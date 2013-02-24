#ifndef GE_CONTEXTBASE_H_INCLUDED
#define GE_CONTEXTBASE_H_INCLUDED

class GE_DLLIMPORT eCContextBase :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );
public:    virtual                           ~eCContextBase( void );
public:    virtual GEBool                     EnumEntities( GEBool ( GE_STDCALL * )( eCEntity *, GELPVoid ), GELPVoid ) const;
public:    virtual GEBool                     IsDataAvailable( void ) const;
public:    virtual void                       SetGraph( eCNode * );
public:    virtual GEBool                     IsProcessing( void ) const;
public:    virtual GEFloat                    QueryProgress( void ) const;
public:    virtual void                       CollectSaveGameEntities( bTValArray< eCEntity * > & );
public:    virtual bEResult                   WriteSaveGame( eCArchiveFile & );
public:    virtual bEResult                   ReadSaveGame( eCArchiveFile & );
public:    virtual eCNode *                   CreateSpecificEntity( void );
public:    virtual void                       OnUpdateInternals( void );
protected: virtual void                       UpdateBoundingBox( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCContextBase( eCContextBase const & );
    eCContextBase( void );
public:
    eCContextBase & operator = ( eCContextBase const & );
public:
    bCBox &          AccessContextBox( void );
    bCGuid &         AccessID( void );
    void             DisableUpdateInternalsOnWrite( void );
    void             Enable( GEBool );
    bCBox const &    GetContextBox( void ) const;
    bCString const & GetFilePath( void ) const;
    eCNode *         GetGraph( void );
    eCNode const *   GetGraph( void ) const;
    bCGuid const &   GetID( void ) const;
    GEBool           HasGraph( void ) const;
    GEBool           IsEnabled( void ) const;
    GEBool           IsLocked( void ) const;
    GEU16            Lock( void );
    void             SetContextBox( bCBox const & );
    void             SetFilePath( bCString const & );
    void             SetID( bCGuid const & );
    GEU16            Unlock( void );
protected:
    void     CollectNodes( eCNode *, bTValArray< eCNode * > & ) const;
    void     Invalidate( void );
    bEResult ReadDependency( bCIStream &, bTValArray< eCNode * > & );
    bEResult WriteDependency( bCOStream &, bTValArray< eCNode * > const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCGuid   m_ID;
    bCBox    m_boxContextBox;
    GEU16    m_u16LockCount;
             GE_PADDING( 2 )
    eCNode * m_pGraph;
    GEBool   m_bEnabled;
             GE_PADDING1( 3 )
    bCString m_strFilePath;
    GEBool   m_bUpdateInternalsOnWriteDisabled;
             GE_PADDING1( 3 )
};
GE_ASSERT_SIZEOF( eCContextBase, 0x0048 );

#endif