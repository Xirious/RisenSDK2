#ifndef GE_PROPERTYCONVERTER_H_INCLUDED
#define GE_PROPERTYCONVERTER_H_INCLUDED

//TODO: bCPropertyConverter - How to create array elements?
//TODO: bCPropertyConverter - How to delete array elements?

class GE_DLLIMPORT bCPropertyConverter
{
public: virtual GEU32                  AddReference( void );                          
public: virtual GEU32                  ReleaseReference( void );                      
public: virtual bCString const &       GetPropertyName( void ) const            = 0;  
public: virtual GELPCChar              GetClassName( void ) const               = 0;  
public: virtual GELPCChar              GetValueTypeName( void ) const           = 0;  
public: virtual bCString               GetPropertyCategory( void ) const        = 0;  
public: virtual bCString               GetPropertyDescription( void ) const     = 0;  
public: virtual GEBool                 IsReadOnly( void ) const                 = 0;  
public: virtual GEBool                 IsPatchable( void ) const                = 0;  
public: virtual GEBool                 ConvertStringToValue( bCString const & ) = 0;  
public: virtual GEBool                 ConvertValueToString( bCString & )       = 0;  
public: virtual GEBool                 IsEnum( void ) const                     = 0;  
public: virtual void                   GetEnumNames( bTObjArray< bCString > & ) = 0;  
public: virtual GEInt                  GetElementCount( void )                  = 0;  
public: virtual bCPropertyConverterPtr GetElement( GEInt )                      = 0;  
public: virtual GEBool                 CopyFrom( bCPropertyConverterPtr )       = 0;  
public: virtual GEBool                 IsEqual( bCPropertyConverterPtr )        = 0;  
public: virtual GEBool                 IsArrayElement( void )                   = 0;  
public: virtual GEBool                 IsArray( void )                          = 0;  
public: virtual GEBool                 IsNonArray( void )                       = 0;  
public: virtual bCPropertyConverterPtr GetArray( void )                         = 0;  
public: virtual GEBool                 AddElement( bCPropertyConverterPtr )     = 0;  
public: virtual GEBool                 Contains( bCPropertyConverterPtr )       = 0;  
public: virtual bCObjectBase *         GetPropertyClass( void )                 = 0;  
public: virtual                       ~bCPropertyConverter( void );                   
// bTPropertyConverterTyped< TYPE >
// public: virtual TYPE const &        PropertyGetter( void )                   = 0;  
// public: virtual void                SetValue( TYPE const & )                 = 0;  
private:
    GEU32 m_u32ReferenceCount;  // 0004
    // sizeof(bCPropertyConverter) 0008
public:
    bCPropertyConverter & operator = ( bCPropertyConverter const & );
public:
    bCPropertyConverter( bCPropertyConverter const & );
    bCPropertyConverter( void );
};

#endif
