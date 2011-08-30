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
private:
    Focus( void );           // hide constructor
    Focus( Focus const & );  // hide copy constructor
   ~Focus( void );           // hide destructor
private:
    Focus & operator = ( Focus const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC Focus focus;

#endif
