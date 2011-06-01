#ifndef GE_DOCOBJECT_H_INCLUDED
#define GE_DOCOBJECT_H_INCLUDED

class GE_DLLIMPORT eCDocObject :
    public bCObjectRefBase
{
public:    virtual bCString                   GetRawExt( void ) const;              
public:    virtual bCString                   GetRawPath( void ) const;             
public:    virtual bCString                   GetFileKey( void ) const;             
public:    virtual bCString                   GetFileTitleA( void ) const;          
public:    virtual void                       SetFileTitleA( bCString const & );    
public:    virtual void                       PostLoad( void );                     
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          
public:    virtual                           ~eCDocObject( void );                  
private:
    bCString m_strFileTitleA;  // 0008
    // sizeof(eCDocObject)        000C
private:
    static bCPropertyObjectTypeBase thisType;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static eCDocObject *              GE_STDCALL LoadBinary( bCIStream & );
    static eCDocObject *              GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString GetRawFileName( void ) const;
    bCString GetRawFilePath( void ) const;
    GEBool   GetRawFileTime( SFFFileTime & ) const;
    GEBool   ReloadRaw( void );
    GEBool   SaveRaw( void );
    GEBool   SaveRawAs( bCString const &, bCString const & );
    GEBool   SaveRawAsClass( bCString const &, bCString const &, bCString const & );
public:
    eCDocObject & operator = ( eCDocObject const & );
public:
    eCDocObject( eCDocObject const & );
    eCDocObject( void );
};

#endif
