#ifndef GE_PROPERTYTYPEBASE_H_INCLUDED
#define GE_PROPERTYTYPEBASE_H_INCLUDED

class bCObjectBase;              // forward
class bCPropertyObjectTypeBase;  // forward

//FIXME: UDT name bSEnumValue guessed.
struct bSEnumValue
{
    bCString m_strValue;
    GEU32    m_u32Value;
};

enum bEPropertyType
{
    bEPropertyType_Member = 1,
    bEPropertyType_Func,
    bEPropertyType_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4201 )  // nonstandard extension used : nameless struct/union

class GE_DLLIMPORT bCPropertyTypeBase
{
/* [0000].0000 */ public:    virtual GEU32                            GetDataSize( void ) const = 0;
/* [0000].0004 */ public:    virtual bCString const &                 GetClassName( void ) const = 0;
/* [0000].0008 */ public:    virtual bCString const &                 GetValueTypeName( void ) const = 0;
/* [0000].000C */ public:    virtual bCPropertyObjectTypeBase const & GetClassType( void ) const = 0;
/* [0000].0010 */ public:    virtual void                             PropertyInitialize( bCObjectBase * ) = 0;
/* [0000].0014 */ public:    virtual GEBool                           IsEnum( void ) const = 0;
/* [0000].0018 */ public:    virtual GEInt                            GetEnumCount( void ) const = 0;
/* [0000].001C */ public:    virtual bSEnumValue const &              GetEnumValue( GEInt ) const = 0;
/* [0000].0020 */ public:    virtual bCPropertyConverterPtr           GetPropertyConverter( bCObjectBase const * ) = 0;
/* [0000].0024 */ public:    virtual GEBool                           ConvertStringToValue( bCObjectBase *, bCString const & ) = 0;
/* [0000].0028 */ public:    virtual GEBool                           ConvertValueToString( bCObjectBase const *, bCString & ) = 0;
/* [0000].002C */ public:    virtual GEBool                           PropertyCopy( bCObjectBase *, bCObjectBase const * ) = 0;
/* [0000].0030 */ public:    virtual void                             PropertyWrite( bCOStream &, bCObjectBase const * ) = 0;
/* [0000].0034 */ public:    virtual void                             PropertyRead( bCIStream &, bCObjectBase * ) = 0;
/* [0000].0038 */ public:    virtual GEU16                            Read( bCIStream & );
/* [0000].003C */ public:    virtual void                             Write( bCOStream & );
/* [0000].0040 */ public:    virtual GEBool                           Deserialize( bCObjectBase *, bCXMLParserNode const * ) = 0;
/* [0000].0044 */ public:    virtual GEBool                           Serialize( bCObjectBase const *, bCXMLParserNode * ) = 0;
/* [0000].0048 */ protected: virtual void                             Destroy( void );
/* [0000].004C */ protected: virtual void                             Create( void );
/* [0000].0050 */ protected: virtual bCPropertyTypeBase *             DoClone( void ) const;
/* [0000].0054 */ protected: virtual void                             CopyFrom( bCPropertyTypeBase const & );
/* [0000].0058 */ public:    virtual                                 ~bCPropertyTypeBase( void );
private:
    bCString       m_strPropertyName;
    bCString       m_strPropertyDescription;
    bCString       m_strPropertyCategory;
    bEPropertyType m_enuPropertyType;
    union
    {
        GEU8       m_u8Attributes;
        struct 
        {
            GEU8   m_bIsReadOnly : 1;
            GEU8   m_bIsPatchable: 1;
        };
    };
                   GE_PADDING( 3 )
protected:
    bCPropertyTypeBase * Clone( void ) const;
    void                 CopyTo( bCPropertyTypeBase & ) const;
    void                 Invalidate( void );
public:
    static void GE_STDCALL PropertyReadSkip( bCIStream &, bCObjectBase *, bCString const &, bCString const & );
public:
    GEU8                 GetAttributes( void ) const;
    bCPropertyID const & GetID( void ) const;
    bCString const &     GetPropertyCategory( void ) const;
    bCString const &     GetPropertyDescription( void ) const;
    bCString const &     GetPropertyName( void ) const;
    bEPropertyType       GetPropertyType( void ) const;
    GEBool               IsNonPatchable( void ) const;
    GEBool               IsPatchable( void ) const;
    GEBool               IsReadOnly( void ) const;
protected:
    bCPropertyTypeBase const & operator = ( bCPropertyTypeBase const & );
public:
    bCIStream & operator << ( bCIStream & );
    bCOStream & operator >> ( bCOStream & );
private:
    bCPropertyTypeBase( bCPropertyTypeBase const & );
    bCPropertyTypeBase( void );
protected:
    bCPropertyTypeBase( bCString const &, bCString const &, bCString const &, bEPropertyType, GEInt );
    bCPropertyTypeBase( bCString const &, bCString const &, bEPropertyType, GEInt );
    bCPropertyTypeBase( bCString const &, bEPropertyType );
};

#pragma warning( pop )

#endif
