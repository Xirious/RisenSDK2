#ifndef GS_INFCOMSAYHOLDINGPOSITION_H_INCLUDED
#define GS_INFCOMSAYHOLDINGPOSITION_H_INCLUDED

GS_DECLARE_INFCOM( InfComSayHoldingPosition, gCInfoCommandSayHoldingPosition )
public:
    Entity GetListener( void );
    Entity GetSpeaker( void );
};

#endif
