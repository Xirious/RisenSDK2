#ifndef GS_PSDOOR_H_INCLUDED
#define GS_PSDOOR_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSDoor, gCDoor_PS )
public:
    GS_DECLARE_PROPERTY( Status, gEDoorStatus )
public:
    GEBool IsValid( void ) const;
};

#endif
