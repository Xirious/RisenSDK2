#ifndef GE_ACCESSORPROPERTY_H_INCLUDED
#define GE_ACCESSORPROPERTY_H_INCLUDED

enum bEPropertyTypeDetail
{
    bEPropertyTypeDetail_Unknown,
    bEPropertyTypeDetail_String,          // bCString
    bEPropertyTypeDetail_UnicodeString,   // bCUnicodeString
    bEPropertyTypeDetail_GUID,            // bCGuid
    bEPropertyTypeDetail_Vector,          // bCVector
    bEPropertyTypeDetail_Vector4,         // bCVector4
    bEPropertyTypeDetail_Matrix,          // bCMatrix
    bEPropertyTypeDetail_Matrix3,         // bCMatrix3
    bEPropertyTypeDetail_Box,             // bCBox
    bEPropertyTypeDetail_Sphere,          // bCSphere
    bEPropertyTypeDetail_Quaternion,      // bCQuaternion
    bEPropertyTypeDetail_ObjectBase,      // bCObjectBase
    bEPropertyTypeDetail_PropertyObject,  // *bTPropertyObject*
    bEPropertyTypeDetail_Float,           // float
    bEPropertyTypeDetail_Double,          // double
    bEPropertyTypeDetail_Bool,            // bool
    bEPropertyTypeDetail_Char,            // char
    bEPropertyTypeDetail_Int64,           // __int64
    bEPropertyTypeDetail_Long,            // long
    bEPropertyTypeDetail_Short,           // short
    bEPropertyTypeDetail_Int,             // int
    bEPropertyTypeDetail_Enum,            // *bTPropertyContainer*
    bEPropertyTypeDetail_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCAccessorProperty :
    public bCAccessorPropertyObject
{
protected:
    GEInt m_iIndex;
protected:
    static bCString ms_strEmptyName;
protected:
    GEBool Iterate( void );
    GEBool ResolveProperty( bCPropertyID const & );
    GEBool ResolveProperty( bCString const & );
public:
    GEBool                           Compare( bCAccessorProperty const & ) const;
    void                             ConvertStringToValue( bCString const & );
    bCString                         ConvertValueToString( void );
    void                             CopyFrom( bCAccessorProperty const & );
    void                             CopyTo( bCAccessorProperty & ) const;
    void                             DumpOutputDebugString( void );
    bCAccessorPropertyObject &       GetAccessorPropertyObject( void );
    bCAccessorPropertyObject const & GetAccessorPropertyObject( void ) const;
    bCString const &                 GetClassName( void ) const;
    bCString const &                 GetPropertyCategory( void ) const;
    bCString const &                 GetPropertyDescription( void ) const;
    bCString                         GetPropertyHeader( void ) const;
    bCPropertyID const &             GetPropertyID( void ) const;
    bCString const &                 GetPropertyName( void ) const;
    bCObjectBase *                   GetPropertyObject( void );
    bCObjectBase const *             GetPropertyObject( void ) const;
    bCString const &                 GetPropertyType( void ) const;
    bCPropertyTypeBase *             GetPropertyTypeObject( void );
    bCPropertyTypeBase const *       GetPropertyTypeObject( void ) const;
    bEPropertyTypeDetail             GetPropertyValueDetailType( void ) const;
    void                             Invalidate( void );
    GEBool                           IsEnum( void ) const;
    GEBool                           IsPropertyReadOnly( void ) const;
    GEBool                           IsValid( void ) const;
public:
    bCAccessorProperty const & operator =  ( bCAccessorProperty const & );
    GEBool                     operator == ( bCAccessorProperty const & ) const;
    GEBool                     operator != ( bCAccessorProperty const & ) const;
    bCAccessorProperty         operator [] ( bCString const & );
    bCAccessorProperty         operator [] ( bCString const & ) const;
    bCAccessorProperty         operator ++ ( GEInt );
    bCAccessorProperty &       operator ++ ( void );
public:
    bCAccessorProperty( bCAccessorCreator const & );
    bCAccessorProperty( bCAccessorCreator const &, bCPropertyID const & );
    bCAccessorProperty( bCAccessorCreator const &, bCString const & );
    bCAccessorProperty( bCAccessorPropertyObject const & );
    bCAccessorProperty( bCObjectBase const * );
    bCAccessorProperty( bCObjectBase const *, bCString const & );
    bCAccessorProperty( bCAccessorProperty const & );
    bCAccessorProperty( void );
   ~bCAccessorProperty( void );
};

#endif
