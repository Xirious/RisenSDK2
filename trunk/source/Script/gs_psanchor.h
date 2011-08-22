#ifndef GS_PSANCHOR_H_INCLUDED
#define GS_PSANCHOR_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSAnchor )
public:
    using Entity::Property;
    GS_DECLARE_PROPERTY( AnchorType,  gEAnchorType )
    GS_DECLARE_PROPERTY( PatrolIndex, GEU32 )
public:
    bTObjArray< Entity > GetInteractPoints( GEBool ) const;
    GEInt                GetMaxUserCount( void ) const;
    GEInt                GetUserCount( void ) const;
    GEBool               IsValid( void ) const;
protected:
                  operator gCAnchor_PS *       ( void );
                  operator gCAnchor_PS const * ( void ) const;
    gCAnchor_PS * operator ->                  ( void );
public:
    gCAnchor_PS const * operator -> ( void ) const;
};

#endif
