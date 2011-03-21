#ifndef GS_EFFECTSYSTEM_H_INCLUDED
#define GS_EFFECTSYSTEM_H_INCLUDED

class GE_DLLIMPORT EffectSystem
{
public:
    static GEBool GE_STDCALL ExistsEffect( bCString const & );
    static Effect GE_STDCALL StartEffect( bCString const &, Entity const &, Entity const & );
    static Effect GE_STDCALL StartEffect( bCString const &, Entity const & );
    static Effect GE_STDCALL StartEffect( bCString const &, bCMatrix const & );
    static Effect GE_STDCALL StartEffect( bCString const &, bCMatrix const &, Entity const & );
    static Effect GE_STDCALL StartEffect( bCString const &, bCVector const & );
    static Effect GE_STDCALL StartEffect( bCString const &, bCVector const &, Entity const & );
    static GEBool GE_STDCALL StartImageEffect( bCString const &, GEFloat, GEFloat, GEFloat );
    static GEBool GE_STDCALL StopEffect( Effect const &, GEBool );
    static GEBool GE_STDCALL StopImageEffect( void );
};

#endif
