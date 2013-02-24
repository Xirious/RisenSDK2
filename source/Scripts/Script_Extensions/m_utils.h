#ifndef SCRIPT_EXTENSIONS_M_UTILS_H_INCLUDED
#define SCRIPT_EXTENSIONS_M_UTILS_H_INCLUDED

#include "Script.h"

void              DbgOut( GELPCChar a_strFormat, ... );
void              DestroyEntity( eCEntity * a_pEntity );
GEBool            FromFile( bCMemoryStream & a_streamDest, GELPCChar a_strFileName );
bCUnicodeString   GetClipboardText( void );
eCDynamicEntity * GetDynamicEntity( bCUnicodeString a_strGuid, bCUnicodeString & a_strResult );
gCDynamicLayer *  GetLayer( bCString a_strName );
gCDynamicLayer *  GetLayer( eCDynamicEntity * a_pEntity );
bCString          GetPhysicalFilePath( bCString const & a_strFilePath );
bCString          GetRisenAppdataPath( void );
bCString          GetRisenPath( void );
GEBool            GetVectorFromText( bCVector & a_vecTarget, bCString const & a_strText );
GEBool            IsEntityEnabled( const eCEntity * a_pEntity );
GEBool            IsPhysical( bCString const & a_strFilePath );
void              SetClipboardText( bCUnicodeString a_strText );
GEBool            SetEntityLayer( eCDynamicEntity * a_pEntity, gCDynamicLayer * a_pLayer );
GEBool            ToFile( bCMemoryStream & a_streamSource, GELPCChar a_strFileName );

template< typename T >
void g_swap( T & a_First, T & a_Second )
{
    GEByte arrBuffer[ sizeof( T ) ];
    g_MemCpy( arrBuffer, &a_First, sizeof( T ) );
    g_MemCpy( &a_First, &a_Second, sizeof( T ) );
    g_MemCpy( &a_Second, arrBuffer, sizeof( T ) );
}

#endif