#ifndef GE_INFOCOMMANDMOVETO_H_INCLUDED
#define GE_INFOCOMMANDMOVETO_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandMoveTo :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandMoveTo( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy &            GetEntityProxy2( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString      m_strEntity1;
    bCString      m_strEntity2;
    eCEntityProxy m_EntityProxy1;
    eCEntityProxy m_EntityProxy2;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessEntity1( void );
    bCString &       AccessEntity2( void );
    bCString const & GetEntity1( void ) const;
    bCString const & GetEntity2( void ) const;
    void             SetEntity1( bCString const & );
    void             SetEntity2( bCString const & );
public:
    gCInfoCommandMoveTo & operator = ( gCInfoCommandMoveTo const & );
public:
    gCInfoCommandMoveTo( gCInfoCommandMoveTo const & );
    gCInfoCommandMoveTo( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandMoveTo, 0x0020 )

#endif
