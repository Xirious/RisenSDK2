#ifndef GS_INFCOMSETSECTORSTATUS_H_INCLUDED
#define GS_INFCOMSETSECTORSTATUS_H_INCLUDED

GS_DECLARE_INFCOM( InfComSetSectorStatus, gCInfoCommandSetSectorStatus )
public:
    GEBool   GetSectorEnabled( void );
    bCString GetSectorName( void );
};

#endif
