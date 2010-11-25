#ifndef GE_PROPERTYCONVERTER_H_INCLUDED
#define GE_PROPERTYCONVERTER_H_INCLUDED

class bCObjectBase;  // forward

class GE_DLLIMPORT bCPropertyConverter
{
public: virtual GEU32                  AddReference( void );                         // [0000].0000
public: virtual GEU32                  ReleaseReference( void );                     // [0000].0004
public: virtual bCString const &       GetPropertyName( void ) const            = 0;  // [0000].0008
public: virtual GELPCChar              GetClassName( void ) const               = 0;  // [0000].000C
public: virtual GELPCChar              GetValueTypeName( void ) const           = 0;  // [0000].0010
public: virtual bCString               GetPropertyCategory( void ) const        = 0;  // [0000].0014
public: virtual bCString               GetPropertyDescription( void ) const     = 0;  // [0000].0018
public: virtual GEBool                 IsReadOnly( void ) const                 = 0;  // [0000].001C
public: virtual GEBool                 IsPatchable( void ) const                = 0;  // [0000].0020
public: virtual GEBool                 ConvertStringToValue( bCString const & ) = 0;  // [0000].0024
public: virtual GEBool                 ConvertValueToString( bCString & )       = 0;  // [0000].0028
public: virtual GEBool                 IsEnum( void ) const                     = 0;  // [0000].002C
public: virtual void *                 __FIXME_0030( void * )                   = 0;  // [0000].0030
public: virtual GEInt                  GetElementCount( void )                  = 0;  // [0000].0034
public: virtual bCPropertyConverterPtr GetElement( GEInt )                      = 0;  // [0000].0038
public: virtual GEBool                 CopyFrom( bCPropertyConverterPtr )       = 0;  // [0000].003C
public: virtual GEBool                 IsEqual( bCPropertyConverterPtr )        = 0;  // [0000].0040
public: virtual GEBool                 __FIXME_0044( void )                     = 0;  // [0000].0044
public: virtual GEBool                 IsArray( void )                          = 0;  // [0000].0048
public: virtual GEBool                 IsNonArray( void )                       = 0;  // [0000].004C
public: virtual bCPropertyConverterPtr __FIXME_0050( void )                     = 0;  // [0000].0050
public: virtual GEBool                 AddElement( bCPropertyConverterPtr )     = 0;  // [0000].0054
public: virtual GEBool                 Contains( bCPropertyConverterPtr )       = 0;  // [0000].0058
public: virtual bCObjectBase *         GetPropertyClass( void )                 = 0;  // [0000].005C
public: virtual                       ~bCPropertyConverter( void );                   // [0000].0060
// bTPropertyConverterTyped< TYPE >
// public: virtual T &                 PropertyGetter( void )                   = 0;  // [0000].0064
// public: virtual void                SetValue( T const & )                    = 0;  // [0000].0068
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
