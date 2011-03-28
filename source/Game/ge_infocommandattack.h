#ifndef GE_INFOCOMMANDATTACK_H_INCLUDED
#define GE_INFOCOMMANDATTACK_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandAttack :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandAttack( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual gEInfoCommand              GetCommandTypeForScript( void ) const;
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
    bCString      m_strReason;
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
    bCString &       AccessReason( void );
    bCString const & GetEntity1( void ) const;
    bCString const & GetEntity2( void ) const;
    bCString const & GetReason( void ) const;
    void             SetEntity1( bCString const & );
    void             SetEntity2( bCString const & );
    void             SetReason( bCString const & );
public:
    gCInfoCommandAttack & operator = ( gCInfoCommandAttack const & );
public:
    gCInfoCommandAttack( gCInfoCommandAttack const & );
    gCInfoCommandAttack( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandAttack, 0x0024 )

#endif
