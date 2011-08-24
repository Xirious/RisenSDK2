#ifndef GE_CLOCK_PS_H_INCLUDED
#define GE_CLOCK_PS_H_INCLUDED

class GE_DLLIMPORT gCClock_PS :
    public eCEntityPropertySet
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCClock_PS * m_pClockPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public: virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual bEResult                                   PostInitializeProperties( void );
public: virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public: virtual                                           ~gCClock_PS( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual bEResult                                   ReadSaveGame( bCIStream & );
public: virtual bEResult                                   WriteSaveGame( bCOStream & );
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public: virtual GEBool                                     IsClassProcessible( void ) const;
public: virtual GEBool                                     IsClassProcessingEnabled( void ) const;
public: virtual void                                       EnableClassProcessing( GEBool );
public: virtual void                                       EnterProcessingRange( void );
public: virtual void                                       ExitProcessingRange( void );
public: virtual void                                       OnProcess( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x009C - sizeof(eCEngineComponentBase) ];
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &         AccessDay( void );
    GEU32 &         AccessDaysPlayed( void );
    GEFloat &       AccessFactor( void );
    GEU32 &         AccessHour( void );
    GEU32 &         AccessMinute( void );
    GEU32 &         AccessSecond( void );
    GEU32 &         AccessSecondsPlayed( void );
    GEU32 &         AccessTriggerEndHour( void );
    GEU32 &         AccessTriggerStartHour( void );
    GEU32 &         AccessYear( void );
    GEU32 const &   GetDay( void ) const;
    GEU32 const &   GetDaysPlayed( void ) const;
    GEFloat const & GetFactor( void ) const;
    GEU32 const &   GetHour( void ) const;
    GEU32 const &   GetMinute( void ) const;
    GEU32 const &   GetSecond( void ) const;
    GEU32 const &   GetSecondsPlayed( void ) const;
    GEU32           GetTimeStampInSeconds( void ) const;
    GEFloat         GetTimeStampInSecondsAsFloat( void ) const;
    GEU32 const &   GetTriggerEndHour( void ) const;
    GEU32 const &   GetTriggerStartHour( void ) const;
    GEU32 const &   GetYear( void ) const;
    GEBool          IsPaused( void ) const;
    void            SetDay( GEU32 const & );
    void            SetDaysPlayed( GEU32 const & );
    void            SetFactor( GEFloat const & );
    void            SetHour( GEU32 const & );
    void            SetMinute( GEU32 const & );
    void            SetPause( GEBool );
    void            SetSecond( GEU32 const & );
    void            SetSecondsPlayed( GEU32 const & );
    void            SetTriggerEndHour( GEU32 const & );
    void            SetTriggerStartHour( GEU32 const & );
    void            SetYear( GEU32 const & );
public:
    gCClock_PS & operator = ( gCClock_PS const & );
public:
    gCClock_PS( gCClock_PS const & );
    gCClock_PS( void );
};
GE_ASSERT_SIZEOF( gCClock_PS, 0x009C )

#endif
