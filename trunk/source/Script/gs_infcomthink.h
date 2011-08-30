#ifndef GS_INFCOMTHINK_H_INCLUDED
#define GS_INFCOMTHINK_H_INCLUDED

GS_DECLARE_INFCOM( InfComThink, gCInfoCommandThink )
public:
    gEInfoGesture GetGesture( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
};

#endif
