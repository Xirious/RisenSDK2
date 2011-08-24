#ifndef GE_SKILLS_PS_H_INCLUDED
#define GE_SKILLS_PS_H_INCLUDED

enum gESkillCategroy
{
    gESkillCategory_Atrib      = 0x00000000,
    gESkillCategory_Stat1      = 0x00000001,  // LV/XP/LP
    gESkillCategory_Stat2      = 0x00000002,  // HP/MP/STR/DEX/INT
    gESkillCategory_Prot       = 0x00000003,
    gESkillCategory_Combat     = 0x00000004,
    gESkillCategory_Magic      = 0x00000005,
    gESkillCategory_Misc       = 0x00000006,
    gESkillCategory_ForceDWORD = GE_FORCE_DWORD
};

struct gSSkillInfo
{
    GEI32           m_i32MinValue;
    GEI32           m_i32MaxValue;
    GEI32           m_i32BaseValue;
    gESkillCategroy m_enumCategory;
    GEU8            m_u8CategoryIndex;
                    GE_PADDING( 3 )
    bCString        m_strTag;
    eCLocString     m_locName;
    eCLocString     m_locShortName;
    eCLocString     m_locDesc;
    eCLocString     m_locRequDesc;
};
GE_ASSERT_SIZEOF( gSSkillInfo, 0x0048 )

struct gSMissingSkill
{
    gESkill     m_enumSkill;
    GEI32       m_i32Missing;
    gSSkillInfo m_SkillInfo;
};
GE_ASSERT_SIZEOF( gSMissingSkill, 0x0050 )

class GE_DLLIMPORT gCSkills_PS :
    public eCEntityPropertySet
{
public:
    typedef void (GE_STDCALL * gFSkillChangedCallback)( gCSkills_PS *, gESkill );
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual GEBool                     OnCopyFrom( bCObjectBase const & );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual GEInt                      GetNativePropertyCount( void ) const;
public: virtual bCPropertyConverterPtr     GetNativePropertyAt( GEInt ) const;
public: virtual                           ~gCSkills_PS( void );
public: virtual eEPropertySetType          GetPropertySetType( void ) const;
public: virtual GEBool                     IsEditorRelevant( void ) const;
public: virtual bEResult                   ReadSaveGame( bCIStream & );
public: virtual bEResult                   WriteSaveGame( bCOStream & );
public: virtual eEPSSaveGameRelevance      GetSaveGameRelevance( void ) const;
private:
    static gSSkillInfo              ms_arrSkillInfos[ gESkill_Count ];
    static gFSkillChangedCallback   ms_pSkillChangedCallback;
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x0120 - sizeof(eCEntityPropertySet) ];
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL FindNextSkill( bCString const &, bCString const & );
    static gFSkillChangedCallback     GE_STDCALL GetChangedCallback( void );
    static eCLocString const &        GE_STDCALL GetSkillDesc( gESkill );
    static eCLocString const &        GE_STDCALL GetSkillName( gESkill );
    static eCLocString const &        GE_STDCALL GetSkillRequDesc( gESkill );
    static eCLocString const &        GE_STDCALL GetSkillShortName( gESkill );
    static bCString const &           GE_STDCALL GetSkillTag( gESkill );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL SetChangedCallback( gFSkillChangedCallback );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void     ApplySkillModifyValue( gCSkillValue const & );
    void     ApplySkillModifyValues( bTObjArray< gCSkillValue > const & );
    GEI32    GetSkillBaseValue( gESkill ) const;
    bCString GetSkillImageTag( gESkill ) const;
    void     GetSkillInfo( gESkill, gSSkillInfo & ) const;
    GEI32    GetSkillMaxValue( gESkill ) const;
    GEI32    GetSkillModifyValue( gESkill ) const;
    GEI32    GetSkillValue( gESkill ) const;
    GEBool   HasRequiredSkill( gCSkillValue const &, gSMissingSkill * ) const;
    GEBool   HasRequiredSkills( bTObjArray< gCSkillValue > const &, bTObjArray< gSMissingSkill > * ) const;
    void     ModifySkillValue( gCModifySkill const &, GEBool );
    void     ModifySkillValues( bTObjArray< gCModifySkill > const &, GEBool );
    void     SetSkillBaseValue( gESkill, GEI32 );
    void     SetSkillModifyValue( gESkill, GEI32 );
    void     SetSkillValue( gESkill, GEI32 );
    void     SetToDefaults( void );
    void     UnapplySkillModifyValue( gCSkillValue const & );
    void     UnapplySkillModifyValues( bTObjArray< gCSkillValue > const & );
public:
    gCSkills_PS & operator = ( gCSkills_PS const & );
public:
    gCSkills_PS( gCSkills_PS const & );
    gCSkills_PS( void );
};
GE_ASSERT_SIZEOF( gCSkills_PS, 0x0120 )

#endif
