#ifndef GS_INFCOMHEAL_H_INCLUDED
#define GS_INFCOMHEAL_H_INCLUDED

class GE_DLLIMPORT InfComHeal
{
public: virtual ~InfComHeal( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    Entity GetEntity1( void );
    Entity GetEntity2( void );
    void   SetCommand( gCInfoCommand * );
public:
    InfComHeal & operator = ( InfComHeal const & );
public:
    InfComHeal( InfComHeal const & );
    InfComHeal( void );
};
GE_ASSERT_SIZEOF( InfComHeal, 0x0008 )

#endif
