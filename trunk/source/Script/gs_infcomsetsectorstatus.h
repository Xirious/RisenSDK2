#ifndef GS_INFCOMSETSECTORSTATUS_H_INCLUDED
#define GS_INFCOMSETSECTORSTATUS_H_INCLUDED

class GE_DLLIMPORT InfComSetSectorStatus
{
public: virtual ~InfComSetSectorStatus( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    GEBool   GetSectorEnabled( void );
    bCString GetSectorName( void );
    void     SetCommand( gCInfoCommand * );
public:
    InfComSetSectorStatus & operator = ( InfComSetSectorStatus const & );
public:
    InfComSetSectorStatus( InfComSetSectorStatus const & );
    InfComSetSectorStatus( void );
};
GE_ASSERT_SIZEOF( InfComSetSectorStatus, 0x0008 )

#endif
