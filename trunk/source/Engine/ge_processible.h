#ifndef GE_PROCESSIBLE_H_INCLUDED
#define GE_PROCESSIBLE_H_INCLUDED

class eIProcessible
{
public: virtual GEU8  GetProcessingIndex( void ) const = 0;  // [0000].0000
public: virtual GEU32 GetAppStateFlags( void ) const   = 0;  // [0000].0004
public: virtual void  OnProcess( void )                = 0;  // [0000].0008
};
GE_ASSERT_SIZEOF( eIProcessible, 0x0004 )

class GE_DLLIMPORT eCProcessible :
    public eIProcessible
{
public: using eIProcessible::GetProcessingIndex;     // [0000].0000
public: using eIProcessible::GetAppStateFlags;       // [0000].0004
public: virtual void         OnProcess( void );      // [0000].0008
public: virtual             ~eCProcessible( void );  // [0000].000C
protected:
    eCProcessible * m_pNext;  // 0004
    eCProcessible * m_pPrev;  // 0008
public:
    eCProcessible & operator = ( eCProcessible const & );
public:
    eCProcessible( eCProcessible const & );
    eCProcessible( void );
};
GE_ASSERT_SIZEOF( eCProcessible, 0x000C )

#endif
