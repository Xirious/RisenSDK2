#ifndef GE_BOOK_PS_H_INCLUDED
#define GE_BOOK_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCBookLocString :
    public eCLocString
{
public: virtual bCString GetPrefix( void ) const;
public:
    gCBookLocString & operator = ( gCBookLocString const & );
public:
    gCBookLocString( gCBookLocString const & );
    gCBookLocString( void );
   ~gCBookLocString( void );
};
GE_ASSERT_SIZEOF( gCBookLocString, 0x000C )

#pragma warning( pop )

class GE_DLLIMPORT gCBook_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual GEBool                     HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
public: virtual                           ~gCBook_PS( void );
public: virtual eEPropertySetType          GetPropertySetType( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCBookLocString m_locHeader;
    gCBookLocString m_locLeftText;
    gCBookLocString m_locRightText;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public: 
    gCBookLocString &       AccessHeader( void );
    gCBookLocString &       AccessLeftText( void );
    gCBookLocString &       AccessRightText( void );
    gCBookLocString const & GetHeader( void ) const;
    gCBookLocString const & GetLeftText( void ) const;
    gCBookLocString const & GetRightText( void ) const;
    void                    SetHeader( gCBookLocString const & );
    void                    SetLeftText( gCBookLocString const & );
    void                    SetRightText( gCBookLocString const & );
public:
    gCBook_PS & operator = ( gCBook_PS const & );
public:
    gCBook_PS( gCBook_PS const & );
    gCBook_PS( void );
};
GE_ASSERT_SIZEOF( gCBook_PS, 0x0034 )

#endif
