#ifndef GE_EFFECTCOMMANDPLAYSOUND_H_INCLUDED
#define GE_EFFECTCOMMANDPLAYSOUND_H_INCLUDED

struct gSEffectCommandPlaySoundItem
{
    bCString __FIXME;
};
GE_ASSERT_SIZEOF( gSEffectCommandPlaySoundItem, 0x0004 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandPlaySound'
                                   // class 'bTObjArray<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandPlaySound'

class GE_DLLIMPORT gCEffectCommandPlaySound :
    public gCEffectCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCEffectCommandPlaySound( void );
public:    virtual bCString                   GetCommandString( void ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
protected: virtual void                       OnStop( gSEffectCommandInstance & ) const;
protected: virtual GEBool                     OnProcess( gSEffectCommandInstance & ) const;
public:    virtual GEBool                     Prefetch( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat                                      m_fVolume;               // c
    GEFloat                                      m_fMinDistance;          // 10
    GEFloat                                      m_fMaxDistance;          // 14
    bTPropertyContainer< eEAudioChannelFallOff > m_enumFallOff;           // 18
    bCString                                     m_strRollOffPreset;      // 20
    GEBool                                       m_bUseRollOffPreset;     // 24
    GEBool                                       m_bUseVolumeFromPreset;  // 25
    GEBool                                       m_bLoopSound;            // 26
                                                 GE_PADDING( 1 )
    bTObjArray< gSEffectCommandPlaySoundItem >   m_arrItems;              // 28
    bCString                                     m_strBoneName;           // 34
    bTPropertyContainer< gEEffectLink >          m_enumCoordinateSystem;  // 38
    bCVector                                     m_vecOffset;             // 40
    GEBool                                       m_bInDialog;             // 4c
                                                 GE_PADDING1( 3 )
protected:
    void GetPosition( bCVector &, gSEffectCommandInstance & ) const;
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                           AccessBoneName( void );
    bTPropertyContainer< gEEffectLink > &                AccessCoordinateSystem( void );
    bTPropertyContainer< eEAudioChannelFallOff > &       AccessFallOff( void );
    GEBool &                                             AccessInDialog( void );
    bTObjArray< gSEffectCommandPlaySoundItem > &         AccessItems( void );
    GEBool &                                             AccessLoopSound( void );
    GEFloat &                                            AccessMaxDistance( void );
    GEFloat &                                            AccessMinDistance( void );
    bCVector &                                           AccessOffset( void );
    bCString &                                           AccessRollOffPreset( void );
    GEBool &                                             AccessUseRollOffPreset( void );
    GEBool &                                             AccessUseVolumeFromPreset( void );
    GEFloat &                                            AccessVolume( void );
    bCString const &                                     GetBoneName( void ) const;
    bTPropertyContainer< gEEffectLink > const &          GetCoordinateSystem( void ) const;
    bTPropertyContainer< eEAudioChannelFallOff > const & GetFallOff( void ) const;
    GEBool const &                                       GetInDialog( void ) const;
    bTObjArray< gSEffectCommandPlaySoundItem > &         GetItems( void );
    bTObjArray< gSEffectCommandPlaySoundItem > const &   GetItems( void ) const;
    GEBool const &                                       GetLoopSound( void ) const;
    GEFloat const &                                      GetMaxDistance( void ) const;
    GEFloat const &                                      GetMinDistance( void ) const;
    bCVector const &                                     GetOffset( void ) const;
    bCString const &                                     GetRollOffPreset( void ) const;
    GEBool const &                                       GetUseRollOffPreset( void ) const;
    GEBool const &                                       GetUseVolumeFromPreset( void ) const;
    GEFloat const &                                      GetVolume( void ) const;
    GEInt                                                SelectSample( void ) const;
    void                                                 SetBoneName( bCString const & );
    void                                                 SetCoordinateSystem( bTPropertyContainer< gEEffectLink > const & );
    void                                                 SetFallOff( bTPropertyContainer< eEAudioChannelFallOff > const & );
    void                                                 SetInDialog( GEBool const & );
    void                                                 SetItems( bTObjArray< gSEffectCommandPlaySoundItem > const & );
    void                                                 SetLoopSound( GEBool const & );
    void                                                 SetMaxDistance( GEFloat const & );
    void                                                 SetMinDistance( GEFloat const & );
    void                                                 SetOffset( bCVector const & );
    void                                                 SetRollOffPreset( bCString const & );
    void                                                 SetUseRollOffPreset( GEBool const & );
    void                                                 SetUseVolumeFromPreset( GEBool const & );
    void                                                 SetVolume( GEFloat const & );
public:
    gCEffectCommandPlaySound & operator = ( gCEffectCommandPlaySound const & );
public:
    gCEffectCommandPlaySound( gCEffectCommandPlaySound const & );
    gCEffectCommandPlaySound( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandPlaySound, 0x0050 )

#pragma warning( pop )

#endif
