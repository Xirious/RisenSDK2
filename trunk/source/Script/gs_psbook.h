#ifndef GS_PSBOOK_H_INCLUDED
#define GS_PSBOOK_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSBook )
public:
    GEBool IsValid( void ) const;
protected:
                operator gCBook_PS *       ( void );
                operator gCBook_PS const * ( void ) const;
    gCBook_PS * operator ->                ( void );
public:
    gCBook_PS const * operator -> ( void ) const;
};

#endif
