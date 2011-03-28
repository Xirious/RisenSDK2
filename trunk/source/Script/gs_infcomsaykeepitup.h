#ifndef GS_INFCOMSAYKEEPITUP_H_INCLUDED
#define GS_INFCOMSAYKEEPITUP_H_INCLUDED

class GE_DLLIMPORT InfComSayKeepItUp
{
public: virtual ~InfComSayKeepItUp( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity GetListener( void );
    Entity GetSpeaker( void );
    void   SetCommand( gCInfoCommand * );
public:
    InfComSayKeepItUp & operator = ( InfComSayKeepItUp const & );
public:
    InfComSayKeepItUp( InfComSayKeepItUp const & );
    InfComSayKeepItUp( void );
};
GE_ASSERT_SIZEOF( InfComSayKeepItUp, 0x0008 )

#endif
