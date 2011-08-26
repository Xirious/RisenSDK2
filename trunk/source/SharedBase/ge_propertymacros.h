#ifndef GE_PROPERTYMACROS_H_INCLUDED
#define GE_PROPERTYMACROS_H_INCLUDED

//
// Property Object
//

#define GE_DECLARE_PROPERTY_OBJECT( CLASS, BASECLASS )\
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;\
public:\
    static bCObjectBase *             GE_STDCALL CreateObject( void );\
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );\
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );\
private:\
    static bCPropertyObjectTypeBase thisType;

//
// Property
//

#define GE_DECLARE_PROPERTY_MEMBER( TYPE, MEMBERNAME )\
protected:\
    TYPE MEMBERNAME;

#define GE_DECLARE_PROPERTY_GETTER( TYPE, PROPERTYNAME )\
public:\
    TYPE const & Get##PROPERTYNAME( void ) const;

#define GE_DECLARE_PROPERTY_SETTER( TYPE, PROPERTYNAME )\
public:\
    void Set##PROPERTYNAME( TYPE const & a_Value );

#define GE_DECLARE_PROPERTY_GETSET( TYPE, PROPERTYNAME )\
GE_DECLARE_PROPERTY_GETTER( TYPE, PROPERTYNAME )\
GE_DECLARE_PROPERTY_SETTER( TYPE, PROPERTYNAME )

#define GE_DECLARE_PROPERTY_ACCESS( TYPE, PROPERTYNAME )\
GE_DECLARE_PROPERTY_GETSET( TYPE, PROPERTYNAME )\
public:\
    TYPE & Access##PROPERTYNAME( void );

//NOTE: GE_DECLARE_PROPERTY ends with protected scope.
#define GE_DECLARE_PROPERTY( TYPE, MEMBERNAME, PROPERTYNAME )\
GE_DECLARE_PROPERTY_ACCESS( TYPE, PROPERTYNAME )\
GE_DECLARE_PROPERTY_MEMBER( TYPE, MEMBERNAME )

//
// Enumeration Property
//

#define GE_DECLARE_ENUMPROP_MEMBER( ENUM, MEMBERNAME )\
GE_DECLARE_PROPERTY_MEMBER( bTPropertyContainer< ENUM >, MEMBERNAME )

#define GE_DECLARE_ENUMPROP_GETTER( ENUM, PROPERTYNAME )\
GE_DECLARE_PROPERTY_GETTER( bTPropertyContainer< ENUM >, PROPERTYNAME )

#define GE_DECLARE_ENUMPROP_SETTER( ENUM, PROPERTYNAME )\
GE_DECLARE_PROPERTY_SETTER( bTPropertyContainer< ENUM >, PROPERTYNAME )

#define GE_DECLARE_ENUMPROP_GETSET( ENUM, PROPERTYNAME )\
GE_DECLARE_PROPERTY_GETSET( bTPropertyContainer< ENUM >, PROPERTYNAME )

#define GE_DECLARE_ENUMPROP_ACCESS( ENUM, PROPERTYNAME )\
GE_DECLARE_PROPERTY_ACCESS( bTPropertyContainer< ENUM >, PROPERTYNAME )

//NOTE: GE_DECLARE_ENUMPROP ends with protected scope.
#define GE_DECLARE_ENUMPROP( ENUM, MEMBERNAME, PROPERTYNAME )\
GE_DECLARE_PROPERTY( bTPropertyContainer< ENUM >, MEMBERNAME, PROPERTYNAME )

#endif
