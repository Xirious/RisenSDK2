#ifndef GS_INFCOMSAYCONFIRM_H_INCLUDED
#define GS_INFCOMSAYCONFIRM_H_INCLUDED

GS_DECLARE_INFCOM( InfComSayConfirm, gCInfoCommandSayConfirm )
public:
    Entity GetListener( void );
    Entity GetSpeaker( void );
};

#endif
