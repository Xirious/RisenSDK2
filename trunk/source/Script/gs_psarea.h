#ifndef GS_PSAREA_H_INCLUDED
#define GS_PSAREA_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSArea, eCArea_StringProperty_PS )
public:
    GEBool HasProperty( bCString ) const;
    GEBool IsValid( void ) const;
};


#endif
