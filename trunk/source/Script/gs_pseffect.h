#ifndef GS_PSEFFECT_H_INCLUDED
#define GS_PSEFFECT_H_IMCLUDED

GS_DECLARE_PROPERTYSET( PSEffect, gCEffect_PS )
public:
    GS_DECLARE_PROPERTY( Enabled, GEBool )
public:
    GEBool IsRuntimeEffectStarted( bCString const & );
    GEBool IsValid( void ) const;
    void   Start( void );
    GEBool StartEffect( bCString const &, GEBool );
    GEBool StartRuntimeEffect( bCString const & );
    void   Stop( void );
    GEBool StopAllRuntimeEffects( GEBool );
    void   StopEffect( GEBool );
    GEBool StopRuntimeEffect( bCString const &, GEBool );
};

#endif
