#ifndef GS_INFCOMSAYSOUND_H_INCLUDED
#define GS_INFCOMSAYSOUND_H_INCLUDED

GS_DECLARE_INFCOM( InfComSaySound, gCInfoCommandSaySound )
public:
    bCString GetSoundName( void );
    Entity   GetSpeaker( void );
};

#endif
