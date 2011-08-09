#ifndef GE_LAYERBASE_H_INCLUDED
#define GE_LAYERBASE_H_INCLUDED

enum gEEntityType
{
    gEEntityType_Game       = 0x00000000,
    gEEntityType_Temporary  = 0x00000001,
    gEEntityType_ForceDWORD = GE_FORCE_DWORD
};

typedef GEBool (GE_STDCALL * GEFEnumEntitiesCallback)( eCEntity *, GELPVoid );

class GE_DLLIMPORT gCLayerBase :
    public eCProcessibleElement
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     IsValid( void ) const;
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCLayerBase( void );
public:    virtual GEBool                     IsDataAvailable( void ) const;
protected: virtual GEBool                     OnCreateData( void );
public:    virtual GEBool                     EnumEntities( GEFEnumEntitiesCallback, GELPVoid ) const;
public:    virtual bCString                   GetLayerCategory( void ) const;
public:    virtual GEBool                     Unload( void );
public:    virtual GEBool                     Reload( void );
public:    virtual GEBool                     WriteSaveGame( eCArchiveFile &, bTObjMap< bCString, GEU32 > &, GEI64 ) const;
public:    virtual GEBool                     ReadSaveGame( eCArchiveFile &, bTObjMap< bCString, GEU32 > const &, GEI64 );
protected: virtual bCObjectBase *             OnCreateContext( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x0020 - sizeof(eCProcessibleElement) ];
protected:
    void                           Invalidate( void );
    eCProcessibleElement::eEResult SetContext( eCContextBase * );
    void                           SetSector( gCSector const * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                  Enable( GEBool );
    eCContextBase &       GetContext( void );
    eCContextBase const & GetContext( void ) const;
    gCSector &            GetSector( void );
    gCSector const &      GetSector( void ) const;
    GEBool                HasSector( void ) const;
    GEBool                IsEnabled( void ) const;
    GEBool                IsLocked( void ) const;
    GEU16                 Lock( void );
    GEU16                 Unlock( void );
public:
    gCLayerBase & operator = ( gCLayerBase const & );
public:
    gCLayerBase( gCLayerBase const & );
    gCLayerBase( void );
};
GE_ASSERT_SIZEOF( gCLayerBase, 0x0020 )

#endif
