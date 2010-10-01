#ifndef GE_PROPERTYCONTAINER_H_INCLUDED
#define GE_PROPERTYCONTAINER_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class bCPropertyContainer
{
public: virtual void     Invalidate( void );
public: virtual bEResult Read( bCIStream & );
public: virtual bEResult Write( bCOStream & ) const;
private:
    bCPropertyContainer const & operator = ( bCPropertyContainer const & );  // not defined
private:
    bCPropertyContainer( bCPropertyContainer const & );  // not defined
public:
    bCPropertyContainer( void );
   ~bCPropertyContainer( void );
};

#pragma warning( pop )

template< typename T >
class bTPropertyContainer :
    public bCPropertyContainer
{
public: virtual void     Invalidate( void );
public: virtual bEResult Read( bCIStream & );
public: virtual bEResult Write( bCOStream & ) const;
private:
    static T ms_DefaultValue;
private:
    T m_Value;
protected:
    GE_SERIALIZE_VERSION( 201 );
protected:
    static GEU16 GetVersion( void );
public:
    static T const &        GetDefaultValue( void );
    static bCString const & GetTypeName( void );
    static void             SetDefaultValue( T const & a_DefaultValue );
public:
    T &              AccessValue( void );
    T const &        GetValue( void ) const;
    void             SetValue( T const & a_Value );
public:
                               operator T &       ( void );
                               operator T const & ( void ) const;
                               operator GEU32     ( void ) const;
    GEBool                     operator ==        ( bTPropertyContainer< T > const & a_Other ) const;
    GEBool                     operator !=        ( bTPropertyContainer< T > const & a_Other ) const;
    bTPropertyContainer< T > & operator =         ( bTPropertyContainer< T > const & a_Source );
public:
    bTPropertyContainer( T const & a_Value );
    bTPropertyContainer( bTPropertyContainer< T > const & a_Source );
    bTPropertyContainer( void );
   ~bTPropertyContainer( void );
};

#include "ge_propertycontainer.inl"

#endif
