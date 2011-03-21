#ifndef GS_FOCUS_H_INCLUDED
#define GS_FOCUS_H_INCLUDED

class GE_DLLIMPORT Focus
{
protected:
    bCMatrix m_matOffsetPose;
public:
    void     ClearOffsetPose( void );
    void     EnableAutoRefresh( GEBool );
    Entity   GetFocusEntity( void ) const;
    bCString GetFocusMode( void ) const;
    bCMatrix GetOffsetPose( void ) const;
    GEBool   GetTargetPoint( bCVector & ) const;
    GEBool   IsAutoRefreshEnabled( void ) const;
    Entity   RefreshFocusEntity( gEDirection );
    Entity   RefreshFocusEntity( void );
    bCVector RefreshFocusPoint( void );
    void     SetFocusEntity( Entity );
    void     SetFocusMode( bCString );
    void     SetOffsetPose( bCMatrix const & );

public:
    Focus & operator = ( Focus const & );
public:
    Focus( Focus const & );
    Focus( void );
   ~Focus( void );
};

GE_C_LINKAGE GE_DLLIMPORT Focus focus;

#endif
