#ifndef GE_LOCKSYSTEM_H_INCLUDED
#define GE_LOCKSYSTEM_H_INCLUDED

class GE_DLLIMPORT bCLockSystem
{
private:
    bCLockSystem const & operator = ( bCLockSystem const & );  // not defined
    bCLockSystem( bCLockSystem const & );                      // not defined
protected:
    bCCriticalSection & m_CriticalSection;
public:
    GEU32 GetLockCount( void ) const;
public:
    bCLockSystem( bCCriticalSection & a_CriticalSection );
   ~bCLockSystem( void );
};

#endif
