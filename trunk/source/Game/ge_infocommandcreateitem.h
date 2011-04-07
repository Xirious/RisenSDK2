#ifndef GE_INFOCOMMANDCREATEITEM_H_INCLUDED
#define GE_INFOCOMMANDCREATEITEM_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandCreateItem :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandCreateItem( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString              m_strEntity1;
    eCTemplateEntityProxy m_Item;
    GEU32                 m_u32Amount;
    eCEntityProxy         m_EntityProxy1;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &                       AccessAmount( void );
    bCString &                    AccessEntity1( void );
    eCTemplateEntityProxy &       AccessItem( void );
    GEU32 const &                 GetAmount( void ) const;
    bCString const &              GetEntity1( void ) const;
    eCTemplateEntityProxy const & GetItem( void ) const;
    void                          SetAmount( GEU32 const & );
    void                          SetEntity1( bCString const & );
    void                          SetItem( eCTemplateEntityProxy const & );
public:
    gCInfoCommandCreateItem & operator = ( gCInfoCommandCreateItem const & );
public:
    gCInfoCommandCreateItem( gCInfoCommandCreateItem const & );
    gCInfoCommandCreateItem( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandCreateItem, 0x001C )

#endif
