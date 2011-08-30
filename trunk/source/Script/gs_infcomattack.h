#ifndef GS_INFCOMATTACK_H_INCLUDED
#define GS_INFCOMATTACK_H_INCLUDED

GS_DECLARE_INFCOM( InfComAttack, gCInfoCommandAttack )
public:
    Entity   GetEntity1( void );
    Entity   GetEntity2( void );
    bCString GetReason( void );
};

#endif
