#ifndef GE_PROPERTYCONTAINER_H_INCLUDED
#define GE_PROPERTYCONTAINER_H_INCLUDED

class bCPropertyContainer
{
public: virtual void     Invalidate( void ) = 0;
public: virtual bEResult Read( bCIStream & ) = 0;
public: virtual bEResult Write( bCOStream & ) const = 0;
};

//NOTE: Invalidate is virtual but the template is not exported.
// Therefore we do not have access to the Default Value defined
// elsewhere in the Genome libraries or the Game application...
// That is the reason why no default constructor is defined and
// our definition of Invalidate sets the Value to -1 (it should
// be an invalid value for most of the enumerations). The other
// virtual methods (Read and Write) emulate the Genome methods.
template< typename T >
class bTPropertyContainer :
    public bCPropertyContainer
{
public: virtual void     Invalidate( void );
public: virtual bEResult Read( bCIStream & );
public: virtual bEResult Write( bCOStream & ) const;
protected:
    GE_DECLARE_PROPERTY( T, m_Value, Value )
public:
    bTPropertyContainer( T const & );
    bTPropertyContainer( bTPropertyContainer< T > const & );
public:
                               operator T &       ( void );
                               operator T const & ( void ) const;
    GEBool                     operator ==        ( bTPropertyContainer< T > const & ) const;
    GEBool                     operator ==        ( T const & ) const;
    GEBool                     operator !=        ( bTPropertyContainer< T > const & ) const;
    GEBool                     operator !=        ( T const & ) const;
private:
    bTPropertyContainer( void );  // not defined
private:
    bTPropertyContainer< T > & operator = ( bTPropertyContainer< T > const & );  // not defined
};

#include "ge_propertycontainer.inl"

#endif
