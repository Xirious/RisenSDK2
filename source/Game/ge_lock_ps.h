#ifndef GE_LOCK_PS_H_INCLUDED
#define GE_LOCK_PS_H_INCLUDED

enum gELockCombi
{
    gELockCombi_Left,
    gELockCombi_Right,
    gELockCombi_ForceDWORD = GE_FORCE_DWORD
};

enum gELockStatus
{
    gELockStatus_Locked,
    gELockStatus_Unlocked,
    gELockStatus_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCLock_PS'

class GE_DLLIMPORT gCLock_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCLock_PS, eCEntityPropertySet )
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual bEResult                                   PostInitializeProperties( void );
public: virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual GEBool                                     IsReferencedByTemplate( void ) const;
public: virtual bEResult                                   ReadSaveGame( bCIStream & );
public: virtual bEResult                                   WriteSaveGame( bCOStream & );
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public: virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected:
    GE_DECLARE_ENUMPROP( gELockStatus,          m_enumStatus,          Status )
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_Key,                 Key )
    GE_DECLARE_PROPERTY( GEInt,                 m_iDifficulty,         Difficulty )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,   m_OnLockStatusChanged, OnLockStatusChanged )
    gELockCombi                                 m_penumLockCombinations[ 8 ];
public:
    gELockCombi GetLockCombination( GEInt ) const;
    GEInt       GetLockCombinationCount( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCLock_PS, 0x0048 )

#pragma warning( pop )

#endif
