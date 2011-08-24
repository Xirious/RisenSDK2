#ifndef GS_PSCASTINFO_H_INCLUDED
#define GS_PSCASTINFO_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSCastInfo, gCCastInfo_PS )
public:
    GS_DECLARE_PROPERTY( CastAmmo,    Template )
    GS_DECLARE_PROPERTY( CastFail,    Template )
    GS_DECLARE_PROPERTY( CastInfo,    bCString )
    GS_DECLARE_PROPERTY( CastItem,    Template )
    GS_DECLARE_PROPERTY( ConsumeItem, GEBool )
    GS_DECLARE_PROPERTY( FocusMode,   bCString )
    GS_DECLARE_PROPERTY( ManaCost,    GEInt )
    GS_DECLARE_PROPERTY( StartTask,   bCString )
public:
    GEBool CanCast( Entity & ) const;
    GEBool Consume( Entity &, GEInt );
    GEInt  GetAmmoStack( Entity & );
    GEInt  GetCastStack( Entity & );
    GEInt  GetFailStack( Entity & );
    GEBool HoldCastItem( Entity & );
    GEBool IsValid( void ) const;
};

#endif
