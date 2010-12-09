#ifndef GE_OBJECTREFBASE_H_INCLUDED
#define GE_OBJECTREFBASE_H_INCLUDED

//NOTE: 'const' attribute missing in bCObjectBase::GetReferenceCount.

class GE_DLLIMPORT bCObjectRefBase :
    public bCObjectBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          // [0000].0000
public:    virtual GEU16                      GetVersion( void ) const;             // [0000].0004
public:    virtual GEBool                     IsValid( void ) const;                // [0000].0008
public:    using                bCObjectBase::Deserialize;                          // [0000].000C
public:    using                bCObjectBase::Serialize;                            // [0000].0010
public:    using                bCObjectBase::Read;                                 // [0000].0014
public:    using                bCObjectBase::Write;                                // [0000].0018
protected: using                bCObjectBase::OnDeserialize;                        // [0000].001C
protected: using                bCObjectBase::OnSerialize;                          // [0000].0020
public:    virtual GEBool                     OnRead( bCIStream & );                // [0000].0024
public:    virtual GEBool                     OnWrite( bCOStream & );               // [0000].0028
public:    virtual bEResult                   Create( void );                       // [0000].002C
public:    virtual void                       Destroy( void );                      // [0000].0030
public:    using                bCObjectBase::CopyFrom;                             // [0000].0034
protected: using                bCObjectBase::OnCopyFrom;                           // [0000].0038
protected: using                bCObjectBase::OnCopyPatchableOnly;                  // [0000].003C
public:    virtual GEU32                      AddReference( void );                 // [0000].0040
public:    virtual GEU32                      ReleaseReference( void );             // [0000].0044
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
public:    virtual                           ~bCObjectRefBase( void );              // [0000].0070
private:
    static bCPropertyObjectTypeBase thisType;
private:
    GEU32 m_u32ReferenceCount: 31;  // 0004
    GEU32 m_bIsValid         :  1;
    // sizeof(bCObjectRefBase)      // 0008
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 GetReferenceCount( void ) const;
public:
    bCObjectRefBase & operator = ( bCObjectRefBase const & );
public:
    bCObjectRefBase( bCObjectRefBase const & );
    bCObjectRefBase( void );
};

#endif
