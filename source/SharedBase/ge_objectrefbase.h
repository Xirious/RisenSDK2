#ifndef GE_OBJECTREFBASE_H_INCLUDED
#define GE_OBJECTREFBASE_H_INCLUDED

//NOTE: 'const' attribute missing in bCObjectBase::GetReferenceCount.
#pragma warning( push )

class GE_DLLIMPORT bCObjectRefBase :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     IsValid( void ) const;
public: using                bCObjectBase::Deserialize;
public: using                bCObjectBase::Serialize;
public: using                bCObjectBase::Read;
public: using                bCObjectBase::Write;
public: using                bCObjectBase::OnDeserialize;
public: using                bCObjectBase::OnSerialize;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: using                bCObjectBase::CopyFrom;
public: using                bCObjectBase::OnCopyFrom;
public: using                bCObjectBase::OnCopyPatchableOnly;
public: virtual GEU32                      AddReference( void );
public: virtual GEU32                      ReleaseReference( void );
public: using                bCObjectBase::GetReferenceCount;
public: using                bCObjectBase::BindPOType;
public: using                bCObjectBase::PostInitializeProperties;
public: using                bCObjectBase::HandleDeprecatedProperty;
public: using                bCObjectBase::NotifyPropertyValueChangedEnterEx;
public: using                bCObjectBase::NotifyPropertyValueChangedExitEx;
public: using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;
public: using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;
public: using                bCObjectBase::GetNativePropertyCount;
public: using                bCObjectBase::GetNativePropertyAt;
public: virtual                           ~bCObjectRefBase( void );
private:
    static bCPropertyObjectTypeBase thisType;
private:
    GEU32 m_u32ReferenceCount: 31;
    GEU32 m_bIsValid         :  1;
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
