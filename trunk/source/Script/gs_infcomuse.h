#ifndef GS_INFCOMUSE_H_INCLUDED
#define GS_INFCOMUSE_H_INCLUDED

class GE_DLLIMPORT InfComUse
{
public: virtual ~InfComUse( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity   GetEntity1( void );
    Template GetItem( void );
    bCString GetUseAnimationName( void );
    void     SetCommand( gCInfoCommand * );
public:
    InfComUse & operator = ( InfComUse const & );
public:
    InfComUse( InfComUse const & );
    InfComUse( void );
};
GE_ASSERT_SIZEOF( InfComUse, 0x0008 )

#endif
