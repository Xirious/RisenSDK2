#include "m_gizmotranslate.h"

mCGizmoTranslate::mCGizmoTranslate( void )
{
    m_arrIteratorPrimitives.RemoveAt( 0 );
    m_arrIteratorPrimitives.SetCount( 6 );
}

mCGizmoTranslate & mCGizmoTranslate::GetInstance( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )
    static mCGizmoTranslate * s_pInstance = new mCGizmoTranslate;
#pragma warning( pop )
    return *s_pInstance;
}

void mCGizmoTranslate::RenderOnEntity( eCGeometryEntity * a_pEntity, GEFloat a_fScaling, bCQuaternion const * a_pRotation, GEBool a_bAxisHighlighted[ 3 ] )
{
    if ( !a_pEntity )
        return;
    mCGizmoTranslate & Instance = GetInstance();
    bCMatrix matGizmo;
    a_pEntity->GetGizmoTrafoSpaceWorldMatrix( &eCApplication::GetInstance().GetCurrentCamera(), matGizmo );
    matGizmo.Scale( a_fScaling );
    if ( a_pRotation )
    {
        bCVector vecTranslation = matGizmo.GetTranslation();
        matGizmo *= bCMatrix( bCQuaternion( matGizmo.GetPureRotation() ).GetInverted() * *a_pRotation, bCVector() );
        matGizmo.AccessTranslation() = vecTranslation;
    }
    bTValArray< GEU32 > arrColors( Instance.m_arrIteratorPrimitives.GetCount() );
    for ( GEInt i = 0, ie = Instance.m_arrIteratorPrimitives.GetCount(); i != ie; ++i )
    {
        GEU32 & u32Color = reinterpret_cast< GEU32 * >( Instance.m_arrIteratorPrimitives[ i ] )[ 4 ];
        arrColors.Add( u32Color );
        for ( GEInt j = 0; j != 32; j += 8 )
        {
            u32Color |= ( u32Color & ( 0xFF << j ) ) ? ( 0xFF << j ) : ( 0x3F << j );
            if ( !a_bAxisHighlighted[ i / 2 ] )
                u32Color &= ~( 0x1F << j );
        }
    }
    Instance.Render( matGizmo );
    for ( GEInt i = 0, ie = Instance.m_arrIteratorPrimitives.GetCount(); i != ie; ++i )
        reinterpret_cast< GEU32 * >( Instance.m_arrIteratorPrimitives[ i ] )[ 4 ] = arrColors[ i ];
}