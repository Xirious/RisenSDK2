#ifndef GS_INFCOMSAYCONFIRM_H_INCLUDED
#define GS_INFCOMSAYCONFIRM_H_INCLUDED

class GE_DLLIMPORT InfComSayConfirm
{
public: virtual ~InfComSayConfirm( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity GetListener( void );
    Entity GetSpeaker( void );
    void   SetCommand( gCInfoCommand * );
public:
    InfComSayConfirm & operator = ( InfComSayConfirm const & );
public:
    InfComSayConfirm( InfComSayConfirm const & );
    InfComSayConfirm( void );
};
GE_ASSERT_SIZEOF( InfComSayConfirm, 0x0008 )

#endif
