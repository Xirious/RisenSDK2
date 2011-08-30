#ifndef GS_INFCOMSAYKEEPITUP_H_INCLUDED
#define GS_INFCOMSAYKEEPITUP_H_INCLUDED

GS_DECLARE_INFCOM( InfComSayKeepItUp, gCInfoCommandSayKeepItUp )
public:
    Entity GetListener( void );
    Entity GetSpeaker( void );
};

#endif
