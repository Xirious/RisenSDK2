#ifndef GE_DIALOG_PS_H_INCLUDED
#define GE_DIALOG_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCDialog_PS'

class GE_DLLIMPORT gCDialog_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual bEResult                                   PostInitializeProperties( void );
public: virtual                                           ~gCDialog_PS( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat                     m_fEndDialogTimestamp;
    GEFloat                     m_fAccessSaleModifier;
    GEFloat                     m_fPurchaseModifier;
    GEBool                      m_bTradeEnabled;
    GEBool                      m_bTeachEnabled;
                                GE_PADDING( 2 )
    bTObjArray< gCSkillRange >  m_arrTeachSkills;
    GEBool                      m_bTalkedToPlayer;
    GEBool                      m_bPartyEnabled;
    GEBool                      m_bMobEnabled;
    GEBool                      m_bSlaveryEnabled;
    GEBool                      m_bPickedPocket;
                                GE_PADDING1( 3 )
    eCEntityProxy               m_TalkingTo;
    bTObjArray< eCEntityProxy > m_arrTalkedToBy;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &                          AccessEndDialogTimestamp( void );
    GEBool &                           AccessMobEnabled( void );
    GEBool &                           AccessPartyEnabled( void );
    GEBool &                           AccessPickedPocket( void );
    GEFloat &                          AccessPurchaseModifier( void );
    GEFloat &                          AccessSaleModifier( void );
    GEBool &                           AccessSlaveryEnabled( void );
    GEBool &                           AccessTalkedToPlayer( void );
    GEBool &                           AccessTeachEnabled( void );
    bTObjArray< gCSkillRange > &       AccessTeachSkills( void );
    GEBool &                           AccessTradeEnabled( void );
    GEInt                              AddTalkedToBy( eCEntity * );
    GEFloat const &                    GetEndDialogTimestamp( void ) const;
    GEBool const &                     GetMobEnabled( void ) const;
    GEBool const &                     GetPartyEnabled( void ) const;
    GEBool const &                     GetPickedPocket( void ) const;
    GEFloat const &                    GetPurchaseModifier( void ) const;
    GEFloat const &                    GetSaleModifier( void ) const;
    GEBool const &                     GetSlaveryEnabled( void ) const;
    eCEntity *                         GetTalkedToBy( GEInt ) const;
    GEInt                              GetTalkedToByCount( void ) const;
    GEBool const &                     GetTalkedToPlayer( void ) const;
    eCEntity *                         GetTalkingTo( void ) const;
    GEBool const &                     GetTeachEnabled( void ) const;
    bTObjArray< gCSkillRange > const & GetTeachSkills( void ) const;
    GEBool const &                     GetTradeEnabled( void ) const;
    GEBool                             RemoveTalkedToBy( eCEntity * );
    void                               SetEndDialogTimestamp( GEFloat const & );
    void                               SetMobEnabled( GEBool const & );
    void                               SetPartyEnabled( GEBool const & );
    void                               SetPickedPocket( GEBool const & );
    void                               SetPurchaseModifier( GEFloat const & );
    void                               SetSaleModifier( GEFloat const & );
    void                               SetSlaveryEnabled( GEBool const & );
    void                               SetTalkedToPlayer( GEBool const & );
    void                               SetTalkingTo( eCEntity * );
    void                               SetTeachEnabled( GEBool const & );
    void                               SetTeachSkills( bTObjArray< gCSkillRange > const & );
    void                               SetTradeEnabled( GEBool const & );
public:
    gCDialog_PS & operator = ( gCDialog_PS const & );
public:
    gCDialog_PS( gCDialog_PS const & );
    gCDialog_PS( void );
};
GE_ASSERT_SIZEOF( gCDialog_PS, 0x0048 )

#pragma warning( pop )

#endif
