#include "Script.h"

////////////////////////////////////////////////////////////////////////////////
//
//  Script functions
//
////////////////////////////////////////////////////////////////////////////////

GEInt GE_STDCALL CON_library( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    UNREFERENCED_PARAMETER( a_pSPU );
    UNREFERENCED_PARAMETER( a_pSelfEntity );
    UNREFERENCED_PARAMETER( a_pOtherEntity );
    struct SArgs {
        enum EReason {
            EReason_Help,
            EReason_AutoComplete,
            EReason_Execute
        }                             m_enuReason;
        bTObjArray< bCUnicodeString > m_arrParams;
        bCUnicodeString               m_strResult;
    } & Args = *reinterpret_cast< SArgs * >( a_iArgs );

    enum ECommand
    {
        ECommand_Compile,
        ECommand_Export,
        ECommand_Count
    };
    GELPCUnicodeChar const arrCommandNames[ ECommand_Count ] = {
        L"compile",
        L"export"
    };
    enum ELibrary
    {
        ELibrary_Audio,
        ELibrary_Camera,
        ELibrary_CombatSpecies,
        ELibrary_Cursors,
        ELibrary_Effects,
        ELibrary_Focus,
        ELibrary_Fonts,
        ELibrary_ImageEffects,
        ELibrary_ImageLists,
        ELibrary_Infos,
        ELibrary_Music,
        ELibrary_Quests,
        ELibrary_Tutorials,
        ELibrary_Windows,
        ELibrary_Count
    };
    GELPCUnicodeChar const arrLibraryNames[ ELibrary_Count ] = {
        L"audio",
        L"camera",
        L"combatspecies",
        L"cursors",
        L"effects",
        L"focus",
        L"fonts",
        L"imageeffects",
        L"imagelists",
        L"infos",
        L"music",
        L"quests",
        L"tutorials",
        L"windows"
    };

    switch( Args.m_enuReason )
    {
    case SArgs::EReason_Help:
        {
            Args.m_strResult =
                L"Compile or export document archives (data/compiled/library/compiled_*.bin)\n" \
                L"Usage:\n" \
                L"  library <Command> <Library>\n" \
                L"Commands:\n";
            for( ECommand enuCommand = static_cast< ECommand >( 0 ); enuCommand < ECommand_Count; ++*reinterpret_cast< int * >( &enuCommand ) )
                Args.m_strResult += L"  " + bCUnicodeString( arrCommandNames[ enuCommand ] ) + L"\n";
            Args.m_strResult += L"Libraries:\n";
            for( ELibrary enuLibrary = static_cast< ELibrary >( 0 ); enuLibrary < ELibrary_Count; ++*reinterpret_cast< int * >( &enuLibrary ) )
                Args.m_strResult += L"  " + bCUnicodeString( arrLibraryNames[ enuLibrary ] ) + L"\n";
            return 1;
        }
    case SArgs::EReason_AutoComplete:
        {
            switch( Args.m_arrParams.GetCount() )
            {
            case 1:
                {
                    bCUnicodeString & strCommand = Args.m_arrParams.AccessAt( 0 );
                    for( ECommand enuCommand = static_cast< ECommand >( 0 ); enuCommand < ECommand_Count; ++*reinterpret_cast< int * >( &enuCommand ) )
                        if( strCommand.CompareNoCase( arrCommandNames[ enuCommand ] ) < 0 )
                        {
                            strCommand = arrCommandNames[ enuCommand ];
                            return 1;
                        }
                    strCommand = arrCommandNames[ static_cast< ECommand >( 0 ) ];
                    return 1;
                }
            case 2:
                {
                    bCUnicodeString & strLibrary = Args.m_arrParams.AccessAt( 1 );
                    for( ELibrary enuLibrary = static_cast< ELibrary >( 0 ); enuLibrary < ELibrary_Count; ++*reinterpret_cast< int * >( &enuLibrary ) )
                        if( strLibrary.CompareNoCase( arrLibraryNames[ enuLibrary ] ) < 0 )
                        {
                            strLibrary = arrLibraryNames[ enuLibrary ];
                            return 1;
                        }
                    strLibrary = arrLibraryNames[ static_cast< ELibrary >( 0 ) ];
                    return 1;
                }
            default:
                return 0;
            }
        }
    case SArgs::EReason_Execute:
        {
            switch( Args.m_arrParams.GetCount() )
            {
            case 0:
                {
                    Args.m_strResult = L"Please specify a command.";
                    return 0;
                }
            case 1:
                {
                    Args.m_strResult = L"Please specify a library.";
                    return 0;
                }
            case 2:
                {
                    bCUnicodeString & strCommand = Args.m_arrParams.AccessAt( 0 );
                    for( ECommand enuCommand = static_cast< ECommand >( 0 ); enuCommand < ECommand_Count; ++*reinterpret_cast< int * >( &enuCommand ) )
                        if( 0 == strCommand.CompareNoCase( arrCommandNames[ enuCommand ] ) )
                        {
                            bCUnicodeString & strLibrary = Args.m_arrParams.AccessAt( 1 );
                            for( ELibrary enuLibrary = static_cast< ELibrary >( 0 ); enuLibrary < ELibrary_Count; ++*reinterpret_cast< int * >( &enuLibrary ) )
                                if( 0 == strLibrary.CompareNoCase( arrLibraryNames[ enuLibrary ] ) )
                                {
                                    eSDocArchiveConfig Config(
                                        "#G3:/data/compiled/library/",
                                        "compiled_",
                                        ".bin",
                                        "#G3:/data/raw/"
                                    );
                                    Config.m_strBinaryName += bCString( arrLibraryNames[ enuLibrary ] );
                                    switch( enuLibrary )
                                    {
                                    case ELibrary_Audio:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xaudrev" );
                                        Config.m_arrRawExts.Add( ".xaudroll" );
                                        break;
                                    case ELibrary_Camera:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xcat" );
                                        Config.m_arrRawExts.Add( ".xcae" );
                                        break;
                                    case ELibrary_CombatSpecies:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xcs" );
                                        break;
                                    case ELibrary_Cursors:
                                        Config.m_strRawPath += "gui2/";
                                        Config.m_arrRawExts.Add( ".xcur" );
                                        break;
                                    case ELibrary_Effects:
                                        Config.m_arrRawExts.Add( ".xeff" );
                                        break;
                                    case ELibrary_Focus:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xfoccol" );
                                        Config.m_arrRawExts.Add( ".xfocind" );
                                        Config.m_arrRawExts.Add( ".xfocmod" );
                                        break;
                                    case ELibrary_Fonts:
                                        Config.m_strRawPath += "gui2/";
                                        Config.m_arrRawExts.Add( ".xfnt" );
                                        break;
                                    case ELibrary_ImageEffects:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xieff" );
                                        break;
                                    case ELibrary_ImageLists:
                                        Config.m_strRawPath += "gui2/";
                                        Config.m_arrRawExts.Add( ".ximc" );
                                        break;
                                    case ELibrary_Infos:
                                        Config.m_arrRawExts.Add( ".xinf" );
                                        break;
                                    case ELibrary_Music:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xmloc" );
                                        Config.m_arrRawExts.Add( ".xmtra" );
                                        break;
                                    case ELibrary_Quests:
                                        Config.m_arrRawExts.Add( ".xqst" );
                                        break;
                                    case ELibrary_Tutorials:
                                        Config.m_strRawPath += "library/";
                                        Config.m_arrRawExts.Add( ".xcs" );
                                        break;
                                    case ELibrary_Windows:
                                        Config.m_strRawPath += "gui2/";
                                        Config.m_arrRawExts.Add( ".xwnd" );
                                        break;
                                    case ELibrary_Count:
                                        break;
                                    }
                                    if( ELibrary_Tutorials == enuLibrary )
                                        Config.m_strRawPath += "tutorial/";
                                    else
                                        Config.m_strRawPath += bCString( arrLibraryNames[ enuLibrary ] ) + "/";
                                    // Create output directory.
                                    {
                                        eCVirtualFileSystem & VirtualFileSystem = eCVirtualFileSystem::GetInstance();
                                        bCString strFilePath = VirtualFileSystem.GetPhysicalRootPath();
                                        if( ECommand_Compile == enuCommand )
                                            strFilePath += Config.m_strBinaryPath.Right( Config.m_strBinaryPath.GetLength() - 5 );
                                        else
                                            strFilePath += Config.m_strRawPath.Right( Config.m_strRawPath.GetLength() - 5 );
                                        g_FFPathMakeWindowsFile( strFilePath );
                                        if( !g_FFIsDirectory( strFilePath ) )
                                        {
                                            g_FFPathMakeWindowsDir( strFilePath );
                                            g_FFCreateDirectoryChain( strFilePath );
                                        }
                                    }
                                    GEBool bResult = GEFalse;
                                    {
                                        eCDocArchive Archive;
                                        Archive.Create( Config );
                                        switch( enuCommand )
                                        {
                                        case ECommand_Compile:
                                            {
                                                if( bResult = Archive.ImportRaw(), !bResult )
                                                    Args.m_strResult = L"ImportRaw failed.";
                                                else if( bResult = !Archive.GetDocuments().IsEmpty(), !bResult )
                                                    Args.m_strResult = L"No raw files found.";
                                                else if( bResult = Archive.WriteBinary(), !bResult )
                                                    Args.m_strResult = L"WriteBinary failed.";
                                            }
                                        case ECommand_Export:
                                            {
                                                if( bResult = Archive.ReadBinary(), !bResult )
                                                    Args.m_strResult = L"ReadBinary failed.";
                                                else if( bResult = !Archive.GetDocuments().IsEmpty(), !bResult )
                                                    Args.m_strResult = L"Archive is empty.";
                                                else if( bResult = Archive.ExportRaw(), !bResult )
                                                    Args.m_strResult = L"ExportRaw failed.";
                                                else
                                                {
                                                    bTRefPropertyArray< eCDocObject * > const & arrDocuments = Archive.GetDocuments();
                                                    // Set file time-stamps by manually parsing the binary archive.
                                                    {
                                                        eCArchiveFile ArchiveFile = eCArchiveManager::GetInstance().GetFile( Config.m_strBinaryPath + Config.m_strBinaryName + Config.m_strBinaryExt );
                                                        if( ArchiveFile.Open( eCArchiveFile::bEArchiveFileAccessMode_Read, GETrue ) )
                                                        {
                                                            GEU32 u32Token = 0;
                                                            GEU8 u8Version = 0;
                                                            GEU32 u32Count = 0;
                                                            ArchiveFile >> u32Token;
                                                            ArchiveFile >> u8Version;
                                                            ArchiveFile >> u32Count;
                                                            if( (0x31303056 == u32Token) && (0x01 == u8Version) && (arrDocuments.GetCount() == static_cast< GEInt >( u32Count )) )
                                                            {
                                                                //NOTE: We silently assume that the document order is the same as in the binary archive.
                                                                for( bTRefPropertyArray< eCDocObject * >::bCConstIterator pDocument = arrDocuments.Begin(); pDocument != arrDocuments.End(); ++pDocument )
                                                                {
                                                                    SFFFileTime FileTime;
                                                                    bCString strFileName;
                                                                    ArchiveFile >> FileTime.m_FileTime.dwHighDateTime;
                                                                    ArchiveFile >> FileTime.m_FileTime.dwLowDateTime;
                                                                    ArchiveFile >> strFileName;
                                                                    {
                                                                        bCString strRawFilePath = (*pDocument)->GetRawFilePath();
                                                                        if( eCVirtualFileSystem::GetInstance().MakeAbsPhysicalPath( strRawFilePath ) && !strRawFilePath.IsEmpty() )
                                                                        {
                                                                            FFLPVoid hFile = g_FFCreateFile( strRawFilePath, EFFFileCreate_OpenExisting, EFFFileAccess_Write, 0, 0, 0 );
                                                                            if( g_FFIsValidFileHandle( hFile ) )
                                                                            {
                                                                                g_FFSetFileTime( hFile, &FileTime, &FileTime, &FileTime );
                                                                                g_FFCloseFile( hFile );
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    // Move camera source files to the import directory.
                                                    if( ELibrary_Camera == enuLibrary )
                                                    {
                                                        bCString strRawPath = Archive.GetDocuments().GetAt( 0 )->GetRawPath();
                                                        if( Config.m_strRawPath.CompareNoCase( strRawPath ) )
                                                        {
                                                            eCVirtualFileSystem & VirtualFileSystem = eCVirtualFileSystem::GetInstance();
                                                            for( bTRefPropertyArray< eCDocObject * >::bCConstIterator pDocument = arrDocuments.Begin(); pDocument != arrDocuments.End(); ++pDocument )
                                                            {
                                                                bCString strExistingFileName = (*pDocument)->GetRawFilePath();
                                                                if( VirtualFileSystem.MakeAbsPhysicalPath( strExistingFileName ) && !strExistingFileName.IsEmpty() )
                                                                {
                                                                    bCString strNewFileName = Config.m_strRawPath;
                                                                    if( VirtualFileSystem.MakeAbsPhysicalPath( strNewFileName ) && !strNewFileName.IsEmpty() )
                                                                    {
                                                                        strNewFileName += (*pDocument)->GetRawFileName();
                                                                        g_FFMoveFile( strExistingFileName, strNewFileName, FFTrue );
                                                                    }
                                                                }
                                                            }
                                                            if( VirtualFileSystem.MakeAbsPhysicalPath( strRawPath ) && !strRawPath.IsEmpty() )
                                                                g_FFRemoveDirectory( strRawPath );
                                                        }
                                                    }
                                                }
                                            }
                                        case ECommand_Count:
                                            break;
                                        }
                                        Archive.Destroy();
                                    }
                                    return bResult ? 1 : 0;
                                }
                            Args.m_strResult = L"Invalid library specified.";
                            return 0;
                        }
                    Args.m_strResult = L"Invalid command specified.";
                    return 0;
                }
            default:
                {
                    Args.m_strResult = L"Too many arguments.";
                    return 0;
                }
            }
        }
    default:
        {
            Args.m_strResult = L"Unknown command action.";
            return 0;
        }
    }
}

//
// Script Init
//

extern "C" __declspec( dllexport )  // "_ScriptInit@0"
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )  // construction of local static object is not thread-safe

    static gSScriptInit s_ScriptInit;

#pragma warning( pop )

    s_ScriptInit.m_arrScriptAIStates.Clear();
    s_ScriptInit.m_arrScriptAIFunctions.Clear();
    s_ScriptInit.m_arrScriptAICallbacks.Clear();
    s_ScriptInit.m_arrScripts.Clear();
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_library", __FILE__, CON_library ) );

    return &s_ScriptInit;
}

//
// Entry Point
//

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved )
{
    UNREFERENCED_PARAMETER( lpReserved );
    switch( dwReason )
	{
	case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
