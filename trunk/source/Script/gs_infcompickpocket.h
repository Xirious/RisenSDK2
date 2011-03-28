#ifndef GS_INFCOMPICKPOCKET_H_INCLUDED
#define GS_INFCOMPICKPOCKET_H_INCLUDED

class GE_DLLIMPORT InfComPickPocket
{
public: virtual ~InfComPickPocket( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    GEU32         GetDifficulty( void );
    gEInfoGesture GetGesture( void );
    Entity        GetListener( void );
    bCString      GetSVMID( void );
    bCString      GetSVMTextID( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
    void          SetCommand( gCInfoCommand * );
public:
    InfComPickPocket & operator = ( InfComPickPocket const & );
public:
    InfComPickPocket( InfComPickPocket const & );
    InfComPickPocket( void );
};
GE_ASSERT_SIZEOF( InfComPickPocket, 0x0008 )

#endif
