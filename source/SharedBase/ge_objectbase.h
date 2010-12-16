#ifndef GE_OBJECTBASE_H_INCLUDED
#define GE_OBJECTBASE_H_INCLUDED

enum bEDoNotOverwriteMethod
{
    bEDoNotOverwriteMethod_False = bEResult_False,
    bEDoNotOverwriteMethod_Ok    = bEResult_Ok,
    bEDoNotOverwriteMethod_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCObjectBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;                                                  // [0000].0000
public:    virtual GEU16                      GetVersion( void ) const;                                                     // [0000].0004
public:    virtual GEBool                     IsValid( void ) const;                                                        // [0000].0008
public:    virtual GEBool                     Deserialize( bCXMLParserNode * );                                             // [0000].000C
public:    virtual GEBool                     Serialize( bCXMLParserNode * );                                               // [0000].0010
public:    virtual bEDoNotOverwriteMethod     Read( bCIStream & );                                                          // [0000].0014
public:    virtual bEDoNotOverwriteMethod     Write( bCOStream & );                                                         // [0000].0018
protected: virtual GEBool                     OnDeserialize( bCXMLParserNode * );                                           // [0000].001C
protected: virtual GEBool                     OnSerialize( bCXMLParserNode * );                                             // [0000].0020
protected: virtual GEBool                     OnRead( bCIStream & );                                                        // [0000].0024
protected: virtual GEBool                     OnWrite(bCOStream &);                                                         // [0000].0028
public:    virtual bEResult                   Create( void );                                                               // [0000].002C
protected: virtual void                       Destroy( void );                                                              // [0000].0030
public:    virtual bEDoNotOverwriteMethod     CopyFrom( bCObjectBase const &, GEBool );                                     // [0000].0034
protected: virtual GEBool                     OnCopyFrom( bCObjectBase const & );                                           // [0000].0038
protected: virtual GEBool                     OnCopyPatchableOnly( bCObjectBase const & );                                  // [0000].003C
public:    virtual GEU32                      AddReference( void );                                                         // [0000].0040
public:    virtual GEU32                      ReleaseReference( void );                                                     // [0000].0044
public:    virtual GEU32                      GetReferenceCount( void );                                                    // [0000].0048
public:    virtual bEResult                   BindPOType( void );                                                           // [0000].004C
public:    virtual bEResult                   PostInitializeProperties( void );                                             // [0000].0050
public:    virtual GEBool                     HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );  // [0000].0054
public:    virtual GEBool                     NotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );                       // [0000].0058
public:    virtual GEBool                     NotifyPropertyValueChangedExitEx( GELPCChar, GEBool );                        // [0000].005C
protected: virtual GEBool                     OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );                     // [0000].0060
protected: virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );                      // [0000].0064
public:    virtual GEInt                      GetNativePropertyCount( void ) const;                                         // [0000].0068
public:    virtual bCPropertyConverterPtr     GetNativePropertyAt( GEInt ) const;                                           // [0000].006C
public:    virtual                           ~bCObjectBase( void );                                                         // [0000].0070
private:
    static bCPropertyObjectTypeBase thisType;
private:
    GEU16 ReadData( bCIStream & );
    void  WriteData( bCOStream & );
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
public:
    bCObjectBase *         Clone( void );
    bEDoNotOverwriteMethod CopyTo( bCObjectBase & ) const;
    bCString const &       GetBaseClassName( void ) const;
    bCString               GetClassDescription( void ) const;
    bCString const &       GetClassName( void ) const;
    bCObjectBase *         GetPropertyObject( void );
    bCObjectBase const *   GetPropertyObject( void ) const;
    GEBool                 IsDerivedFrom( bCPropertyObjectTypeBase const * ) const;
    GEBool                 IsKindOf( bCPropertyObjectTypeBase const * ) const;
    GEBool                 IsObjectTypeValid( void ) const;
public:
    bCIStream &          operator << ( bCIStream & );
    bCOStream &          operator >> ( bCOStream & );
    bCObjectBase const & operator =  ( bCObjectBase const & );
public:
    explicit bCObjectBase( GEBool );
             bCObjectBase( bCObjectBase const & );
             bCObjectBase( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, bCObjectBase & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, bCObjectBase & );
};
GE_ASSERT_SIZEOF( bCObjectBase, 0x0004 )

#endif
