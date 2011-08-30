#ifndef GS_INFCOMSAY_H_INCLUDED
#define GS_INFCOMSAY_H_INCLUDED

GS_DECLARE_INFCOM( InfComSay, gCInfoCommandSay )
public:
    gEInfoGesture GetGesture( void );
    Entity        GetListener( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
};

#endif
