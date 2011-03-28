#ifndef GS_INFCOMINFOWAIT_H_INCLUDED
#define GS_INFCOMINFOWAIT_H_INCLUDED

class GE_DLLIMPORT InfComInfoWait
{
public: virtual ~InfComInfoWait( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    GEU32 GetTime( void );
    void  SetCommand( gCInfoCommand * );
public:
    InfComInfoWait & operator = ( InfComInfoWait const & );
public:
    InfComInfoWait( InfComInfoWait const & );
    InfComInfoWait( void );
};
GE_ASSERT_SIZEOF( InfComInfoWait, 0x0008 )

#endif
