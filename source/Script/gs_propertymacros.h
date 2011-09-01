#ifndef GS_PROPERTYMACROS_H_INCLUDED
#define GS_PROPERTYMACROS_H_INCLUDED

//
// Entity PropertySet (PS*)
//

class GE_DLLIMPORT EntityPropertySet
{
public:
    template< typename PSP >
    inline PSP & AccessProperty( void );
    template< typename PSP >
    inline PSP const & GetProperty( void ) const;
protected:
    eCEntity * m_pEngineEntity;
private:
    EntityPropertySet( void );                                     // not defined
    EntityPropertySet( EntityPropertySet const & );                // not defined
    EntityPropertySet & operator = ( EntityPropertySet const & );  // not defined
};

#define GS_DECLARE_PROPERTYSET( T, C )     \
class GE_DLLIMPORT T :                     \
    public EntityPropertySet               \
{                                          \
public:                                    \
    C const * operator -> ( void ) const;  \
protected:                                 \
    friend Entity;                         \
    typedef T PropertySet;                 \
    typedef C EnginePropertySet;           \
protected:                                 \
        operator C *       ( void );       \
        operator C const * ( void ) const; \
    C * operator ->        ( void );       \
private:                                   \
    T( void );                             \
    T( T const & );                        \
private:                                   \
    /* hide copy assignment operator */    \
    T & operator = ( T const & );

//
// Entity PropertySet Property (PS*::Property*)
//

class GE_DLLIMPORT EntityPropertySetProperty
{
protected:
    eCEntity * m_pEngineEntity;
private:
    EntityPropertySetProperty( void );                                             // not defined
    EntityPropertySetProperty( EntityPropertySetProperty const & );                // not defined
    EntityPropertySetProperty & operator = ( EntityPropertySetProperty const & );  // not defined
};

#define GS_DECLARE_PROPERTY( N, T )                   \
class GE_DLLIMPORT Property##N :                      \
    public EntityPropertySetProperty                  \
{                                                     \
public:                                               \
                  operator T const ( void ) const;    \
    Property##N & operator =       ( T const & );     \
protected:                                            \
    friend Entity;                                    \
    friend EntityPropertySet;                         \
    typedef Property##N PropertySetProperty;          \
private:                                              \
    Property##N( void );                              \
    Property##N( Property##N const & );               \
private:                                              \
    /* hide copy assignment operator */               \
    Property##N & operator = ( Property##N const & ); \
};

#include "gs_propertymacros.inl"

#endif
