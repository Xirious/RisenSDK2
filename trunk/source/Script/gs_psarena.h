#ifndef GS_PSARENA_H_INCLUDED
#define GS_PSARENA_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSArena )
public:
    using Entity::Property;
    GS_DECLARE_PROPERTY( Status, gEArenaStatus )
public:
    GEBool IsValid( void ) const;
protected:
                 operator gCArena_PS *       ( void );
                 operator gCArena_PS const * ( void ) const;
    gCArena_PS * operator ->                 ( void );
public:
    gCArena_PS const * operator -> ( void ) const;
};

#endif
