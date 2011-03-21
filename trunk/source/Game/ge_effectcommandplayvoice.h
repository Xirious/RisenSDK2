#ifndef GE_EFFECTCOMMANDPLAYVOICE_H_INCLUDED
#define GE_EFFECTCOMMANDPLAYVOICE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandPlayVoice'

class GE_DLLIMPORT gCEffectCommandPlayVoice :
    public gCEffectCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCEffectCommandPlayVoice( void );
public:    virtual bCString                   GetCommandString( void ) const;
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
protected: virtual void                       OnStop( gSEffectCommandInstance & ) const;
protected: virtual GEBool                     OnProcess( gSEffectCommandInstance & ) const;
public:    virtual GEBool                     Prefetch( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat                                     m_fVolume;
    GEFloat                                     m_fMinDistance;
    GEFloat                                     m_fMaxDistance;
    bTPropertyContainer< eEAudioChannelFallOff> m_enumFallOff;
    bCString                                    m_strRollOffPreset;
    GEBool                                      m_bUseRollOffPreset;
    GEBool                                      m_bUseVolumeFromPreset;
                                                GE_PADDING( 2 )
    bCString                                    m_strSample;
    GEBool                                      m_bInDialog;
                                                GE_PADDING1( 3 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< eEAudioChannelFallOff > &       AccessFallOff( void );
    GEBool &                                             AccessInDialog( void );
    GEFloat &                                            AccessMaxDistance( void );
    GEFloat &                                            AccessMinDistance( void );
    bCString &                                           AccessRollOffPreset( void );
    bCString &                                           AccessSample( void );
    GEBool &                                             AccessUseRollOffPreset( void );
    GEBool &                                             AccessUseVolumeFromPreset( void );
    GEFloat &                                            AccessVolume( void );
    bTPropertyContainer< eEAudioChannelFallOff > const & GetFallOff( void ) const;
    GEBool const &                                       GetInDialog( void ) const;
    GEFloat const &                                      GetMaxDistance( void ) const;
    GEFloat const &                                      GetMinDistance( void ) const;
    bCString const &                                     GetRollOffPreset( void ) const;
    bCString const &                                     GetSample( void ) const;
    GEBool const &                                       GetUseRollOffPreset( void ) const;
    GEBool const &                                       GetUseVolumeFromPreset( void ) const;
    GEFloat const &                                      GetVolume( void ) const;
    void                                                 SetFallOff( bTPropertyContainer< eEAudioChannelFallOff > const & );
    void                                                 SetInDialog( GEBool const & );
    void                                                 SetMaxDistance( GEFloat const & );
    void                                                 SetMinDistance( GEFloat const & );
    void                                                 SetRollOffPreset( bCString const & );
    void                                                 SetSample( bCString const & );
    void                                                 SetUseRollOffPreset( GEBool const & );
    void                                                 SetUseVolumeFromPreset( GEBool const & );
    void                                                 SetVolume( GEFloat const & );
public:
    gCEffectCommandPlayVoice & operator = ( gCEffectCommandPlayVoice const & );
public:
    gCEffectCommandPlayVoice( gCEffectCommandPlayVoice const & );
    gCEffectCommandPlayVoice( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandPlayVoice, 0x0030 )

#pragma warning( pop )

#endif
