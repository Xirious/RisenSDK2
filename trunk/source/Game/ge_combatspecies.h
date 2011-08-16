#ifndef GE_COMBATSPECIES_H_INCLUDED
#define GE_COMBATSPECIES_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<T>' needs to have dll-interface to be used by clients of class 'gCCombatSpecies'

class GE_DLLIMPORT gCCombatSpecies :
    public eCDocObject
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     OnDeserialize( bCXMLParserNode * );
public:    virtual GEBool                     OnSerialize( bCXMLParserNode * );
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual GEInt                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr     GetNativePropertyAt( GEInt ) const;
public:    virtual                           ~gCCombatSpecies( void );
public:    virtual bCString                   GetRawExt( void ) const;
public:    virtual bCString                   GetRawPath( void ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat                       m_fHitSufferRadius;
    GEFloat                       m_fMeleeDistanceRadius;
    GEBool                        m_bCanStrafe;
                                  GE_PADDING( 3 )
    eCTemplateEntityProxy         m_LeftFistItem;
    eCTemplateEntityProxy         m_RightFistItem;
    bCString                      m_strStumble;
    bCString                      m_strStumbleLight;
    bCString                      m_strStumbleHeavy;
    bCString                      m_strStumbleOverlay;
    bCString                      m_strStumbleOverlayLight;
    bCString                      m_strStumbleOverlayHeavy;
    bCString                      m_strStumbleBack;
    bCString                      m_strStumbleDown;
    bCString                      m_strStumbleDownBack;
    bCString                      m_strStumbleDead;
    bCString                      m_strStumbleDeadBack;
    bCString                      m_strJumpBack;
    bCString                      m_strStrafeLeft;
    bCString                      m_strStrafeRight;
    bTPtrArray< gCCombatStyle * > m_arrStyles;
    bTPtrArray< gCCombatMove * >  m_arrMoves;
    bTPtrArray< gCCombatAI * >    m_arrFightAIs;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL GetClassRawExt( void );
    static bCString                   GE_STDCALL GetClassRawPath( void );
    static bCString const &           GE_STDCALL GetRawFileExtension( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static gCCombatSpecies *          GE_STDCALL LoadBinary( bCIStream & );
    static gCCombatSpecies *          GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                      AccessCanStrafe( void );
    GEFloat &                     AccessHitSufferRadius( void );
    bCString &                    AccessJumpBack( void );
    eCTemplateEntityProxy &       AccessLeftFistItem( void );
    GEFloat &                     AccessMeleeDistanceRadius( void );
    eCTemplateEntityProxy &       AccessRightFistItem( void );
    bCString &                    AccessStrafeLeft( void );
    bCString &                    AccessStrafeRight( void );
    bCString &                    AccessStumble( void );
    bCString &                    AccessStumbleBack( void );
    bCString &                    AccessStumbleDead( void );
    bCString &                    AccessStumbleDeadBack( void );
    bCString &                    AccessStumbleDown( void );
    bCString &                    AccessStumbleDownBack( void );
    bCString &                    AccessStumbleHeavy( void );
    bCString &                    AccessStumbleLight( void );
    bCString &                    AccessStumbleOverlay( void );
    bCString &                    AccessStumbleOverlayHeavy( void );
    bCString &                    AccessStumbleOverlayLight( void );
    void                          AddFightAI( gCCombatAI * );
    void                          AddMove( gCCombatMove * );
    void                          AddStyle( gCCombatStyle * );
    GEBool const &                GetCanStrafe( void ) const;
    gCCombatAI *                  GetFightAI( bCString const & ) const;
    gCCombatAI *                  GetFightAIAt( GEInt ) const;
    GEInt                         GetFightAICount( void ) const;
    GEInt                         GetFightAIIndex( bCString const & ) const;
    GEInt                         GetFightAIIndex( gCCombatAI * ) const;
    GEFloat const &               GetHitSufferRadius( void ) const;
    bCString const &              GetJumpBack( void ) const;
    eCTemplateEntityProxy const & GetLeftFistItem( void ) const;
    GEFloat const &               GetMeleeDistanceRadius( void ) const;
    gCCombatMove *                GetMove( bCString const & ) const;
    gCCombatMove *                GetMove( gECombatMove ) const;
    gCCombatMove *                GetMoveAt( GEInt ) const;
    GEInt                         GetMoveCount( void ) const;
    GEInt                         GetMoveIndex( bCString const & ) const;
    GEInt                         GetMoveIndex( gCCombatMove * ) const;
    bCString const                GetName( void ) const;
    eCTemplateEntityProxy const & GetRightFistItem( void ) const;
    bCString const &              GetStrafeLeft( void ) const;
    bCString const &              GetStrafeRight( void ) const;
    bCString const &              GetStumble( void ) const;
    bCString const &              GetStumbleBack( void ) const;
    bCString const &              GetStumbleDead( void ) const;
    bCString const &              GetStumbleDeadBack( void ) const;
    bCString const &              GetStumbleDown( void ) const;
    bCString const &              GetStumbleDownBack( void ) const;
    bCString const &              GetStumbleHeavy( void ) const;
    bCString const &              GetStumbleLight( void ) const;
    bCString const &              GetStumbleOverlay( void ) const;
    bCString const &              GetStumbleOverlayHeavy( void ) const;
    bCString const &              GetStumbleOverlayLight( void ) const;
    gCCombatStyle *               GetStyle( bCString const & ) const;
    gCCombatStyle *               GetStyleAt( GEInt ) const;
    GEInt                         GetStyleCount( void ) const;
    GEInt                         GetStyleIndex( bCString const & ) const;
    GEInt                         GetStyleIndex( gCCombatStyle * ) const;
    void                          RemoveFightAI( gCCombatAI * );
    void                          RemoveMove( gCCombatMove * );
    void                          RemoveStyle( gCCombatStyle * );
    void                          SetCanStrafe( GEBool const & );
    void                          SetHitSufferRadius( GEFloat const & );
    void                          SetJumpBack( bCString const & );
    void                          SetLeftFistItem( eCTemplateEntityProxy const & );
    void                          SetMeleeDistanceRadius( GEFloat const & );
    void                          SetRightFistItem( eCTemplateEntityProxy const & );
    void                          SetStrafeLeft( bCString const & );
    void                          SetStrafeRight( bCString const & );
    void                          SetStumble( bCString const & );
    void                          SetStumbleBack( bCString const & );
    void                          SetStumbleDead( bCString const & );
    void                          SetStumbleDeadBack( bCString const & );
    void                          SetStumbleDown( bCString const & );
    void                          SetStumbleDownBack( bCString const & );
    void                          SetStumbleHeavy( bCString const & );
    void                          SetStumbleLight( bCString const & );
    void                          SetStumbleOverlay( bCString const & );
    void                          SetStumbleOverlayHeavy( bCString const & );
    void                          SetStumbleOverlayLight( bCString const & );
public:
    gCCombatSpecies & operator = ( gCCombatSpecies const & );
public:
    gCCombatSpecies( gCCombatSpecies const & );
    gCCombatSpecies( void );
};
GE_ASSERT_SIZEOF( gCCombatSpecies, 0x007C )

#pragma warning( pop )

#endif
