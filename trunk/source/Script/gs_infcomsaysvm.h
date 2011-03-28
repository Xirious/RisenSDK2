#ifndef GS_INFCOMSAYSVM_H_INCLUDED
#define GS_INFCOMSAYSVM_H_INCLUDED

class GE_DLLIMPORT InfComSaySVM
{
public: virtual ~InfComSaySVM( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    gEInfoGesture GetGesture( void );
    Entity        GetListener( void );
    bCString      GetSVMID( void );
    Entity        GetSpeaker( void );
    bCString      GetTextID( void );
    void          SetCommand( gCInfoCommand * );
public:
    InfComSaySVM & operator = ( InfComSaySVM const & );
public:
    InfComSaySVM( InfComSaySVM const & );
    InfComSaySVM( void );
};
GE_ASSERT_SIZEOF( InfComSaySVM, 0x0008 )

#endif
