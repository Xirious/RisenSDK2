#ifndef GE_ENTITYDYNAMICCONTEXT_H_INCLUDED
#define GE_ENTITYDYNAMICCONTEXT_H_INCLUDED

class GE_DLLIMPORT eCEntityDynamicContext :
    public eCContextBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual                           ~eCEntityDynamicContext( void );
public: virtual void                       SetGraph( eCNode * );
public: virtual void                       CollectSaveGameEntities( bTValArray< eCEntity * > & );
public: virtual bEResult                   WriteSaveGame( eCArchiveFile & );
public: virtual bEResult                   ReadSaveGame( eCArchiveFile & );
public: virtual eCDynamicEntity *          CreateSpecificEntity( void );
public: virtual GEBool                     WriteSaveGame( eCArchiveFile &, GEU32 &, eCNode *, eCDynamicEntity * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCEntityDynamicContext( eCEntityDynamicContext const & );
    eCEntityDynamicContext( void );
public:
    eCEntityDynamicContext & operator = ( eCEntityDynamicContext const & );
public:
    void Invalidate( void );
protected:
    void CollectSaveGameEntities( bTValArray< eCEntity * > &, eCNode * );
private:
    static bCPropertyObjectTypeBase thisType;
};
GE_ASSERT_SIZEOF( eCEntityDynamicContext, 0x0048 );

#endif
