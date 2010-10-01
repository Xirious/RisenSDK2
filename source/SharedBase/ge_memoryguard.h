#ifndef GE_MEMORYGUARD_H_INCLUDED
#define GE_MEMORYGUARD_H_INCLUDED

class GE_DLLIMPORT bCMemoryGuard
{
private:
    bEMemorySubSystem m_enuMemorySubSystem;
    GEBool            m_bPopMemorySubSystem;
                      GE_PADDING( 3 )
public:
    bEMemorySubSystem GetMemorySubSystem( void ) const;
public:
    bCMemoryGuard & operator = ( bCMemoryGuard const & );
public:
    bCMemoryGuard( bEMemorySubSystem );
   ~bCMemoryGuard( void );
};

#endif
