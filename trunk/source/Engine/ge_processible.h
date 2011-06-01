#ifndef GE_PROCESSIBLE_H_INCLUDED
#define GE_PROCESSIBLE_H_INCLUDED

class eIProcessible
{
public: virtual GEU8  GetProcessingIndex( void ) const = 0;  
public: virtual GEU32 GetAppStateFlags( void ) const   = 0;  
public: virtual void  OnProcess( void )                = 0;  
};
GE_ASSERT_SIZEOF( eIProcessible, 0x0004 )

class GE_DLLIMPORT eCProcessible :
    public eIProcessible
{
public: virtual             ~eCProcessible( void );  
public: virtual void         OnProcess( void );      
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
