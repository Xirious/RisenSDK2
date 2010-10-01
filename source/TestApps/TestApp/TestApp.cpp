#include "Engine.h"
#include <assert.h>
#include <windows.h>
#include <commctrl.h>
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df'\"" )

#ifdef _OPENMP
#ifdef _OPENMP_NOFORCE_MANIFEST
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='8.0.50727.762' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#else
#error Please verify that the OpenMP version matches Risen’s Engine.dll
#endif
#else
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='8.0.50727.762' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#endif

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
    INITCOMMONCONTROLSEX IccEx;
    IccEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
    IccEx.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx( &IccEx );

    // Set working directory to application path.
    {
        DWORD Size;
        TCHAR FileName[ MAX_PATH ];
        if( Size = GetModuleFileName( NULL, FileName, ARRAYSIZE(FileName) ), (Size > 0) && (Size < ARRAYSIZE(FileName)) )
        {
            TCHAR Path[ MAX_PATH ];
            LPTSTR FilePart;
            if( Size = SearchPath( NULL, FileName, NULL, ARRAYSIZE(Path), Path, &FilePart ), (Size > 0) && (Size < ARRAYSIZE(Path)) )
            {
                *FilePart = TEXT('\0');
                SetCurrentDirectory( Path );
            }
        }
    }

    g_LoadModule( "Game.dll" );
    g_LoadModule( "Importer.dll" );

    bCString strMessage;
    for( bCPropertyObjectTypeBase * pObjectType = bCPropertyObjectTypeBase::GetListHead(); pObjectType; pObjectType = pObjectType->GetListNext() )
    {
        for( bTPtrArray< bCPropertyTypeBase * >::bCConstIterator ppPropertyType = pObjectType->BeginIterator(); ppPropertyType != pObjectType->EndIterator(); ++ppPropertyType )
        {
            bCPropertyTypeBase * pPropertyType = *ppPropertyType;
            GEInt iEnumValuesCount = pPropertyType->GetEnumValuesCount();
            if( iEnumValuesCount > 0 )
            {
                strMessage += bCString::GetFormattedString( "%s { ", pPropertyType->GetValueTypeName().GetText() );
                for( GEInt iEnumValue = 0; iEnumValue < iEnumValuesCount; ++iEnumValue )
                {
                    bSEnumValue const & EnumValue = pPropertyType->GetEnumValue( iEnumValue );
                    if( iEnumValue )
                        strMessage += ", ";
                    strMessage += bCString::GetFormattedString( "%s = 0x%8.8X", EnumValue.m_strValue.GetText(), EnumValue.m_u32Value );
                }
                strMessage += bCString::GetFormattedString( " };  // %s.%s\n", pPropertyType->GetClassName().GetText(), pPropertyType->GetPropertyName().GetText() );
            }
        }
    }
    g_MessageBox( 0, strMessage, "EnumValues", 0 );

    return 0;
}

