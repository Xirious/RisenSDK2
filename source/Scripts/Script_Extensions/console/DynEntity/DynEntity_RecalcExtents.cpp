#include "DynEntity_RecalcExtents.h"
#include "../../m_hacks.h"

bCUnicodeString CON_DynEntity_Sub::RecalcExtents( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCMesh_PS * pMeshPS = dynamic_cast< eCMesh_PS * >( pEntity->GetPropertySet( "eCMesh_PS" ) );
    if ( !pMeshPS )
        return L"$" + pEntity->GetName().GetUnicodeText() + L" has no Mesh property set.";

    eCArchiveManager & ArchiveManager = eCArchiveManager::GetInstance();
    eCArchiveFile File = ArchiveManager.GetFile( pMeshPS->GetMeshFileName() );
    File.Open( eCArchiveFile::bEArchiveFileAccessMode_Read, GEFalse );

    bCBox boxBoundaryNew;
    boxBoundaryNew.Invalidate();

    File.Seek( 127, bEStreamSeekMode_Begin );
    GEU32 SubMeshCount;
    File.Read( SubMeshCount );
    GEU32 u32NextOffset = 133;
    for ( GEU32 i = 0; i != SubMeshCount; ++i )
    {
        GEU32 u32Temp;
        bCBox boxBoundaryPart;
        File.Seek( u32NextOffset, bEStreamSeekMode_Begin );
        File.Read( u32Temp );
        u32NextOffset += ( u32Temp + 6 );
        File.Seek( 32, bEStreamSeekMode_Current );
        File.Read( u32Temp );
        File.Seek( ( u32Temp + 22 ), bEStreamSeekMode_Current );
        boxBoundaryPart << File;
        boxBoundaryNew.Merge( boxBoundaryPart );
    }
    File.Close();

    boxBoundaryNew.Widen( 10.0 );
    pEntity->SetLocalNodeBoundary( boxBoundaryNew );

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return L"Recalculated the extents of " + pEntity->GetName().GetUnicodeText() + L".";
}