#ifndef GS_PROPERTYMACROS_H_INCLUDED
#define GS_PROPERTYMACROS_H_INCLUDED

class GE_DLLIMPORT EntityProperty
{
protected:
    eCEntity * m_pEntity;
private:
    EntityProperty( void );
private:
    EntityProperty & operator = ( EntityProperty const & );
};

#define GS_DECLARE_PROPERTY( NAME, TYPE )                                    \
class GE_DLLIMPORT Property##NAME :                                          \
    public EntityProperty                                                    \
{                                                                            \
public:                                                                      \
                     operator TYPE const ( void ) const;                     \
    Property##NAME & operator =          ( TYPE const & );                   \
protected:                                                                   \
    typedef Property##NAME _tProperty;                                       \
    friend Property##NAME & Entity::Property( void );                        \
    friend Property##NAME const & Entity::Property( void ) const;            \
    friend Property##NAME & EntityPropertySet::Property( void );             \
    friend Property##NAME const & EntityPropertySet::Property( void ) const; \
private:                                                                     \
    /* suppress compiler-generated default constructor */                    \
    Property##NAME( void );                                                  \
    /* suppress compiler-generated default copy constructor */               \
    Property##NAME( Property##NAME const & );                                \
private:                                                                     \
    /* hide compiler-generated copy assignment operator */                   \
    Property##NAME & operator = ( Property##NAME const & );                  \
};

class GE_DLLIMPORT EntityPropertySet
{
public:
    template< typename T >
    inline T & Property( void );
    template< typename T >
    inline T const & Property( void ) const;
protected:
    eCEntity * m_pEntity;
private:
    EntityPropertySet( void );                       // not defined
    EntityPropertySet( EntityPropertySet const & );  // not defined
private:
    EntityPropertySet & operator = ( EntityPropertySet const & );  // not defined
};

#define GS_DECLARE_PROPERTYSET( CLASS, ENGINE_CLASS )            \
class GE_DLLIMPORT CLASS :                                       \
    public EntityPropertySet                                     \
{                                                                \
public:                                                          \
    ENGINE_CLASS const * operator -> ( void ) const;             \
protected:                                                       \
    typedef CLASS _tPropertySet;                                 \
    friend CLASS & Entity::PropertySet( void );                  \
    friend CLASS const & Entity::PropertySet( void ) const;      \
protected:                                                       \
                   operator ENGINE_CLASS *       ( void );       \
                   operator ENGINE_CLASS const * ( void ) const; \
    ENGINE_CLASS * operator ->                   ( void );       \
private:                                                         \
    /* suppress compiler-generated default constructor */        \
    CLASS( void );                                               \
    /* suppress compiler-generated default copy constructor */   \
    CLASS( CLASS const & );                                      \
private:                                                         \
    /* hide compiler-generated copy assignment operator */       \
    CLASS & operator = ( CLASS const & );

#include "gs_propertymacros.inl"

#endif
