#ifndef GS_INFCOMSAY_H_INCLUDED
#define GS_INFCOMSAY_H_INCLUDED

class GE_DLLIMPORT InfComSay
{
public: virtual ~InfComSay( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    gEInfoGesture GetGesture( void );
    Entity        GetListener( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
    void          SetCommand( gCInfoCommand * );
public:
    InfComSay & operator = ( InfComSay const & );
public:
    InfComSay( InfComSay const & );
    InfComSay( void );
};
GE_ASSERT_SIZEOF( InfComSay, 0x0008 )

#endif
