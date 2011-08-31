#ifndef GS_PSMOVER_H_INCLUDED
#define GS_PSMOVER_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSMover, eCMover_PS )
public:
    GEBool IsValid( void ) const;
    GEBool PauseAnimation( bCString, GEBool );
    GEBool StartAnimation( bCString );
    void   StopAll( void );
    GEBool StopAnimation( bCString );
};

#endif
