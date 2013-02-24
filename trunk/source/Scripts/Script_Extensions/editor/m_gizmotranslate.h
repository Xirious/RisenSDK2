#ifndef M_GIZMOTRANSLATE_H_INCLUDED
#define M_GIZMOTRANSLATE_H_INCLUDED

#include "Engine.h"

class mCGizmoTranslate : 
    public eCGizmoTranslateAndScale
{
public:
    mCGizmoTranslate( void );
public:
    static mCGizmoTranslate & GetInstance( void );
    static void               RenderOnEntity( eCGeometryEntity * a_pEntity, GEFloat a_fScaling, bCQuaternion const * a_pRotation, GEBool a_bAxisHighlighted[ 3 ] );
};

#endif