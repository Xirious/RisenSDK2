#include "../SharedBase.h"
#pragma warning( push )
#pragma warning( disable : 4365 )  // conversion from 'unsigned char' to 'char', signed/unsigned mismatch
#pragma warning( disable : 4701 )  // potentially uninitialized local variable 'OpCode' used
#include "../../extern/EliCZ/X86IL.h"
#pragma warning( pop )

namespace Genome {
namespace MessageHooks {

static struct SHook {
    GELPCChar m_pcModule;
    GELPCChar m_pcLogStr;
    GELPCVoid m_funcHook;
    GELPCChar m_pcExport;
    GEBool    m_bEnforce;
    GE_PADDING( 3 )
} const g_arrHooks[ 8 ] = {
    { "SharedBase", "INFO", &GE_MESSAGEF_INFO, "?AllocatePure@bCMemoryAdmin@@IAEPAXQBDH0PBDW4bEMemoryAllocationType@@K@Z", GEFalse },
    { "SharedBase", "WARN", &GE_MESSAGEF_WARN, "?DoClone@bCPropertyTypeBase@@MBEPAV1@XZ", GEFalse },
    { "Engine", "INFO", &GE_MESSAGEF_INFO, "?CalculateHardwareEnvironment@eCApplication@@IAEXXZ", GEFalse },
    { "Engine", "WARN", &GE_MESSAGEF_WARN, "?CreateWorkspace@eCApplication@@MAE?AW4bEResult@@XZ", GEFalse },
    { "Game", "INFO", &GE_MESSAGEF_INFO, "?DumpPageReport@gCHudSystem2@@AAEXXZ", GEFalse },
    { "Game", "WARN", &GE_MESSAGEF_WARN, "?OnCreateContext@gCLayerBase@@MAEPAVbCObjectBase@@XZ", GEFalse },
    { "Game", "OK_EX", &GE_MESSAGEF_OK_EX, "?HasCommentInfo@gCInfoSystem@@QAE_NPAVeCEntity@@@Z", GETrue },
    { "Game", "WARN_EX", &GE_MESSAGEF_WARN_EX, "?OnNPCDefeated@gCQuest@@QAEXABVeCEntity@@@Z", GETrue }
};

GEBool InstallHook( SHook const & a_Hook )
{
    GELPVoid hModule = g_LoadModule( bCString( a_Hook.m_pcModule ) + ".dll" );
    if( hModule )
    {
        GELPCByte pCode = static_cast< GELPCByte >( g_GetProcAddress( hModule, a_Hook.m_pcExport ) );
        if( pCode )
        {
            GEByte pInstruction[ 32 ];
            int iPrefixCount;
            int iModRMOffset;
            int iValueLength;
            int iCount = 0;
            do
            {
                int iLength = X86IL( 0, pCode, pInstruction, &iPrefixCount, &iModRMOffset, &iValueLength );
                if( iLength <= 0 )
                    return GEFalse;
                pCode += iLength;
                iCount += iLength;
                switch( iLength )
                {
                case 1:
                    switch( pInstruction[ 0 ] )
                    {
                    // RET
                    case 0xC3:
                    case 0xCB:
                        return GEFalse;
                    }
                    break;
                case 2:
                    switch( pInstruction[ 0 ] )
                    {
                    // JMP rel8
                    case 0xEB:
                        pCode += static_cast< GEI8 >( pInstruction[ 1 ] );
                        break;
                    }
                    break;
                case 3:
                    switch( pInstruction[ 0 ] )
                    {
                    // RET imm16
                    case 0xC2:
                    case 0xCA:
                        return GEFalse;
                    }
                    break;
                case 5:
                    switch( pInstruction[ 0 ] )
                    {
                    // CALL rel32
                    case 0xE8:
                        {
                            #pragma pack( push, 1 )
                            struct SThunk
                            {
                                GEU8  OpCode;
                                GEI32 Offset;
                            };
                            GE_ASSERT_SIZEOF( SThunk, 0x0005 )
                            #pragma pack( pop )

                            SThunk const * pThunk = reinterpret_cast< SThunk const * >(
                                pCode + *reinterpret_cast< GEI32 * >( &pInstruction[ 1 ] ) );
                            if( 0xE9 == pThunk->OpCode )
                            {
                                // ADD ESP (+)imm8
                                if( (3 == X86IL( 0, pCode, pInstruction, &iPrefixCount, &iModRMOffset, &iValueLength )) &&
                                    (0x83 == pInstruction[ 0 ]) &&
                                    (0xC4 == pInstruction[ 1 ]) &&
                                    (static_cast< GEI8 >( pInstruction[ 2 ] ) > 0) )
                                {
                                    MEMORY_BASIC_INFORMATION MemInfo;
                                    GELPCByte pFunction = reinterpret_cast< GELPCByte >( pThunk + 1 ) + pThunk->Offset;
                                    if( ::VirtualQuery( static_cast< LPCVOID >( pFunction ), &MemInfo, sizeof(MEMORY_BASIC_INFORMATION) ) &&
                                        (MemInfo.AllocationBase == hModule) &&
                                        (a_Hook.m_bEnforce || (0xC3 == *pFunction)) )
                                    {
                                        DWORD dwProtect = 0;
                                        if( ::VirtualProtect(
                                                static_cast< LPVOID >( const_cast< SThunk * >( pThunk ) ),
                                                sizeof(SThunk), PAGE_EXECUTE_WRITECOPY, &dwProtect ) )
                                        {
                                            const_cast< SThunk * >( pThunk )->Offset =
                                                static_cast< GELPCByte >( a_Hook.m_funcHook ) -
                                                reinterpret_cast< GELPCByte >( pThunk + 1 );
                                            return GETrue;
                                        }
                                    }
                                    return GEFalse;
                                }
                            }
                        }
                        break;
                    // JMP rel32
                    case 0xE9:
                        pCode += *reinterpret_cast< GEI32 * >( &pInstruction[ 1 ] );
                        break;
                    }
                    break;
                }
            }
            while( iCount < 0x0100 );
        }
    }
    return GEFalse;
}

void InstallHooks( void )
{
    {
        //NOTE: Avoid C Run-Time Error "R6002 - floating point support not loaded".
        // The compiler might not load the floating-point routines to minimizes the
        // program's size if your application does not use floating-point arguments
        // or assignments. But if our hooks capture a format string that includes a
        // floating-point field (aAeEfgG) the CRT would show a R6002 error message.
        if( (g_f2PI - g_fPI * 2) > g_fEpsilon )
            GE_SILENTLOG_OUT( "Perimeter meditation." );
        //NOTE: Support for count fields (n) is not enabled here (by intention :-).
        // You can use _set_printf_count_output to enable support for count fields.
    }
    for( int iHook = 0; iHook < sizeof(g_arrHooks) / sizeof(g_arrHooks[ 0 ]); ++iHook )
        if( GEFalse == InstallHook( g_arrHooks[ iHook ] ) )
            GE_SILENTLOG_OUT(
                "%s.GE_MESSAGEF_%s not found/hooked.",
                g_arrHooks[ iHook ].m_pcModule,
                g_arrHooks[ iHook ].m_pcLogStr );
}

class CAutoHook
{
protected:
    GELPVoid m_hMutex;
public:
    CAutoHook( void ) : m_hMutex( 0 )
    {
        bCString strMutex = bCString::GetFormattedString(
            "Genome_MessageHooks_%d",
            g_GetCurrentProcessId() );
        m_hMutex = g_CreateMutex( strMutex );
        if( m_hMutex )
            InstallHooks();
    }
    ~CAutoHook( void )
    {
        if( m_hMutex )
        {
            GELPVoid hMutex = m_hMutex;
            m_hMutex = 0;
            g_CloseMutex( hMutex );
        }
    }
}
AutoHook;

}}
