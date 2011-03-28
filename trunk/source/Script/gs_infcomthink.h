#ifndef GS_INFCOMTHINK_H_INCLUDED
#define GS_INFCOMTHINK_H_INCLUDED

class GE_DLLIMPORT InfComThink
{
public: virtual ~InfComThink( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    gEInfoGesture GetGesture( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
    void          SetCommand( gCInfoCommand * );
public:
    InfComThink & operator = ( InfComThink const & );
public:
    InfComThink( InfComThink const & );
    InfComThink( void );
};
GE_ASSERT_SIZEOF( InfComThink, 0x0008 )

#endif
