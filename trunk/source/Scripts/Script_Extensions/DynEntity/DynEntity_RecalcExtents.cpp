#include "DynEntity_RecalcExtents.h"

bCUnicodeString CON_DynEntity::RecalcExtents( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCMesh_PS * MeshPropertySet = dynamic_cast< eCMesh_PS * >( pEntity->GetPropertySet( "eCMesh_PS" ) );
    if ( !MeshPropertySet )
        return L"$" + pEntity->GetName().GetUnicodeText() + L" has no eCMesh_PS.";

    eCArchiveManager & ArchiveManager = eCArchiveManager::GetInstance();
    eCArchiveFile File = ArchiveManager.GetFile( MeshPropertySet->GetMeshFileName() );
    File.Open( eCArchiveFile::bEArchiveFileAccessMode_Read, false );

    bCBox NewBoundingBox;
    NewBoundingBox.Invalidate();

    File.Seek( 127, bEStreamSeekMode_Begin );
    GEU32 SubMeshCount;
    File.Read( SubMeshCount );
    GEU32 NextOffset = 133;
    for ( GEU32 i = 0; i != SubMeshCount; ++i )
    {
        GEU32 TmpInt;
        bCBox TmpBoundingBox;
        File.Seek( NextOffset, bEStreamSeekMode_Begin );
        File.Read( TmpInt );
        NextOffset += ( TmpInt + 6 );
        File.Seek( 32, bEStreamSeekMode_Current );
        File.Read( TmpInt );
        File.Seek( ( TmpInt + 22 ), bEStreamSeekMode_Current );
        TmpBoundingBox << File;
        NewBoundingBox.Merge( TmpBoundingBox );
    }
    File.Close();

    NewBoundingBox.Widen( 10.0 );
    pEntity->SetWorldNodeBoundary( NewBoundingBox );
    pEntity->SetLocalNodeBoundary( NewBoundingBox );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return L"Recalculated extents of " + pEntity->GetName().GetUnicodeText() + L".";
}