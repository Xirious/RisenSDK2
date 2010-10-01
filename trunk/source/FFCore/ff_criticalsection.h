#ifndef FF_CRITICALSECTION_H_INCLUDED
#define FF_CRITICALSECTION_H_INCLUDED

class FF_DLLIMPORT CFFCriticalSection
{
private:
    /* 0000 */ SFFCriticalSection m_CriticalSection;
    // 0018 // sizeof(CFFCriticalSection)
private:
    void Create( void );
    void Destroy( void );
public:
    GEBool Lock( void );
    GEBool Unlock( void );
public:
    CFFCriticalSection & operator = ( CFFCriticalSection const & a_Source );
public:
    CFFCriticalSection( void );
   ~CFFCriticalSection( void );
};

#endif
