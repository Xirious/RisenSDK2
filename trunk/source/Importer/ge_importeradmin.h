#ifndef GE_IMPORTERADMIN_H_INCLUDED
#define GE_IMPORTERADMIN_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<T>' needs to have dll-interface to be used by clients of class 'iCImporterAdmin'

class GE_DLLIMPORT iCImporterAdmin
{
public:
    typedef void (GE_STDCALL * iFMeshConvertCallback)( bCString const & );
public: virtual GEBool Create( void );
public: virtual void   Destroy( void );
public: virtual       ~iCImporterAdmin( void );
protected:
    iCBaseFileReader *     m_pFileReader;
    iCOptimizer *          m_pOptimizer;
    iCStrippifier *        m_pStrippifier;
    iCMasterWriter *       m_pMasterWriter;
    GEBool                 m_bStopOnCrash;
    GEBool                 m_bEmptyEntitySkip;
    GEBool                 m_bStrippifier;
    GEBool                 m_bMaterialWrite;
    GEBool                 m_bMeshWrite;
    GEBool                 m_bGeomEntityWrite;
    GEBool                 m_bEntityGroupWrite;
    GEBool                 m_bDynamicEntityWrite;
    GEBool                 m_bReplaceOldMaterialFiles;
    GEBool                 m_bReplaceOldMeshFiles;
    GEBool                 m_bCollisionMeshSkip;
    GEBool                 m_bAmbientOcclusion;
    GEBool                 m_bUseCellifier;
    GEBool                 m_bPureMatrixCorrectPass;
    GEBool                 m_bEntityUpdate;
    GEBool                 m_bEntityDelete;
    GEBool                 m_bMultipleEntityWriteForLODMesh;
                           GE_PADDING( 3 )
    GEFloat                m_fAmbientOcclusionShadowSoftnes;
    iFMeshConvertCallback  m_funcMeshConvertCallback;
    bCString               m_strMeshPath;
    bCString               m_strMaterialPath;
    bCString               m_strImagePath;
    gCWorld *              m_pWorld;
    gCDynamicLayer *       m_pDynamicLayer;
    bTPtrArray< eCNode * > m_arrContextGraphChildren;
    GEFloat                m_fScaleFactor;
protected:
    GEBool RunAllDynamicEntityPasses( bCString );
    GEBool RunAllEntityGroupPasses( bCString );
    GEBool RunAllGeomEntityPasses( bCString, GEBool );
    GEBool RunAllMaterialPasses( bCString );
    GEBool RunAllMeshPasses( bCString, GEBool );
    GEBool RunAllSplinePasses( bCString );
public:
    void                           EnableAmbientOcclusion( GEBool );
    void                           EnableCollisionMeshSkip( GEBool );
    void                           EnableDynamicEntityWrite( GEBool );
    void                           EnableEmptyEntitySkip( GEBool );
    void                           EnableEntityDelete( GEBool );
    void                           EnableEntityGroupWrite( GEBool );
    void                           EnableEntityUpdate( GEBool );
    void                           EnableGeomEntityWrite( GEBool );
    void                           EnableMaterialWrite( GEBool );
    void                           EnableMeshWrite( GEBool );
    void                           EnableMultipleEntityWriteForLODMesh( GEBool );
    void                           EnablePureMatrixCorrectPass( GEBool );
    void                           EnableReplaceOldFiles( GEBool );
    void                           EnableReplaceOldMaterialFiles( GEBool );
    void                           EnableReplaceOldMeshFiles( GEBool );
    void                           EnableStopOnCrash( GEBool );
    void                           EnableStrippifier( GEBool );
    void                           EnableUseCellifier( GEBool );
    GEFloat                        GetAmbientOcclusionShadowSoftnes( void ) const;
    void                           GetDynamicLayer( gCDynamicLayer * & ) const;
    GEBool                         GetEnableAmbientOcclusion( void ) const;
    GEBool                         GetEnableCollisionMeshSkip( void ) const;
    GEBool                         GetEnableDynamicEntityWrite( void ) const;
    GEBool                         GetEnableEmptyEntitySkip( void ) const;
    GEBool                         GetEnableEntityDelete( void ) const;
    GEBool                         GetEnableEntityGroupWrite( void ) const;
    GEBool                         GetEnableEntityUpdate( void ) const;
    GEBool                         GetEnableGeomEntityWrite( void ) const;
    GEBool                         GetEnableMaterialWrite( void ) const;
    GEBool                         GetEnableMeshWrite( void ) const;
    GEBool                         GetEnableMultipleEntityWriteForLODMesh( void ) const;
    GEBool                         GetEnableReplaceOldFiles( void ) const;
    GEBool                         GetEnableReplaceOldMaterialFiles( void ) const;
    GEBool                         GetEnableReplaceOldMeshFiles( void ) const;
    GEBool                         GetEnableStopOnCrash( void ) const;
    GEBool                         GetEnableStrippifier( void ) const;
    void                           GetImagePath( bCString & ) const;
    bTObjArray< bCString > const & GetListOfEmptyEntites( void ) const;
    void                           GetMaterialPath( bCString & ) const;
    iFMeshConvertCallback          GetMeshConvertCallback( void ) const;
    void                           GetMeshPath( bCString & ) const;
    GEBool                         GetPureMatrixCorrectPass( void ) const;
    GEFloat                        GetScaleFactor( void ) const;
    GEBool                         GetUseCellifier( void ) const;
    void                           GetWorld( gCWorld * & ) const;
    GEBool                         ImportFile( bCString );
    void                           SetAmbientOcclusionShadowSoftnes( GEFloat );
    void                           SetDynamicLayer( gCDynamicLayer * );
    void                           SetImagePath( bCString );
    void                           SetMaterialPath( bCString );
    void                           SetMeshConvertCallback( iFMeshConvertCallback );
    void                           SetMeshPath( bCString );
    void                           SetScaleFactor( GEFloat );
    void                           SetWorld( gCWorld * );
public:
    iCImporterAdmin & operator = ( iCImporterAdmin const & );
public:
    iCImporterAdmin( iCImporterAdmin const & );
    iCImporterAdmin( void );
};
GE_ASSERT_SIZEOF( iCImporterAdmin, 0x0054 )

#pragma warning( pop )

#endif
