#ifndef GE_GUIRESOURCE2_H_INCLUDED
#define GE_GUIRESOURCE2_H_INCLUDED

class GE_DLLIMPORT eCGuiResource2 :
    public eCDocObject,
    public virtual IFFUnknown
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;                   // [0000].0000
public:    using             bCObjectRefBase::GetVersion;                                    // [0000].0004
public:    using             bCObjectRefBase::IsValid;                                       // [0000].0008
public:    using                bCObjectBase::Deserialize;                                   // [0000].000C
public:    using                bCObjectBase::Serialize;                                     // [0000].0010
public:    using                bCObjectBase::Read;                                          // [0000].0014
public:    using                bCObjectBase::Write;                                         // [0000].0018
protected: using                bCObjectBase::OnDeserialize;                                 // [0000].001C
protected: using                bCObjectBase::OnSerialize;                                   // [0000].0020
public:    using             bCObjectRefBase::OnRead;                                        // [0000].0024
public:    using             bCObjectRefBase::OnWrite;                                       // [0000].0028
public:    using             bCObjectRefBase::Create;                                        // [0000].002C
public:    using             bCObjectRefBase::Destroy;                                       // [0000].0030
public:    using                bCObjectBase::CopyFrom;                                      // [0000].0034
protected: using                bCObjectBase::OnCopyFrom;                                    // [0000].0038
protected: using                bCObjectBase::OnCopyPatchableOnly;                           // [0000].003C
public:    virtual GEU32                      AddReference( void );                          // [0000].0040
public:    virtual GEU32                      ReleaseReference( void );                      // [0000].0044
public:    virtual GEU32                      GetReferenceCount( void );                     // [0000].0048
public:    using                bCObjectBase::BindPOType;                                    // [0000].004C
public:    using                bCObjectBase::PostInitializeProperties;                      // [0000].0050
public:    using                bCObjectBase::HandleDeprecatedProperty;                      // [0000].0054
public:    using                bCObjectBase::NotifyPropertyValueChangedEnterEx;             // [0000].0058
public:    using                bCObjectBase::NotifyPropertyValueChangedExitEx;              // [0000].005C
public:    using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;           // [0000].0060
public:    using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;            // [0000].0064
public:    using                bCObjectBase::GetNativePropertyCount;                        // [0000].0068
public:    using                bCObjectBase::GetNativePropertyAt;                           // [0000].006C
public:    virtual                           ~eCGuiResource2( void );                        // [0000].0070
public:    virtual bCString                   GetRawExt( void ) const;                       // [0000].0074
public:    virtual bCString                   GetRawPath( void ) const;                      // [0000].0078
public:    using                 eCDocObject::GetFileKey;                                    // [0000].007C
public:    using                 eCDocObject::GetFileTitleA;                                 // [0000].0080
public:    using                 eCDocObject::SetFileTitleA;                                 // [0000].0084
public:    using                 eCDocObject::PostLoad;                                      // [0000].0088
public:    virtual void                       OnFinalRelease( void );                        // [0000].008C
public:    virtual GEU32                      AddRef( void );                                // [0014].0000
public:    virtual GEU32                      Release( void );                               // [0014].0004
public:    virtual GEU32                      QueryInterface( FFGUID const &, FFLPVoid * );  // [0014].0008
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    // sizeof(eCGuiResource2) 0018
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL GetClassRawExt( void );
    static bCString                   GE_STDCALL GetClassRawPath( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static eCGuiResource2 *           GE_STDCALL LoadBinary( bCIStream & );
    static eCGuiResource2 *           GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static char s_carrAllocBuffer[];
public:
    eCGuiResource2 & operator = ( eCGuiResource2 const & );
public:
    eCGuiResource2( eCGuiResource2 const & );
    eCGuiResource2( void );
};

#endif
