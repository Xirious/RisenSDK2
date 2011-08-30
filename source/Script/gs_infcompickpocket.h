#ifndef GS_INFCOMPICKPOCKET_H_INCLUDED
#define GS_INFCOMPICKPOCKET_H_INCLUDED

GS_DECLARE_INFCOM( InfComPickPocket, gCInfoCommandPickPocket )
public:
    GEU32         GetDifficulty( void );
    gEInfoGesture GetGesture( void );
    Entity        GetListener( void );
    bCString      GetSVMID( void );
    bCString      GetSVMTextID( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
};

#endif
