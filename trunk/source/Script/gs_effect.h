#ifndef GS_EFFECT_H_INCLUDED
#define GS_EFFECT_H_INCLUDED

class GE_DLLIMPORT Effect
{
protected:
    gCEffect * m_pEffect;
private:
    operator gCEffect * ( void ) const;
public:
    Effect & operator = ( Effect const & );
private:
    Effect( Effect const & );
    Effect( gCEffect * = 0 );
};

// FX is not used in the original game.
// Because Effect is not constructable,
// this export might be used to assign
// the returned object of EffectSystem
// functions.
// However, the name suggest that FX’s
// original type could be EffectSystem.
GE_DLLIMPORT_EXTC Effect FX;

#endif
