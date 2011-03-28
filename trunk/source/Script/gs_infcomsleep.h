#ifndef GS_INFCOMSLEEP_H_INCLUDED
#define GS_INFCOMSLEEP_H_INCLUDED

class GE_DLLIMPORT InfComSleep
{
public: virtual ~InfComSleep( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity GetEntity1( void );
    GEU32  GetTargetHour( void );
    void   SetCommand( gCInfoCommand * );
public:
    InfComSleep & operator = ( InfComSleep const & );
public:
    InfComSleep( InfComSleep const & );
    InfComSleep( void );
};
GE_ASSERT_SIZEOF( InfComSleep, 0x0008 )

#endif
