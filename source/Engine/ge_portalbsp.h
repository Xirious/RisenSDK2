#ifndef GE_PORTALBSP_H_INCLUDED
#define GE_PORTALBSP_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'eCPortalBSP'

class GE_DLLIMPORT eCPortalBSP
{
public:
    struct eSPortalRect
    {
        bCVector m_arrPoints[ 4 ];
        bCVector m_vecNormal;
    };
    GE_ASSERT_SIZEOF( eSPortalRect, 0x003C )
protected:
    //FIXME: eSBSPPolygon name.
    struct eSBSPPolygon
    {
        bCPlane  m_plPlane;
        bCVector m_arrPoints[ 9 ];
        GEU32    m_u32ValidPointCount;
    };
    GE_ASSERT_SIZEOF( eSBSPPolygon, 0x0080 )
protected:
    eCPortalBSP *              m_pChild1;
    eCPortalBSP *              m_pChild2;
    bCPlane                    m_plPlane;
    GEBool                     m_bIsLeaf;
                               GE_PADDING( 3 );
    bCSphere                   m_sphSphere;
    bTObjArray< eSBSPPolygon > m_arrElements;
};
GE_ASSERT_SIZEOF( eCPortalBSP, 0x0038 )

#pragma warning( pop )

#endif