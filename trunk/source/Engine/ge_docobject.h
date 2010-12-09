#ifndef GE_DOCOBJECT_H_INCLUDED
#define GE_DOCOBJECT_H_INCLUDED

class GE_DLLIMPORT eCDocObject :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          // [0000].0000
public:    using             bCObjectRefBase::GetVersion;                           // [0000].0004
public:    using             bCObjectRefBase::IsValid;                              // [0000].0008
public:    using                bCObjectBase::Deserialize;                          // [0000].000C
public:    using                bCObjectBase::Serialize;                            // [0000].0010
public:    using                bCObjectBase::Read;                                 // [0000].0014
public:    using                bCObjectBase::Write;                                // [0000].0018
protected: using                bCObjectBase::OnDeserialize;                        // [0000].001C
protected: using                bCObjectBase::OnSerialize;                          // [0000].0020
public:    using             bCObjectRefBase::OnRead;                               // [0000].0024
public:    using             bCObjectRefBase::OnWrite;                              // [0000].0028
public:    using             bCObjectRefBase::Create;                               // [0000].002C
public:    using             bCObjectRefBase::Destroy;                              // [0000].0030
public:    using                bCObjectBase::CopyFrom;                             // [0000].0034
protected: using                bCObjectBase::OnCopyFrom;                           // [0000].0038
protected: using                bCObjectBase::OnCopyPatchableOnly;                  // [0000].003C
public:    using             bCObjectRefBase::AddReference;                         // [0000].0040
public:    using             bCObjectRefBase::ReleaseReference;                     // [0000].0044
public:    using                bCObjectBase::GetReferenceCount;                    // [0000].0048
public:    using                bCObjectBase::BindPOType;                           // [0000].004C
public:    using                bCObjectBase::PostInitializeProperties;             // [0000].0050
public:    using                bCObjectBase::HandleDeprecatedProperty;             // [0000].0054
public:    using                bCObjectBase::NotifyPropertyValueChangedEnterEx;    // [0000].0058
public:    using                bCObjectBase::NotifyPropertyValueChangedExitEx;     // [0000].005C
protected: using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;  // [0000].0060
protected: using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;   // [0000].0064
public:    using                bCObjectBase::GetNativePropertyCount;               // [0000].0068
public:    using                bCObjectBase::GetNativePropertyAt;                  // [0000].006C
public:    virtual                           ~eCDocObject( void );                  // [0000].0070
public:    virtual bCString                   GetRawExt( void ) const;              // [0000].0074
public:    virtual bCString                   GetRawPath( void ) const;             // [0000].0078
public:    virtual bCString                   GetFileKey( void ) const;             // [0000].007C
public:    virtual bCString                   GetFileTitleA( void ) const;          // [0000].0080
public:    virtual void                       SetFileTitleA( bCString const & );    // [0000].0084
public:    virtual void                       PostLoad( void );                     // [0000].0088
private:
    bCString m_strFileTitleA;  // 0008
    // sizeof(eCDocObject)        000C
private:
    static bCPropertyObjectTypeBase thisType;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static eCDocObject *              GE_STDCALL LoadBinary( bCIStream & );
    static eCDocObject *              GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString GetRawFileName( void ) const;
    bCString GetRawFilePath( void ) const;
    GEBool   GetRawFileTime( SFFFileTime & ) const;
    GEBool   ReloadRaw( void );
    GEBool   SaveRaw( void );
    GEBool   SaveRawAs( bCString const &, bCString const & );
    GEBool   SaveRawAsClass( bCString const &, bCString const &, bCString const & );
public:
    eCDocObject & operator = ( eCDocObject const & );
public:
    eCDocObject( eCDocObject const & );
    eCDocObject( void );
};

#endif
