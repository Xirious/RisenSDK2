#ifndef GS_PSSTRIP_H_INCLUDED
#define GS_PSSTRIP_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSStrip, eCStrip_PS )
public:
    GS_DECLARE_PROPERTY( Enabled, GEBool )
public:
    GEBool IsValid( void ) const;
};

#endif
