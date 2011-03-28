#ifndef GS_INFCOMSAYHOLDINGPOSITION_H_INCLUDED
#define GS_INFCOMSAYHOLDINGPOSITION_H_INCLUDED

class GE_DLLIMPORT InfComSayHoldingPosition
{
public: virtual ~InfComSayHoldingPosition( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity GetListener( void );
    Entity GetSpeaker( void );
    void   SetCommand( gCInfoCommand * );
public:
    InfComSayHoldingPosition & operator = ( InfComSayHoldingPosition const & );
public:
    InfComSayHoldingPosition( InfComSayHoldingPosition const & );
    InfComSayHoldingPosition( void );
};
GE_ASSERT_SIZEOF( InfComSayHoldingPosition, 0x0008 )

#endif
