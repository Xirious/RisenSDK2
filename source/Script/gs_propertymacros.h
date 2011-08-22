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
private:                                                             \
    /* operator is exported but the implementation does nothing */   \
    Property##NAME & operator = ( Property##NAME const & );          \
private:                                                             \
    Property##NAME( Property##NAME const & );                        \
    Property##NAME( void );                                          \
   ~Property##NAME( void );                                          \
};

#define GS_DECLARE_PROPERTYSET( CLASS )                     \
class GE_DLLIMPORT CLASS :                                  \
    protected Entity                                        \
{                                                           \
protected:                                                  \
    typedef CLASS _tPropertySet;                            \
    friend CLASS & Entity::PropertySet( void );             \
    friend CLASS const & Entity::PropertySet( void ) const; \
private:                                                    \
    /* operator is exported but copies only one byte */     \
    CLASS & operator = ( CLASS const & );                   \
private:                                                    \
    CLASS( CLASS const & );                                 \
    CLASS( void );                                          \
   ~CLASS( void );

#endif
