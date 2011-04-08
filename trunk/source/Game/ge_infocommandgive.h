#ifndef GE_INFOCOMMANDGIVE_H_INCLUDED
#define GE_INFOCOMMANDGIVE_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandGive :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandGive( void );
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
    bCString              m_strEntity1;
    bCString              m_strEntity2;
    eCTemplateEntityProxy m_Item;
    GEU32                 m_u32Amount;
    eCEntityProxy         m_EntityProxy1;
    eCEntityProxy         m_EntityProxy2;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &                       AccessAmount( void );
    bCString &                    AccessEntity1( void );
    bCString &                    AccessEntity2( void );
    eCTemplateEntityProxy &       AccessItem( void );
    GEU32 const &                 GetAmount( void ) const;
    bCString const &              GetEntity1( void ) const;
    bCString const &              GetEntity2( void ) const;
    eCTemplateEntityProxy const & GetItem( void ) const;
    void                          SetAmount( GEU32 const & );
    void                          SetEntity1( bCString const & );
    void                          SetEntity2( bCString const & );
    void                          SetItem( eCTemplateEntityProxy const & );
public:
    gCInfoCommandGive & operator = ( gCInfoCommandGive const & );
public:
    gCInfoCommandGive( gCInfoCommandGive const & );
    gCInfoCommandGive( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandGive, 0x0028 )

#endif
