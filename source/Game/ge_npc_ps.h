#ifndef GE_NPC_PS_H_INCLUDED
#define GE_NPC_PS_H_INCLUDED

enum gEAttitude
{
    gEAttitude_None       = 0x00000000,
    gEAttitude_Friendly   = 0x00000001,
    gEAttitude_Neutral    = 0x00000002,
    gEAttitude_Angry      = 0x00000003,
    gEAttitude_Hostile    = 0x00000004,
    gEAttitude_ForceDWORD = GE_FORCE_DWORD
};

enum gEBraveryOverride
{
    gEBraveryOverride_None       = 0x00000000,
    gEBraveryOverride_Brave      = 0x00000001,
    gEBraveryOverride_Coward     = 0x00000002,
    gEBraveryOverride_ForceDWORD = GE_FORCE_DWORD
};

enum gEComment
{
    gEComment_None              = 0x00000000,
    gEComment_DefeatInquisition = 0x00000001,
    gEComment_Theft             = 0x00000002,
    gEComment_Livestock         = 0x00000003,
    gEComment_Defeat            = 0x00000004,
    gEComment_Count             = 0x00000005,
    gEComment_ForceDWORD        = GE_FORCE_DWORD
};

enum gECrime
{
    gECrime_None            = 0x00000000,
    gECrime_MurderLivestock = 0x00000001,
    gECrime_Theft           = 0x00000002,
    gECrime_Murder          = 0x00000003,
    gECrime_Count           = 0x00000004,
    gECrime_ForceDWORD      = GE_FORCE_DWORD
};

enum gEDamageCalculationType
{
    gEDamageCalculationType_Normal     = 0x00000000,
    gEDamageCalculationType_Monster    = 0x00000001,
    gEDamageCalculationType_Immortal   = 0x00000002,
    gEDamageCalculationType_ForceDWORD = GE_FORCE_DWORD
};

enum gEFight
{
    gEFight_None       = 0x00000000,
    gEFight_Lost       = 0x00000001,
    gEFight_Won        = 0x00000002,
    gEFight_Cancel     = 0x00000003,
    gEFight_Running    = 0x00000004,
    gEFight_ForceDWORD = GE_FORCE_DWORD
};

enum gEGender
{
    gEGender_Male       = 0x00000000,
    gEGender_Female     = 0x00000001,
    gEGender_ForceDWORD = GE_FORCE_DWORD
};

enum gEGuardStatus
{
    gEGuardStatus_Active          = 0x00000000,
    gEGuardStatus_FirstWarnGiven  = 0x00000001,
    gEGuardStatus_SecondWarnGiven = 0x00000002,
    gEGuardStatus_Inactive        = 0x00000003,
    gEGuardStatus_Behind          = 0x00000004,
    gEGuardStatus_ForceDWORD      = GE_FORCE_DWORD
};

enum gEGuild
{
    gEGuild_None       = 0x00000000,
    gEGuild_Don        = 0x00000001,
    gEGuild_Dig        = 0x00000002,
    gEGuild_Grd        = 0x00000003,
    gEGuild_Cit        = 0x00000004,
    gEGuild_Inq        = 0x00000005,
    gEGuild_Mag        = 0x00000006,
    gEGuild_Pir        = 0x00000007,
    gEGuild_Count      = 0x00000008,
    gEGuild_ForceDWORD = GE_FORCE_DWORD
};

