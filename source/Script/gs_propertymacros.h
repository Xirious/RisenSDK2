#ifndef GS_PROPERTYMACROS_H_INCLUDED
#define GS_PROPERTYMACROS_H_INCLUDED

#define GS_DECLARE_PROPERTY( NAME, TYPE )                            \
class Property##NAME :                                               \
    protected Entity                                                 \
{                                                                    \
protected:                                                           \
    typedef Property##NAME _tProperty;                               \
    friend Property##NAME & Entity::Property( void );                \
    friend Property##NAME const & Entity::Property( void ) const;    \
public:                                                              \
                     operator TYPE const ( void ) const;             \
    Property##NAME & operator =          ( TYPE const & );           \
    Property##NAME & operator =          ( Property##NAME const & ); \
};

#define GS_DECLARE_PROPERTYSET( CLASS )                     \
class GE_DLLIMPORT CLASS :                                  \
    protected Entity                                        \
{                                                           \
protected:                                                  \
    typedef CLASS _tPropertySet;                            \
    friend CLASS & Entity::PropertySet( void );             \
    friend CLASS const & Entity::PropertySet( void ) const;

#endif
