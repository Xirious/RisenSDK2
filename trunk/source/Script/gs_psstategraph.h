#ifndef GS_PSSTATEGRAPH_H_INCLUDED
#define GS_PSSTATEGRAPH_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSStateGraph, gCStateGraph_PS )
public:
    GEBool CanGoToState( bCString const & );
    GEBool ClearPath( void );
    GEBool GoToState( bCString const &, GEBool );
    GEBool IsInState( bCString const & );
    GEBool IsValid( void ) const;
};

#endif
