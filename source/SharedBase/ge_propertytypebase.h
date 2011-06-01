#ifndef GE_PROPERTYTYPEBASE_H_INCLUDED
#define GE_PROPERTYTYPEBASE_H_INCLUDED

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
public:    virtual GEU32                            GetDataSize( void ) const                                      = 0;  
public:    virtual bCString const &                 GetClassName( void ) const                                     = 0;  
public:    virtual bCString const &                 GetValueTypeName( void ) const                                 = 0;  
public:    virtual bCPropertyObjectTypeBase const & GetClassType( void ) const                                     = 0;  
public:    virtual void                             InitializeProperty( bCObjectBase * )                           = 0;  
public:    virtual GEBool                           IsEnum( void ) const                                           = 0;  
public:    virtual GEInt                            GetEnumCount( void ) const                                     = 0;  
public:    virtual bSEnumValue const &              GetEnumValue( GEInt ) const                                    = 0;  
public:    virtual bCPropertyConverterPtr           GetNativeProperty( bCObjectBase const * )                      = 0;  
public:    virtual GEBool                           ConvertStringToValue( bCObjectBase *, bCString const & ) const = 0;  
public:    virtual GEBool                           ConvertValueToString( bCObjectBase const *, bCString & ) const = 0;  
public:    virtual GEBool                           PropertyCopy( bCObjectBase *, bCObjectBase const * )           = 0;  
public:    virtual void                             PropertyWrite( bCOStream &, bCObjectBase const * )             = 0;  
public:    virtual void                             PropertyRead( bCIStream &, bCObjectBase * )                    = 0;  
public:    virtual GEU16                            Read( bCIStream & );                                                 
public:    virtual void                             Write( bCOStream & );                                                
public:    virtual GEBool                           Deserialize( bCObjectBase *, bCXMLParserNode const * )         = 0;  
public:    virtual GEBool                           Serialize( bCObjectBase const *, bCXMLParserNode * )           = 0;  
protected: virtual void                             Destroy( void );                                                     
protected: virtual void                             Create( void );                                                      
protected: virtual bCPropertyTypeBase *             DoClone( void ) const;                                               
protected: virtual void                             CopyFrom( bCPropertyTypeBase const & );                              
public:    virtual                                 ~bCPropertyTypeBase( void );                                          
private:
    bCString       m_strPropertyName;         // 0004
    bCString       m_strPropertyDescription;  // 0008
    bCString       m_strPropertyCategory;     // 000C
    bEPropertyType m_enuPropertyType;         // 0010
    union
    {
        GEU8       m_u8Attributes;            // 0014
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
