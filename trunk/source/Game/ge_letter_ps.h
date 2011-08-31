#ifndef GE_LETTER_PS_H_INCLUDED
#define GE_LETTER_PS_H_INCLUDED

class GE_DLLIMPORT gCLetter_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCLetter_PS, eCEntityPropertySet )
public: virtual GEU16             GetVersion( void ) const;
public: virtual GEBool            OnRead( bCIStream & );
public: virtual GEBool            OnWrite( bCOStream & );
public: virtual bEResult          Create( void );
public: virtual void              Destroy( void );
public: virtual bEResult          PostInitializeProperties( void );
public: virtual GEBool            HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
public: virtual eEPropertySetType GetPropertySetType( void ) const;
protected:
    GE_DECLARE_PROPERTY( gCLetterLocString, m_locHeader, Header )
    GE_DECLARE_PROPERTY( gCLetterLocString, m_locText,   Text )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCLetter_PS, 0x0028 )

#endif
