#include "../SharedBase.h"
#pragma warning( push )
#pragma warning( disable : 4365 )  // conversion from 'unsigned char' to 'char', signed/unsigned mismatch
#pragma warning( disable : 4701 )  // potentially uninitialized local variable 'OpCode' used
#include "../../extern/EliCZ/X86IL.h"
#pragma warning( pop )

namespace Genome {
namespace MessageHooks {

GEBool HookThunk( GELPCChar a_pcModule, GELPCVoid a_pHook, GELPCChar a_pcReference, GEBool a_bForce = GEFalse )
{
    GELPVoid hModule = g_LoadModule( a_pcModule );
    if( hModule )
    {
        GELPCByte pCode = static_cast< GELPCByte >( g_GetProcAddress( hModule, a_pcReference ) );
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
                                        (a_bForce || (0xC3 == *pFunction)) )
                                    {
                                        DWORD dwProtect = 0;
                                        if( ::VirtualProtect(
                                                static_cast< LPVOID >( const_cast< SThunk * >( pThunk ) ),
                                                sizeof(SThunk), PAGE_EXECUTE_WRITECOPY, &dwProtect ) )
                                        {
                                            const_cast< SThunk * >( pThunk )->Offset =
                                                static_cast< GELPCByte >( a_pHook ) -
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
    HookThunk( "SharedBase.dll", &GE_MESSAGEF_INFO, "?AllocatePure@bCMemoryAdmin@@IAEPAXQBDH0PBDW4bEMemoryAllocationType@@K@Z" );
    HookThunk( "SharedBase.dll", &GE_MESSAGEF_WARN, "?DoClone@bCPropertyTypeBase@@MBEPAV1@XZ" );
    HookThunk( "Engine.dll", &GE_MESSAGEF_INFO, "?CalculateHardwareEnvironment@eCApplication@@IAEXXZ" );
    HookThunk( "Engine.dll", &GE_MESSAGEF_WARN, "?CreateWorkspace@eCApplication@@MAE?AW4bEResult@@XZ" );
    HookThunk( "Game.dll", &GE_MESSAGEF_INFO, "?DumpPageReport@gCHudSystem2@@AAEXXZ" );
    HookThunk( "Game.dll", &GE_MESSAGEF_WARN, "?OnCreateContext@gCLayerBase@@MAEPAVbCObjectBase@@XZ" );
    HookThunk( "Game.dll", &GE_MESSAGEF_OK_EX, "?HasCommentInfo@gCInfoSystem@@QAE_NPAVeCEntity@@@Z", GETrue );
    HookThunk( "Game.dll", &GE_MESSAGEF_WARN_EX, "?OnNPCDefeated@gCQuest@@QAEXABVeCEntity@@@Z", GETrue );
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
