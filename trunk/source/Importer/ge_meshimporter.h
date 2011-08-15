#ifndef GE_MESHIMPORTER_H_INCLUDED
#define GE_MESHIMPORTER_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<T>' needs to have dll-interface to be used by clients of class 'iCMeshImporter'

class GE_DLLIMPORT iCMeshImporter
{
public: virtual void   Destroy( void );
public: virtual GEBool Create( void );
public: virtual GEBool CopyFrom( iCMeshImporter const & );
public: virtual       ~iCMeshImporter( void );
protected:
    bCString                       m_strImportFilePath;
    bCString                       m_strLayerName;
    bCString                       m_strMeshFilePath;
    bCString                       m_strMaterialFilePath;
    bCString                       m_strImageFilePath;
    bCString                       m_strCellifiedMeshName;
    GEBool                         m_bMaterialWrite;
    GEBool                         m_bMeshWrite;
    GEBool                         m_bReplaceOldMeshFiles;
    GEBool                         m_bReplaceOldMaterialFiles;
    GEBool                         m_bSkipCollisionMeshes;
    GEBool                         m_bCalculateAmbientOcclusion;
    GEBool                         m_bWriteStaticEntities;
    GEBool                         m_bCellifierEnabled;
    GEBool                         m_bFixScaling;
    GEBool                         m_bEntityUpdate;
    GEBool                         m_bEntityDelete;
    GEBool                         m_bMultipleEntityWriteForLODMesh;
    GEFloat                        m_fAOShadowSoftness;
    GEFloat                        m_fScaleFactor;
    GEFloat                        m_fCellSize;
    gCSector *                     m_pSector;
    bTPtrArray< gCDynamicLayer * > m_arrLayers;
protected:
    GEBool     CollectCellEntities( eCEntity *, bTPtrArray< eCEntity * > & );
    eCEntity * CreateVisualEntity( eCEntity *, bCString const &, GEBool );
    void       Invalidate( void );
public:
    void             FillImportMeshValues( void );
    void             FillImportSceneValues( GEBool );
    void             FillStandardValues( void );
    GEFloat          GetAOShadowSoftness( void ) const;
    GEBool           GetCalculateAmbientOcclusion( void ) const;
    GEFloat          GetCellSize( void ) const;
    bCString const & GetCellifiedMeshName( void ) const;
    GEBool           GetCellifierEnabled( void ) const;
    GEBool           GetEntityDelete( void ) const;
    GEBool           GetEntityUpdate( void ) const;
    GEBool           GetFixScaling( void ) const;
    bCString const & GetImageFilePath( void ) const;
    bCString const & GetImportFilePath( void ) const;
    bCString const & GetLayerName( void ) const;
    bCString const & GetMaterialFilePath( void ) const;
    GEBool           GetMaterialWrite( void ) const;
    bCString const & GetMeshFilePath( void ) const;
    GEBool           GetMeshWrite( void ) const;
    GEBool           GetMultipleEntityWriteForLODMesh( void ) const;
    GEBool           GetReplaceOldMaterialFiles( void ) const;
    GEBool           GetReplaceOldMeshFiles( void ) const;
    GEFloat          GetScaleFactor( void ) const;
    gCSector *       GetSector( void ) const;
    GEBool           GetSkipCollisionMeshes( void ) const;
    GEBool           GetWriteStaticEntities( void ) const;
    GEBool           Process( void );
    GEBool           ProcessMeshOnly( void );
    void             SetAOShadowSoftness( GEFloat );
    void             SetCalculateAmbientOcclusion( GEBool );
    void             SetCellSize( GEFloat );
    void             SetCellifiedMeshName( bCString const & );
    void             SetCellifierEnable( GEBool );
    void             SetEntityDelete( GEBool );
    void             SetEntityUpdate( GEBool );
    void             SetFixScaling( GEBool );
    void             SetImageFilePath( bCString const & );
    void             SetImportFilePath( bCString const & );
    void             SetLayerName( bCString const & );
    void             SetMaterialFilePath( bCString const & );
    void             SetMaterialWrite( GEBool );
    void             SetMeshFilePath( bCString const & );
    void             SetMeshWrite( GEBool );
    void             SetMultipleEntityWriteForLODMesh( GEBool );
    void             SetReplaceOldMaterialFiles( GEBool );
    void             SetReplaceOldMeshFiles( GEBool );
    void             SetScaleFactor( GEFloat );
    void             SetSector( gCSector * );
    void             SetSkipCollisionMeshes( GEBool );
    void             SetWriteStaticEntities( GEBool );
public:
    iCMeshImporter & operator = ( iCMeshImporter const & );
public:
    iCMeshImporter( iCMeshImporter const & );
    iCMeshImporter( void );
};
GE_ASSERT_SIZEOF( iCMeshImporter, 0x0044 )

#pragma warning( pop )

#endif
