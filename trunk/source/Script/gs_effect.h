#ifndef GS_EFFECT_H_INCLUDED
#define GS_EFFECT_H_INCLUDED

class GE_DLLIMPORT Effect
{
protected:
    gCEffect * m_pEffect;
public:
    Effect & operator = ( Effect const & );
private:
    Effect( Effect const & );
    Effect( gCEffect * = 0 );
private:
    operator gCEffect * ( void ) const;
};
GE_ASSERT_SIZEOF( Effect, 0x0004 )

#endif
