#ifndef GS_INFCOMSAYSVM_H_INCLUDED
#define GS_INFCOMSAYSVM_H_INCLUDED

GS_DECLARE_INFCOM( InfComSaySVM, gCInfoCommandSaySVM )
public:
    gEInfoGesture GetGesture( void );
    Entity        GetListener( void );
    bCString      GetSVMID( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
};

#endif
