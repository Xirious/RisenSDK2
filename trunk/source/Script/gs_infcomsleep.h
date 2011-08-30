#ifndef GS_INFCOMSLEEP_H_INCLUDED
#define GS_INFCOMSLEEP_H_INCLUDED

GS_DECLARE_INFCOM( InfComSleep, gCInfoCommandSleep )
public:
    Entity GetEntity1( void );
    GEU32  GetTargetHour( void );
};

#endif
