#ifndef GE_DATABASE_H_INCLUDED
#define GE_DATABASE_H_INCLUDED

class GE_DLLIMPORT gCDatabase :
    public bCObjectRefBase
{
public:    virtual bCString       GetFileDir( void ) const;
GE_DECLARE_PROPERTY_OBJECT( gCDatabase, bCObjectRefBase )
public:    virtual void           Destroy( void );
public:    virtual               ~gCDatabase( void );
protected: using bCObjectRefBase::Create;
protected:
    gCWorkspace * m_pWorkspace;
public:
    static bCString GE_STDCALL GetAnimationPath( void );
    static bCString GE_STDCALL GetCommonLibrarayPath( void );
    static bCString GE_STDCALL GetCommonPhysicPath( void );
    static bCString GE_STDCALL GetCommonProjectsPath( void );
    static bCString GE_STDCALL GetCompiledAnimationPath( void );
    static bCString GE_STDCALL GetCompiledEffectsPath( void );
    static bCString GE_STDCALL GetCompiledImagePath( void );
    static bCString GE_STDCALL GetCompiledInfosPath( void );
    static bCString GE_STDCALL GetCompiledMeshPath( void );
    static bCString GE_STDCALL GetCompiledPhysicPath( void );
    static bCString GE_STDCALL GetCompiledQuestsPath( void );
    static bCString GE_STDCALL GetCompiledSoundPath( void );
    static bCString GE_STDCALL GetCompiledStringsPath( void );
    static bCString GE_STDCALL GetDeletedTemplatePath( void );
    static bCString GE_STDCALL GetImagePath( void );
    static bCString GE_STDCALL GetLightmapPath( void );
    static bCString GE_STDCALL GetMaterialPath( void );
    static bCString GE_STDCALL GetMeshPath( void );
    static bCString GE_STDCALL GetRawEffectsPath( void );
    static bCString GE_STDCALL GetRawInfosPath( void );
    static bCString GE_STDCALL GetRawProjectsPath( void );
    static bCString GE_STDCALL GetRawQuestsPath( void );
    static bCString GE_STDCALL GetRawSoundPath( void );
    static bCString GE_STDCALL GetRawStringsPath( void );
    static bCString GE_STDCALL GetRootPath( void );
    static bCString GE_STDCALL GetSaveGamePath( void );
    static bCString GE_STDCALL GetSpeedTreePath( void );
    static bCString GE_STDCALL GetTemplatePath( void );
public:
    bEResult            Create( gCWorkspace & a_Reserved, bCString const & a_strReserved );
    eCTemplateEntity *  CreateSpecificEntity( void );
    gCWorkspace &       GetWorkspace( void );
    gCWorkspace const & GetWorkspace( void ) const;
protected:
    GEBool AddToDatabase( bCString const & a_strTemplatePath, GEBool a_bRoot = GETrue );
    void   Invalidate( void );
    void   SetWorkspace( gCWorkspace const * a_pWorkspace );
};
GE_ASSERT_SIZEOF( gCDatabase, 0x000C )

#endif
