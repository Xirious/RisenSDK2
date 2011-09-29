#ifndef GS_INFCOM_H_INCLUDED
#define GS_INFCOM_H_INCLUDED

#define GS_DECLARE_INFCOM( CLASS, ENGINE_CLASS ) \
class GE_DLLIMPORT CLASS                         \
{                                                \
public: virtual ~CLASS( void );                  \
protected:                                       \
    ENGINE_CLASS * m_pCommand;                   \
public:                                          \
    CLASS( void );                               \
    CLASS( CLASS const & );                      \
public:                                          \
    CLASS & operator = ( CLASS const & );        \
public:                                          \
    /* InfComXxx::SetCommand doesn't validate */ \
    /* if the parameter is an ENGINE_CLASS *. */ \
    void SetCommand( gCInfoCommand * );

#endif
