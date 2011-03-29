#ifndef GS_PROPERTYMACROS_H_INCLUDED
#define GS_PROPERTYMACROS_H_INCLUDED

//
// PropertySet<>
//

#define GS_DECLARE_PROPERTYSET_TEMPLATE( CLASS )           \
    template< typename CLASS##_PropertySet >               \
    CLASS##_PropertySet & PropertySet( void );             \
    template< typename CLASS##_PropertySet >               \
    CLASS##_PropertySet const & PropertySet( void ) const; \

#define GS_DECLARE_PROPERTYSET( CLASS ) \
class GE_DLLIMPORT CLASS                \
{                                       \
protected:                              \
    eCEntity * m_pEntity;               \

#define GS_DECLARE_PROPERTYSET_ACCESSOR( CLASS ) \
template<>                                       \
inline                                           \
CLASS & Entity::PropertySet( void );             \
template<>                                       \
inline                                           \
CLASS const & Entity::PropertySet( void ) const; \

#define GS_DEFINE_PROPERTYSET_ACCESSOR( CLASS )        \
template<>                                             \
CLASS & Entity::PropertySet( void )                    \
{                                                      \
    return *reinterpret_cast< CLASS * >( this );       \
}                                                      \
                                                       \
template<>                                             \
CLASS const & Entity::PropertySet( void ) const        \
{                                                      \
    return *reinterpret_cast< CLASS const * >( this ); \
}                                                      \

//
// Property<>
//

#define GS_DECLARE_PROPERTY_TEMPLATE( CLASS )                                              \
    template< typename CLASS##_Property > CLASS##_Property &       Property( void );       \
    template< typename CLASS##_Property > CLASS##_Property const & Property( void ) const; \

#define GS_DECLARE_PROPERTY( NAME, TYPE )                                \
    class Property##NAME                                                 \
    {                                                                    \
    protected:                                                           \
        eCEntity * m_pEntity;                                            \
    public:                                                              \
                         operator TYPE const ( void ) const;             \
        Property##NAME & operator =          ( TYPE const & );           \
        Property##NAME & operator =          ( Property##NAME const & ); \
    };                                                                   \

#define GS_DECLARE_PROPERTY_ACCESSOR( CLASS, NAME )             \
template<>                                                      \
inline                                                          \
CLASS::Property##NAME & CLASS::Property( void );                \
template<>                                                      \
inline                                                          \
CLASS::Property##NAME const & CLASS::Property( void ) const;    \

#define GS_DEFINE_PROPERTY_ACCESSOR( CLASS, NAME )                     \
template<>                                                             \
CLASS::Property##NAME & CLASS::Property( void )                        \
{                                                                      \
    return *reinterpret_cast< CLASS::Property##NAME * >( this );       \
}                                                                      \
                                                                       \
template<>                                                             \
CLASS::Property##NAME const & CLASS::Property( void ) const            \
{                                                                      \
    return *reinterpret_cast< CLASS::Property##NAME const * >( this ); \
}                                                                      \

#endif
