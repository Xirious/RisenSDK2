#ifndef GE_DATABASE_H_INCLUDED
#define GE_DATABASE_H_INCLUDED

class GE_DLLIMPORT gCDatabase :
    public bCObjectRefBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: using             bCObjectRefBase::Create;
public: virtual void                       Destroy( void );
public: virtual                           ~gCDatabase( void );
public: virtual bCString                   GetFileDir( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCWorkspace * m_pWorkspace;
protected:
    GEBool AddToDatabase( bCString const &, GEBool );
    void   Invalidate( void );
    void   SetWorkspace( gCWorkspace const * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL GetAnimationPath( void );
    static bCString                   GE_STDCALL GetCommonLibrarayPath( void );
    static bCString                   GE_STDCALL GetCommonPhysicPath( void );
    static bCString                   GE_STDCALL GetCommonProjectsPath( void );
    static bCString                   GE_STDCALL GetCompiledAnimationPath( void );
    static bCString                   GE_STDCALL GetCompiledEffectsPath( void );
    static bCString                   GE_STDCALL GetCompiledImagePath( void );
    static bCString                   GE_STDCALL GetCompiledInfosPath( void );
    static bCString                   GE_STDCALL GetCompiledMeshPath( void );
    static bCString                   GE_STDCALL GetCompiledPhysicPath( void );
    static bCString                   GE_STDCALL GetCompiledQuestsPath( void );
    static bCString                   GE_STDCALL GetCompiledSoundPath( void );
    static bCString                   GE_STDCALL GetCompiledStringsPath( void );
    static bCString                   GE_STDCALL GetDeletedTemplatePath( void );
    static bCString                   GE_STDCALL GetImagePath( void );
    static bCString                   GE_STDCALL GetLightmapPath( void );
    static bCString                   GE_STDCALL GetMaterialPath( void );
    static bCString                   GE_STDCALL GetMeshPath( void );
    static bCString                   GE_STDCALL GetRawEffectsPath( void );
    static bCString                   GE_STDCALL GetRawInfosPath( void );
    static bCString                   GE_STDCALL GetRawProjectsPath( void );
    static bCString                   GE_STDCALL GetRawQuestsPath( void );
    static bCString                   GE_STDCALL GetRawSoundPath( void );
    static bCString                   GE_STDCALL GetRawStringsPath( void );
    static bCString                   GE_STDCALL GetRootPath( void );
    static bCString                   GE_STDCALL GetSaveGamePath( void );
    static bCString                   GE_STDCALL GetSpeedTreePath( void );
    static bCString                   GE_STDCALL GetTemplatePath( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bEResult            Create( gCWorkspace &, bCString const & );
    eCTemplateEntity *  CreateSpecificEntity( void );
    gCWorkspace &       GetWorkspace( void );
    gCWorkspace const & GetWorkspace( void ) const;
public:
    gCDatabase & operator = ( gCDatabase const & );
public:
    gCDatabase( gCDatabase const & );
    gCDatabase( void );
};
GE_ASSERT_SIZEOF( gCDatabase, 0x000C )

#endif
