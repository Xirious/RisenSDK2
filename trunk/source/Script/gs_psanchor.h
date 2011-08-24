#ifndef GS_PSANCHOR_H_INCLUDED
#define GS_PSANCHOR_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSAnchor, gCAnchor_PS )
public:
    GS_DECLARE_PROPERTY( AnchorType,  gEAnchorType )
    GS_DECLARE_PROPERTY( PatrolIndex, GEU32 )
public:
    bTObjArray< Entity > GetInteractPoints( GEBool ) const;
    GEInt                GetMaxUserCount( void ) const;
    GEInt                GetUserCount( void ) const;
    GEBool               IsValid( void ) const;
};

#endif
