#ifndef GS_INFCOMSAYSOUND_H_INCLUDED
#define GS_INFCOMSAYSOUND_H_INCLUDED

class GE_DLLIMPORT InfComSaySound
{
public: virtual ~InfComSaySound( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    bCString GetSoundName( void );
    Entity   GetSpeaker( void );
    void     SetCommand( gCInfoCommand * );
public:
    InfComSaySound & operator = ( InfComSaySound const & );
public:
    InfComSaySound( InfComSaySound const & );
    InfComSaySound( void );
};
GE_ASSERT_SIZEOF( InfComSaySound, 0x0008 )

#endif
