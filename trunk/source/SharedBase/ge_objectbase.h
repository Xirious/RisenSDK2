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
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     IsValid( void ) const;
public:    virtual GEBool                     Deserialize( bCXMLParserNode * );
public:    virtual GEBool                     Serialize( bCXMLParserNode * );
public:    virtual bEDoNotOverwriteMethod     Read( bCIStream & );
public:    virtual bEDoNotOverwriteMethod     Write( bCOStream & );
protected: virtual GEBool                     OnDeserialize( bCXMLParserNode * );
protected: virtual GEBool                     OnSerialize( bCXMLParserNode * );
protected: virtual GEBool                     OnRead( bCIStream & );
protected: virtual GEBool                     OnWrite(bCOStream &);
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEDoNotOverwriteMethod     CopyFrom( bCObjectBase const &, GEBool );
protected: virtual GEBool                     OnCopyFrom( bCObjectBase const & );
protected: virtual GEBool                     OnCopyPatchableOnly( bCObjectBase const & );
public:    virtual GEU32                      AddReference( void );
public:    virtual GEU32                      ReleaseReference( void );
public:    virtual GEU32                      GetReferenceCount( void );
public:    virtual bEResult                   BindPOType( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual GEBool                     HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
public:    virtual GEBool                     NotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
public:    virtual GEBool                     NotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
protected: virtual GEBool                     OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
protected: virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual GEInt                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr     GetNativePropertyAt( GEInt ) const;
public:    virtual                           ~bCObjectBase( void );
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

#endif
