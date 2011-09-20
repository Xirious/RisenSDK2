#ifndef GE_STATEGRAPHACTIONFOLLOWSTATE_H_INCLUDED
#define GE_STATEGRAPHACTIONFOLLOWSTATE_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionFollowState :
    public gCStateGraphAction
{
public:    virtual gCStateGraphState * GetFollowState( void ) const;
public:    virtual void                SetFollowState( gCStateGraphState const * );
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionFollowState, gCStateGraphAction )
public:    virtual bEResult            Create( void );
protected: virtual void                Destroy( void );
public:    virtual                    ~gCStateGraphActionFollowState( void );
public:    virtual void                GetDescription( bCString & ) const;
public:    virtual void                GetActionDescription( bCString & ) const;
public:    virtual void                OnStateFinished( void );
public:    virtual void                OnEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( GEBool, m_bInteruptCurrentState, InteruptCurrentState )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCString, m_strFollowStateName, FollowStateName )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionFollowState, 0x002C )

#endif
