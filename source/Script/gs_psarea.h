#ifndef GS_PSAREA_H_INCLUDED
#define GS_PSAREA_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSArea )
public:
    GEBool HasProperty( bCString ) const;
    GEBool IsValid( void ) const;
protected:
                               operator eCArea_StringProperty_PS *       ( void );
                               operator eCArea_StringProperty_PS const * ( void ) const;
    eCArea_StringProperty_PS * operator -> ( void );
public:
    eCArea_StringProperty_PS const * operator -> ( void ) const;
};


#endif
