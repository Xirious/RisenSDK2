#ifndef GE_STATEGRAPHTRANSITION_H_INCLUDED
#define GE_STATEGRAPHTRANSITION_H_INCLUDED

class GE_DLLIMPORT gCStateGraphTransition
{
public: virtual ~gCStateGraphTransition( void );
protected:
    gCStateGraphState * m_pOwner;
    bCString            m_strTargetStateName;
    gCStateGraphState * m_pTargetState;
public:
    gCStateGraphTransition( void );
    gCStateGraphTransition( gCStateGraphTransition const & );
public:
    gCStateGraphTransition & operator = ( gCStateGraphTransition const & );
public:
    void                Create( void );
    gCStateGraphState * GetOwner( void ) const;
    gCStateGraphState * GetTargetState( void ) const;
    void                Read( bCIStream & );
    void                SetOwner( gCStateGraphState * );
    void                SetTargetState( gCStateGraphState * );
    void                Write( bCOStream & );
protected:
    void Destroy( void );
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphTransition, 0x0010 )

#endif
