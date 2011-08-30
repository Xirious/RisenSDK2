#ifndef GS_INFCOMUSE_H_INCLUDED
#define GS_INFCOMUSE_H_INCLUDED

GS_DECLARE_INFCOM( InfComUse, gCInfoCommandUse )
public:
    Entity   GetEntity1( void );
    Template GetItem( void );
    bCString GetUseAnimationName( void );
};

#endif
