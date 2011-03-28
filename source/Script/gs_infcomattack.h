#ifndef GS_INFCOMATTACK_H_INCLUDED
#define GS_INFCOMATTACK_H_INCLUDED

class GE_DLLIMPORT InfComAttack
{
public: virtual ~InfComAttack( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity   GetEntity1( void );
    Entity   GetEntity2( void );
    bCString GetReason( void );
    void     SetCommand( gCInfoCommand * );
public:
    InfComAttack & operator = ( InfComAttack const & );
public:
    InfComAttack( InfComAttack const & );
    InfComAttack( void );
};
GE_ASSERT_SIZEOF( InfComAttack, 0x0008 )

#endif
