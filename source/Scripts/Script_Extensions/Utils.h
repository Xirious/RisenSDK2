#ifndef SCRIPT_MOD_EXTENSIONS_UTILS_H_INCLUDED
#define SCRIPT_MOD_EXTENSIONS_UTILS_H_INCLUDED

#include "Hacks.h"

#include <stdio.h>
#pragma comment ( lib, "user32.lib" )

void              DbgOut( GELPCChar a_strFormat, ... );
bCString          GetRisenPath( void );
GEBool            ToFile( bCMemoryStream & a_MemStream, GELPCChar a_strFileName );
GEBool            IsEntityEnabled( const eCEntity * a_pEntity );
bCUnicodeString   GetClipboardText( void );
void              SetClipboardText( bCUnicodeString a_strText );
eCDynamicEntity * GetDynamicEntity( bCUnicodeString a_strGuid, bCUnicodeString & Result );
gCDynamicLayer *  GetLayer( bCString a_strName );
gCDynamicLayer *  GetLayer( eCDynamicEntity * a_pEntity );
GEBool            GetVectorFromText( bCVector & a_vecTarget, bCString a_strText );
bCUnicodeString   ParamAutoCompletion( const bCUnicodeString * a_strResultToRegister = 0 );
GEBool            IsPhysical( bCString const & a_strFilePath );
bCString          GetPhysicalFilePath( bCString const & a_strFilePath );

bCString          GetAddrString( const void * a_pAddr );

#endif  // SCRIPT_MOD_EXTENSIONS_UTILS_H_INCLUDED