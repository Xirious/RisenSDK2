#ifndef M_PLACEMENTADMIN_H_INCLUDED
#define M_PLACEMENTADMIN_H_INCLUDED

#include "Game.h"

#pragma warning( push )
#pragma warning( disable : 4820 )  // padding added after data member

class mCPlacementAdmin
{
public:
    static mCPlacementAdmin & GetInstance( void );
public:
    void             AlignLocalTranslation( GEFloat a_fGridSpacing );
    void             AttachSecondarySelection( GEBool a_bPreserveTransform );
    void             ApplyPendingTransform( void );
    void             ClearSelection( void );
    void             DeleteSecondarySelection( void );
    void             DetachClone( void );
    void             DetachEntity( void );
    void             Disable( void );
    void             EditSelection( void );
    void             Enable( void );
    void             GetActiveTransformAxes( GEInt & a_iPrimaryAxis, GEInt & a_iSecondaryAxis );
    bCMatrix const & GetCameraTransform( void ) const;
    bCMatrix const & GetTransformationSpace( void ) const;
    GEBool           IsEnabled( void ) const;
    GEBool           IsEntityAttached( void ) const;
    GEBool           IsInPickMode( void ) const;
    GEBool           IsInSpawnMode( void ) const;
    void             LockSelection( void );
    void             Move( bCVector a_vecOffset );
    void             OnFilterChanged( void );
    void             OnProcess( void );
    void             OnRender( void );
    void             PickLayer( void );
    void             ResetPendingTransform( void );
    void             ResetRotation( void );
    void             ResetTransform( void );
    void             ResetTranslation( void );
    void             RestoreOldTransform( void );
    void             Rotate( GEFloat a_fAngle );
    void             SelectEntity( void );
    void             SelectNext( GEBool a_bReverse );
    void             SetActiveTransformAxes( GEInt a_iPrimaryAxis, GEInt a_iSecondaryAxis );
    void             SetSecondarySelectionActive( GEBool a_bActive );
    void             SpawnSelectedTemplate( GEBool a_bRandomYRotation );
    void             ToggleLocalSpaceCameraSpace( void );
    void             TogglePickSpawn( void );
    void             ToggleRenderMode( void );
    void             ToggleTraceFree( void );
    void             ToggleStaticColLevelCol( void );
    void             UndeleteEntity( void );
private:
    enum EColor
    {
        EColor_Default = 0xFFFFFFFF,
        EColor_Red     = 0xFFFF3F3F,
        EColor_Green   = 0xFF22FF22,
        EColor_Blue    = 0xFF7FAFFF
    };
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    public:
        CProcessor( mCPlacementAdmin * a_pPlacementAdmin );
    protected:
        mCPlacementAdmin * m_pPlacementAdmin;
    };
    struct SDeletedEntity
    {
        bCMemoryStream m_streamData;
        bCPropertyID   m_ParentID;
    };
    typedef bTObjArray< eCEntityProxy > CEntityArray;
private:
    mCPlacementAdmin( mCPlacementAdmin const & );
    mCPlacementAdmin( void );
   ~mCPlacementAdmin( void );
private:
    mCPlacementAdmin & operator = ( mCPlacementAdmin const & );
private:
    static void               BuildEntityArray( CEntityArray & a_arrEntities, bCVector a_vecPosition );
    static void               BuildTemplateArray( CEntityArray & a_arrEntities );
    static eCDynamicEntity *  GetCurrentEntity( void );
    static gCDynamicLayer *   GetCurrentLayer( void );
    static eCTemplateEntity * GetCurrentTemplate( void );
    static GEBool             SelectNextEntityOnScreen( CEntityArray const & a_arrEntities, GEInt & a_iIndex, GEBool a_bBackwards );
    static void               SetCurrentEntity( eCDynamicEntity const * a_pEntity );
    static void               SetCurrentLayer( gCDynamicLayer const * a_pLayer );
    static void               SetCurrentTemplate( eCTemplateEntity const * a_pTemplate );
private:
    void               AttachSelection( GEBool a_bAttached );
    void               DecomposeWorldTransform( void );
    void               DeleteEntity( eCDynamicEntity * a_pEntity, GEBool a_bUndeleteEnabled );
    eCDynamicEntity *  GetSelection( void );
    eCDynamicEntity *  GetSecondarySelection( void );
    eCTemplateEntity * GetTemplate( void );
    void               RenderCross( EColor a_enuColor );
    void               RenderGizmo( void );
    void               SetHighlightedEntity( eCDynamicEntity * a_pEntity );
    eCDynamicEntity *  SpawnTemplate( eCTemplateEntity const * a_pTemplate, gCDynamicLayer * a_pLayer );
    void               UpdateTarget( void );
    void               UpdateWorldTransform( void );
private:
    static mCPlacementAdmin * s_pInstance;
private:
    CProcessor     m_Processor;
    bCVector       m_vecTarget;
    bCMatrix       m_matCameraTransform;
    bCMatrix       m_matCameraTransformAdjusted;
    bCMatrix       m_matLocalTransform;
    bCMatrix       m_matLocalTransformBase;
    bCMatrix       m_matWorldTransform;
    bCMatrix       m_matWorldTransformOld;
    SDeletedEntity m_arrDeletedEntities[ 20 ];
    CEntityArray   m_arrSelectionBuffer;
    CEntityArray   m_arrSecondarySelectionBuffer;
    CEntityArray   m_arrTemplates;
    GEInt          m_iSelection;
    GEInt          m_iSecondarySelection;
    GEInt          m_iTemplate;
    GEInt          m_iPrimaryTransformAxis;
    GEInt          m_iSecondaryTransformAxis;
    GEBool         m_bEnabled;
    GEBool         m_bSpawnMode;
    GEBool         m_bEntityAttached;
    GEBool         m_bLevelColTraceMode;
    GEBool         m_bFreeMode;
    GEBool         m_bCameraSpace;
    GEBool         m_bRenderBoundingBoxes;
    GEBool         m_bHighlightSelection;
    GEBool         m_bSecondarySelectionActive;
    GEBool         m_bOriginalEntityAttached;
};

#pragma warning( pop )

#endif