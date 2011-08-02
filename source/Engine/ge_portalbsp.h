#ifndef GE_PORTALBSP_H_INCLUDED
#define GE_PORTALBSP_H_INCLUDED

class GE_DLLIMPORT eCPortalBSP
{
public:
    struct eSPortalRect
    {
        bCVector          m_arrPoints[ 4 ];  // 0000
        bCVector          m_vecNormal;       // 0030
    };
    GE_ASSERT_SIZEOF( eSPortalRect, 0x003C )
protected:
    struct eSBSPPolygon //FIXME: Proper structure name.
    {
        bCPlane  m_plPlane;             // 0000
        bCVector m_arrPoints[ 9 ];      // 0010
        GEU32    m_u32ValidPointCount;  // 007C
    };
    GE_ASSERT_SIZEOF( eSBSPPolygon, 0x0080 )
protected:
    eCPortalBSP *              m_pChild1;      // 0000
    eCPortalBSP *              m_pChild2;      // 0004
    bCPlane                    m_plPlane;      // 0008
    GEBool                     m_bIsLeaf;      // 0018
                               GE_PADDING( 3 );
    bCSphere                   m_sphSphere;    // 001C
    bTObjArray< eSBSPPolygon > m_arrElements;  // 002C
};
GE_ASSERT_SIZEOF( eCPortalBSP, 0x0038 )

#endif