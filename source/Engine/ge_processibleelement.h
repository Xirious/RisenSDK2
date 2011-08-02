#ifndef GE_PROCESSIBLEELEMENT_H_INCLUDED
#define GE_PROCESSIBLEELEMENT_H_INCLUDED

class GE_DLLIMPORT eCProcessibleElement : 
    public bCObjectRefBase
{
public:
    enum eEResult
    {
        //FIXME: eCProcessibleElement::eEResult constants.
        eEResult_ForceDWORD = GE_FORCE_DWORD
    };
    enum eEState
    {
        //FIXME: eCProcessibleElement::eEState constants.
        eEState_ForceDWORD = GE_FORCE_DWORD
    };
public:    virtual GEBool                     IsActive( void );
public:    virtual GEBool                     IsDataAvailable( void ) const = 0;
public:    virtual bCString                   GetFileExt( void ) const = 0;
public:    virtual bCString                   GetFileType( void ) const = 0;
public:    virtual bCString                   GetDataFileExt( void ) const = 0;
public:    virtual GEU16                      GetFileVersion( void ) const = 0;
public:    virtual bCString                   GetFileDir( void ) const;
protected: virtual GEBool                     DoAfterLoadData( void );
public:    virtual GEBool                     Save( void );
public:    virtual GEBool                     Load( const bCString & );
public:    virtual GEBool                     Load( eCArchiveFile & );
public:    virtual GEBool                     ReleaseData( void );
protected: virtual eEResult                   CreateFileA( const bCString &, const bCString & );
protected: virtual GEBool                     OnCreateData( void );
protected: virtual GEBool                     OnReleaseData( void ) = 0;
protected: virtual eEResult                   Create( const bCString &, const bCString & );
public:    virtual                           ~eCProcessibleElement( void );
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     IsValid( void ) const;
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
protected:
    GEBool   m_bIsPersistable;
             GE_PADDING( 3 )
    eEState  m_enuState;
    bCString m_strFileBaseName;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             CreateObject( void );
    static bCPropertyObjectTypeBase & GetThisType( void );
    static void                       StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &       AccessIsPersistable( void );
    GEBool         CreateData( void );
    bCString       GetDataFilePath( void ) const;
    bCString       GetFileBaseName( void ) const;
    bCString       GetFileName( void ) const;
    bCString       GetFilePath( void ) const;
    GEBool const & GetIsPersistable( void ) const;
    eEState        GetState( void ) const;
    GEBool         Load( void );
    void           SetFileBaseName( const bCString & );
    void           SetIsPersistable( const GEBool & );
public:
    eCProcessibleElement & operator = ( const eCProcessibleElement & );
public:
    eCProcessibleElement( const eCProcessibleElement & );
    eCProcessibleElement( void );
};
GE_ASSERT_SIZEOF( eCProcessibleElement, 0x0014 )

#endif