enum gEReason
{
    gEReason_None            = 0x00000000,
    gEReason_SVM_Ambient     = 0x00000001,
    gEReason_SVM_Combat      = 0x00000002,
    gEReason_SVM_Party       = 0x00000003,
    gEReason_PlayerTalk      = 0x00000004,
    gEReason_ImportantInfo   = 0x00000005,
    gEReason_PlayerSneaking  = 0x00000006,
    gEReason_PlayerWeapon    = 0x00000007,
    gEReason_PlayerRoom      = 0x00000008,
    gEReason_PlayerUseBed    = 0x00000009,
    gEReason_Eat             = 0x0000000A,
    gEReason_Ransack         = 0x0000000B,
    gEReason_Fighter         = 0x0000000C,
    gEReason_Attacker        = 0x0000000D,
    gEReason_Nuisance        = 0x0000000E,
    gEReason_Joke            = 0x0000000F,
    gEReason_Frost           = 0x00000010,
    gEReason_Damage          = 0x00000011,
    gEReason_DamageLivestock = 0x00000012,
    gEReason_MurderLivestock = 0x00000013,
    gEReason_Theft           = 0x00000014,
    gEReason_Illusion        = 0x00000015,
    gEReason_GateGuard       = 0x00000016,
    gEReason_Defeat          = 0x00000017,
    gEReason_Inspect         = 0x00000018,
    gEReason_Finish          = 0x00000019,
    gEReason_Raider          = 0x0000001A,
    gEReason_Enemy           = 0x0000001B,
    gEReason_Murder          = 0x0000001C,
    gEReason_Duel            = 0x0000001D,
    gEReason_Arena           = 0x0000001E,
    gEReason_Kill            = 0x0000001F,
    gEReason_Count           = 0x00000020,
    gEReason_ForceDWORD      = GE_FORCE_DWORD
};

enum gESpecies
{
    gESpecies_None          = 0x00000000,
    gESpecies_Human         = 0x00000001,
    gESpecies_Lizard        = 0x00000002,
    gESpecies_Brontok       = 0x00000003,
    gESpecies_Wolf_Tame     = 0x00000004,
    gESpecies_Lurker        = 0x00000005,
    gESpecies_Ashbeast      = 0x00000006,
    gESpecies_Nautilus      = 0x00000007,
    gESpecies_Dragonfly     = 0x00000008,
    gESpecies_Mantis        = 0x00000009,
    gESpecies_Scorpion      = 0x0000000A,
    gESpecies_Skeleton      = 0x0000000B,
    gESpecies_Swampmummy    = 0x0000000C,
    gESpecies_Rotworm       = 0x0000000D,
    gESpecies_Skeleton_Tame = 0x0000000E,
    gESpecies_Gnome         = 0x0000000F,
    gESpecies_Boar          = 0x00000010,
    gESpecies_Wolf          = 0x00000011,
    gESpecies_Stingrat      = 0x00000012,
    gESpecies_Vulture       = 0x00000013,
    gESpecies_Thundertail   = 0x00000014,
    gESpecies_Ogre          = 0x00000015,
    gESpecies_Ogre_Tame     = 0x00000016,
    gESpecies_Cow           = 0x00000017,
    gESpecies_Pig           = 0x00000018,
    gESpecies_Chicken       = 0x00000019,
    gESpecies_Ghost         = 0x0000001A,
    gESpecies_Count         = 0x0000001B,
    gESpecies_ForceDWORD    = GE_FORCE_DWORD
};

enum gEStatusEffect
{
    gEStatusEffect_All        = 0xFFFFFFFF,
    gEStatusEffect_None       = 0x00000000,
    gEStatusEffect_Burning    = 0x00000001,
    gEStatusEffect_Frozen     = 0x00000002,
    gEStatusEffect_Poisoned   = 0x00000004,
    gEStatusEffect_Special    = 0x00000008  // (Transform)Beast, Berserker, Levitating, (Transform)Nautilus, Protection, Sprinting
};

struct gSNPCStatusEffect
{
    GEBool              m_bActive;
                        GE_PADDING( 3 )
    gEStatusEffect      m_enumStatusEffect;
    bCString            m_strName;
    eCScriptProxyScript m_StartScript;
    eCScriptProxyScript m_ProcessScript;
    eCScriptProxyScript m_StopScript;
    eCEntityProxy       m_SelfEntity;
    GEU32               m_u32StartTime;
    GEU32               m_u32Duration;
    GEU32               m_u32Time;
    GEU32               m_u32UserData;
};
GE_ASSERT_SIZEOF( gSNPCStatusEffect, 0x003C )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<>' needs to have dll-interface to be used by clients of class 'gCNPC_PS'
                                   // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCNPC_PS'
                                   // class 'gCNPC_PS::CProcessor' needs to have dll-interface to be used by clients of class 'gCNPC_PS'

