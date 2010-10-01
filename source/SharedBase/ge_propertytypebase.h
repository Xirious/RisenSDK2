#ifndef GE_PROPERTYTYPEBASE_H_INCLUDED
#define GE_PROPERTYTYPEBASE_H_INCLUDED

class bCObjectBase;              // forward
class bCPropertyObjectTypeBase;  // forward

//FIXME: Identifier is bSEnumValue pure guesswork.
struct bSEnumValue
{
    bCString m_strValue;
    GEU32    m_u32Value;
};

enum bEPropertyType
{
    //FIXME: bEPropertyType constants.
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
/* [0000].0010 */ private:   virtual void                             __FIXME_0010( void * ) = 0;
/* [0000].0014 */ public:    virtual GEBool                           HasEnumValues( void ) const = 0;
/* [0000].0018 */ public:    virtual GEInt                            GetEnumValuesCount( void ) const = 0;
/* [0000].001C */ public:    virtual bSEnumValue const &              GetEnumValue( GEInt ) const = 0;
/* [0000].0020 */ private:   virtual bCPropertyConverterPtr           __FIXME_0020( void * ) = 0;
/* [0000].0024 */ private:   virtual void                             __FIXME_0024( void ) = 0;
/* [0000].0028 */ private:   virtual void                             __FIXME_0028( void ) = 0;
/* [0000].002C */ private:   virtual void                             __FIXME_002C( void ) = 0;
/* [0000].0030 */ private:   virtual void                             __FIXME_0030( void ) = 0;
/* [0000].0034 */ private:   virtual void                             __FIXME_0034( void ) = 0;
/* [0000].0038 */ public:    virtual GEU16                            Read( bCIStream & );
/* [0000].003C */ public:    virtual void                             Write( bCOStream & );
/* [0000].0040 */ private:   virtual GEBool                           Deserialize( void * a_pPropertyObject, bCXMLParserNode const * ) = 0;
/* [0000].0044 */ private:   virtual GEBool                           Serialize( void * a_pPropertyObject, bCXMLParserNode * ) = 0;
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
