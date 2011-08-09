#ifndef GE_DYNAMICLAYER_H_INCLUDED
#define GE_DYNAMICLAYER_H_INCLUDED

class GE_DLLIMPORT gCDynamicLayer :
    public gCLayerBase
{
public:    virtual bCPropertyObjectTypeBase *     GetObjectType( void ) const;
protected: virtual GEU16                          GetVersion( void ) const;
public:    virtual GEBool                         OnRead( bCIStream & );
public:    virtual GEBool                         OnWrite( bCOStream & );
public:    virtual bEResult                       Create( void );
public:    virtual                               ~gCDynamicLayer( void );
public:    virtual bCString                       GetFileExt( void ) const;
public:    virtual bCString                       GetFileType( void ) const;
public:    virtual bCString                       GetDataFileExt( void ) const;
public:    virtual GEU16                          GetFileVersion( void ) const;
protected: virtual GEBool                         OnReleaseData( void );
public:    virtual GEBool                         Unload( void );
public:    virtual GEBool                         Reload( void );
public:    virtual GEBool                         WriteSaveGame( eCArchiveFile &, bTObjMap< bCString, GEU32 > &, GEI64 ) const;
public:    virtual GEBool                         ReadSaveGame( eCArchiveFile &, bTObjMap< bCString, GEU32 > const &, GEI64 );
protected: virtual bCObjectBase *                 OnCreateContext( void );
public:    using            eCProcessibleElement::Create;
public:    virtual eCProcessibleElement::eEResult Create( gCSector &, bCString const &, gEEntityType );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    static bCString const ms_strDynamicEntityLayer;
    static bCString const ms_strDynamicEntityTempLayer;
protected:
    char __FIXME[ 0x002C - sizeof(gCLayerBase) ];
protected:
    static GEU32 GE_STDCALL GetMagicCode1( void );
    static GEU32 GE_STDCALL GetMagicCode2( void );
protected:
    eCEntityDynamicContext & GetEntityContext( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static void                       GE_STDCALL GetFileExt( bCString & );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEEntityType > &       AccessEntityType( void );
    bCString &                                  AccessOriginImportName( void );
    void                                        CollectSaveGameEntities( bTValArray< eCEntity * > & ) const;
    eCDynamicEntity *                           CreateDynamicEntity( bTObjArray< bCString > const & );
    eCDynamicEntity *                           CreateDynamicEntity( bCString const & );
    eCDynamicEntity *                           CreateDynamicEntity( void );
    eCEntityDynamicContext const &              GetEntityContext( void ) const;
    bTPropertyContainer< gEEntityType > const & GetEntityType( void ) const;
    bCString const &                            GetOriginImportName( void ) const;
    GEBool                                      IsSysLayer( void ) const;
    GEBool                                      IsSysTempLayer( void ) const;
    void                                        SetEntityType( bTPropertyContainer< gEEntityType > const & );
    void                                        SetOriginImportName( bCString const & );
public:
    gCDynamicLayer & operator = ( gCDynamicLayer const & );
public:
    gCDynamicLayer( gCDynamicLayer const & );
    gCDynamicLayer( void );
};
GE_ASSERT_SIZEOF( gCDynamicLayer, 0x002C )

#endif
