#ifndef GE_PROPERTYID_H_INCLUDED
#define GE_PROPERTYID_H_INCLUDED

class bCMd5;  // forward

class GE_DLLIMPORT bCPropertyID
{
public:
    struct bSCore
    {
        union
        {
            GEU8  m_u8Core[ 16 ];
            GEU16 m_u16Core[ 8 ];
            GEU32 m_u32Core[ 4 ];
        };
        GEBool operator == ( bSCore const & a_Core ) const
        {
            for( GEInt i = 3; i >= 0; i-- )
                if( a_Core.m_u32Core[ i ] != this->m_u32Core[ i ] )
                    return GEFalse;
            return GETrue;
        }
    };
private:
    bSCore m_Core;
    GEU32  m_u32Count;
private:
    bSCore & AccessCore( void );
    GEU32 &  AccessCount( void );
    GEBool   Create( void );
    void     Invalidate( void );
    void     SetCore( bSCore const & );
    void     SetCount( GEU32 const & );
protected:
    static void GE_STDCALL DestroyHashList( void );
public:
    void           CopyFrom( bCPropertyID const & );
    void           CopyTo( bCPropertyID & ) const;
    GEBool         CreateFromMd5( bCMd5 const & );
    void           CreateFromString( bCString const & );
    GEBool         CreateRandom( void );
    void           Destroy( void );
    void           ExtractGuid( bCGuid & );
    bSCore const & GetCore( void ) const;
    GEU32 const &  GetCount( void ) const;
    bCString       GetShortText( void ) const;
    bCString       GetText( void ) const;
    bCString       GetTextEx( void ) const;
    GEBool         IsValid( void ) const;
    GEBool         Read( bCIStream & );
    GEBool         SetGuid( bCGuid const & );
    GEBool         SetText( bCString const & );
    GEBool         SetTextEx( bCString const & );
    void           Write( bCOStream & ) const;
public:
    GEBool         operator == ( bCPropertyID const & ) const;
    GEBool         operator != ( bCPropertyID const & ) const;
    bCIStream &    operator << ( bCIStream & );
    bCOStream &    operator >> ( bCOStream & ) const;
    bCPropertyID & operator =  ( bCPropertyID const & );
public:
    bCPropertyID( bCPropertyID const & );
    bCPropertyID( bCGuid const & );
    bCPropertyID( void );
   ~bCPropertyID( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, bCPropertyID & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, bCPropertyID & );
};

template<>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue< bCPropertyID >( bCPropertyID const & );

#endif
