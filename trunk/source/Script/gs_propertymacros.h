#ifndef GS_PROPERTYMACROS_H_INCLUDED
#define GS_PROPERTYMACROS_H_INCLUDED

class GE_DLLIMPORT EntityProperty
{
protected:
    eCEntity * m_pEngineEntity;
private:
    EntityProperty & operator = ( EntityProperty const & );
private:
    EntityProperty( EntityProperty const & );
    EntityProperty( void );
   ~EntityProperty( void );
};

#define GS_DECLARE_PROPERTY( NAME, TYPE )                                    \
class Property##NAME :                                                       \
    public EntityProperty                                                    \
{                                                                            \
protected:                                                                   \
    typedef Property##NAME _tProperty;                                       \
    friend Property##NAME & EntityPropertySet::Property( void );             \
    friend Property##NAME const & EntityPropertySet::Property( void ) const; \
public:                                                                      \
                     operator TYPE const ( void ) const;                     \
    Property##NAME & operator =          ( TYPE const & );                   \
private:                                                                     \
    /* operator is exported but the implementation does nothing */           \
    Property##NAME & operator = ( Property##NAME const & );                  \
private:                                                                     \
    Property##NAME( Property##NAME const & );                                \
    Property##NAME( void );                                                  \
   ~Property##NAME( void );                                                  \
};

class GE_DLLIMPORT EntityPropertySet
{
protected:
    eCEntity * m_pEngineEntity;
public:
    template< typename T >
    inline T & Property( void );
    template< typename T >
    inline T const & Property( void ) const;
private:
    EntityPropertySet & operator = ( EntityPropertySet const & );
private:
    EntityPropertySet( EntityPropertySet const & );
    EntityPropertySet( void );
   ~EntityPropertySet( void );
};

#define GS_DECLARE_PROPERTYSET( CLASS )                     \
class GE_DLLIMPORT CLASS :                                  \
    public EntityPropertySet                                \
{                                                           \
protected:                                                  \
    typedef CLASS _tPropertySet;                            \
    friend CLASS & Entity::PropertySet( void );             \
    friend CLASS const & Entity::PropertySet( void ) const; \
private:                                                    \
    /* operator is exported but only one byte is copied */  \
    CLASS & operator = ( CLASS const & );                   \
private:                                                    \
    CLASS( CLASS const & );                                 \
    CLASS( void );                                          \
   ~CLASS( void );

#include "gs_propertymacros.inl"

#endif