class GE_DLLIMPORT gCNPC_PS :
    public eCEntityPropertySet
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;
    public: virtual GEU32 GetAppStateFlags( void ) const;
    public: virtual void  OnProcess( void );
    public: virtual      ~CProcessor( void );
    protected:
        gCNPC_PS * m_pNpcPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public: virtual                           ~gCNPC_PS( void );
public: virtual eEPropertySetType          GetPropertySetType( void ) const;
public: virtual GEBool                     IsReferencedByTemplate( void ) const;
public: virtual bEResult                   ReadSaveGame( bCIStream & );
public: virtual bEResult                   WriteSaveGame( bCOStream & );
public: virtual eEPSSaveGameRelevance      GetSaveGameRelevance( void ) const;
public: virtual void                       OnSaveGameEntityPostRead( void );
public: virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public: virtual GEBool                     IsClassProcessible( void ) const;
public: virtual GEBool                     IsClassProcessingEnabled( void ) const;
public: virtual void                       EnableClassProcessing( GEBool );
public: virtual void                       EnterProcessingRange( void );
public: virtual void                       ExitProcessingRange( void );
public: virtual void                       OnProcess( void );
public: virtual void                       OnPostRead( void );
public: virtual void                       OnPostCopy( eCEntityPropertySet const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                                       m_strVoice;
    bCString                                       m_strRoleDescription;
    bTPropertyContainer< gEGender >                m_enumGender;
    bTPropertyContainer< gEBraveryOverride >       m_enumBraveryOverride;
    bTPropertyContainer< gESpecies >               m_enumSpecies;
    bTPropertyContainer< gEAttitude >              m_enumAttitudeLock;
    bTPropertyContainer< gECrime >                 m_enumLastPlayerCrime;
    bTPropertyContainer< gEComment >               m_enumLastPlayerComment;
    GEFloat                                        m_fLastCommentTimestamp;
    bTPropertyContainer< gEReason >                m_enumReason;
    bTPropertyContainer< gEReason >                m_enumLastReason;
    bTPropertyContainer< gEReason >                m_enumLastPlayerAR;
    bTPropertyContainer< gEFight >                 m_enumLastFightAgainstPlayer;
    GEFloat                                        m_fLastFightTimestamp;
    GEFloat                                        m_fPlayerWeaponTimestamp;
    GEFloat                                        m_fLastDistToTarget;
    GEBool                                         m_bDefeatedByPlayer;
    GEBool                                         m_bRansacked;
    GEBool                                         m_bDiscovered;
                                                   GE_PADDING( 1 )
    eCEntityProxy                                  m_CurrentTargetEntity;
    eCEntityProxy                                  m_CurrentAttackerEntity;
    eCEntityProxy                                  m_LastAttackerEntity;
    eCEntityProxy                                  m_GuardPoint;
    bTPropertyContainer< gEGuardStatus >           m_enumGuardStatus;
    GEFloat                                        m_fLastDistToGuardPoint;
    bCString                                       m_strAnimationBearing;
    eCEntityProxy                                  m_SpellTarget;
    bTPropertyContainer< gEDamageCalculationType > m_enumDamageCalculationType;
    bTPropertyContainer< gEGuild >                 m_enumGuild;
    bCString                                       m_strGroup;
    bCString                                       m_strEffectSpecies;
    bCString                                       m_strEffectMaterial;
    CProcessor                                     m_Processor;
    GEU32                                          m_u32StatusEffects;
    bTObjArray< gSNPCStatusEffect >                m_arrStatusEffects;
    bCString                                       m_strCurrentMovementAni;
protected:
    void GameReset( void );
    void Invalidate( void );
    void ProcessStatusEffect( GEInt, GEU32 );
    void ProcessStatusEffects( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                             AccessAnimationBearing( void );
    bTPropertyContainer< gEAttitude > &                    AccessAttitudeLock( void );
    bTPropertyContainer< gEBraveryOverride > &             AccessBraveryOverride( void );
    eCEntityProxy &                                        AccessCurrentAttackerEntity( void );
    eCEntityProxy &                                        AccessCurrentTargetEntity( void );
    bTPropertyContainer< gEDamageCalculationType > &       AccessDamageCalculationType( void );
    GEBool &                                               AccessDefeatedByPlayer( void );
    GEBool &                                               AccessDiscovered( void );
    bCString &                                             AccessEffectMaterial( void );
    bCString &                                             AccessEffectSpecies( void );
    bTPropertyContainer< gEGender > &                      AccessGender( void );
    bCString &                                             AccessGroup( void );
    eCEntityProxy &                                        AccessGuardPoint( void );
    bTPropertyContainer< gEGuardStatus > &                 AccessGuardStatus( void );
    bTPropertyContainer< gEGuild > &                       AccessGuild( void );
    eCEntityProxy &                                        AccessLastAttackerEntity( void );
    GEFloat &                                              AccessLastCommentTimestamp( void );
    GEFloat &                                              AccessLastDistToGuardPoint( void );
    GEFloat &                                              AccessLastDistToTarget( void );
    bTPropertyContainer< gEFight > &                       AccessLastFightAgainstPlayer( void );
    GEFloat &                                              AccessLastFightTimestamp( void );
    bTPropertyContainer< gEReason > &                      AccessLastPlayerAR( void );
    bTPropertyContainer< gEComment > &                     AccessLastPlayerComment( void );
    bTPropertyContainer< gECrime > &                       AccessLastPlayerCrime( void );
    bTPropertyContainer< gEReason > &                      AccessLastReason( void );
    GEFloat &                                              AccessPlayerWeaponTimestamp( void );
    GEBool &                                               AccessRansacked( void );
    bTPropertyContainer< gEReason > &                      AccessReason( void );
    bCString &                                             AccessRoleDescription( void );
    bTPropertyContainer< gESpecies > &                     AccessSpecies( void );
    eCEntityProxy &                                        AccessSpellTarget( void );
    bCString &                                             AccessVoice( void );
    GEBool                                                 BeginStatusEffect( gSNPCStatusEffect const &, GEU32 );
    GEBool                                                 EndStatusEffect(gEStatusEffect);
    bCString const &                                       GetAnimationBearing( void ) const;
    bTPropertyContainer< gEAttitude > const &              GetAttitudeLock( void ) const;
    bTPropertyContainer< gEBraveryOverride > const &       GetBraveryOverride( void ) const;
    eCEntityProxy const &                                  GetCurrentAttackerEntity( void ) const;
    bCString const &                                       GetCurrentMovementAni( void ) const;
    eCEntityProxy const &                                  GetCurrentTargetEntity( void ) const;
    bTPropertyContainer< gEDamageCalculationType > const & GetDamageCalculationType( void ) const;
    GEBool const &                                         GetDefeatedByPlayer( void ) const;
    GEBool const &                                         GetDiscovered( void ) const;
    bCString const &                                       GetEffectMaterial( void ) const;
    bCString const &                                       GetEffectSpecies( void ) const;
    bTPropertyContainer< gEGender > const &                GetGender( void ) const;
    bCString const &                                       GetGroup( void ) const;
    eCEntityProxy const &                                  GetGuardPoint( void ) const;
    bTPropertyContainer< gEGuardStatus > const &           GetGuardStatus( void ) const;
    bTPropertyContainer< gEGuild > const &                 GetGuild( void ) const;
    eCEntityProxy const &                                  GetLastAttackerEntity( void ) const;
    GEFloat const &                                        GetLastCommentTimestamp( void ) const;
    GEFloat const &                                        GetLastDistToGuardPoint( void ) const;
    GEFloat const &                                        GetLastDistToTarget( void ) const;
    bTPropertyContainer< gEFight > const &                 GetLastFightAgainstPlayer( void ) const;
    GEFloat const &                                        GetLastFightTimestamp( void ) const;
    bTPropertyContainer< gEReason > const &                GetLastPlayerAR( void ) const;
    bTPropertyContainer< gEComment > const &               GetLastPlayerComment( void ) const;
    bTPropertyContainer< gECrime > const &                 GetLastPlayerCrime( void ) const;
    bTPropertyContainer< gEReason > const &                GetLastReason( void ) const;
    GEFloat const &                                        GetPlayerWeaponTimestamp( void ) const;
    GEBool const &                                         GetRansacked( void ) const;
    bTPropertyContainer< gEReason > const &                GetReason( void ) const;
    bCString const &                                       GetRoleDescription( void ) const;
    bTPropertyContainer< gESpecies > const &               GetSpecies( void ) const;
    eCEntityProxy const &                                  GetSpellTarget( void ) const;
    gSNPCStatusEffect *                                    GetStatusEffect( gEStatusEffect );
    bCString const &                                       GetVoice( void ) const;
    eCGeometryEntity *                                     GetWeapon( GEBool );
    GEBool                                                 HasStatusEffect( gEStatusEffect ) const;
    GEBool                                                 IsDead( void );
    GEBool                                                 IsDown( void );
    void                                                   SetAnimationBearing( bCString const & );
    void                                                   SetAttitudeLock( bTPropertyContainer< gEAttitude > const & );
    void                                                   SetBraveryOverride( bTPropertyContainer< gEBraveryOverride > const & );
    void                                                   SetCurrentAttackerEntity( eCEntityProxy const & );
    void                                                   SetCurrentMovementAni( bCString const & );
    void                                                   SetCurrentTargetEntity( eCEntityProxy const & );
    void                                                   SetDamageCalculationType( bTPropertyContainer< gEDamageCalculationType > const & );
    void                                                   SetDefeatedByPlayer( GEBool const & );
    void                                                   SetDiscovered( GEBool const & );
    void                                                   SetEffectMaterial( bCString const & );
    void                                                   SetEffectSpecies( bCString const & );
    void                                                   SetGender( bTPropertyContainer< gEGender > const & );
    void                                                   SetGroup( bCString const & );
    void                                                   SetGuardPoint( eCEntityProxy const & );
    void                                                   SetGuardStatus( bTPropertyContainer< gEGuardStatus > const & );
    void                                                   SetGuild( bTPropertyContainer< gEGuild > const & );
    void                                                   SetLastAttackerEntity( eCEntityProxy const & );
    void                                                   SetLastCommentTimestamp( GEFloat const & );
    void                                                   SetLastDistToGuardPoint( GEFloat const & );
    void                                                   SetLastDistToTarget( GEFloat const & );
    void                                                   SetLastFightAgainstPlayer( bTPropertyContainer< gEFight > const & );
    void                                                   SetLastFightTimestamp( GEFloat const & );
    void                                                   SetLastPlayerAR( bTPropertyContainer< gEReason > const & );
    void                                                   SetLastPlayerComment( bTPropertyContainer< gEComment > const & );
    void                                                   SetLastPlayerCrime( bTPropertyContainer< gECrime > const & );
    void                                                   SetLastReason( bTPropertyContainer< gEReason > const & );
    void                                                   SetPlayerWeaponTimestamp( GEFloat const & );
    void                                                   SetRansacked( GEBool const & );
    void                                                   SetReason( bTPropertyContainer< gEReason > const & );
    void                                                   SetRoleDescription( bCString const & );
    void                                                   SetSpecies( bTPropertyContainer< gESpecies > const & );
    void                                                   SetSpellTarget( eCEntityProxy const & );
    void                                                   SetVoice( bCString const & );
public:
    gCNPC_PS & operator = ( gCNPC_PS const & );
public:
    gCNPC_PS( gCNPC_PS const & );
    gCNPC_PS( void );
};
GE_ASSERT_SIZEOF( gCNPC_PS, 0x00F4 )

#pragma warning( pop )

#endif
