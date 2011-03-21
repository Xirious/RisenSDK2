#ifndef GE_EFFECTCOMMANDRUNSCRIPT_H_INCLUDED
#define GE_EFFECTCOMMANDRUNSCRIPT_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandRunScript'

class GE_DLLIMPORT gCEffectCommandRunScript :
    public gCEffectCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCEffectCommandRunScript( void );
public:    virtual bCString                   GetCommandString( void ) const;
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
protected: virtual void                       OnStop( gSEffectCommandInstance & ) const;
protected: virtual GEBool                     OnProcess( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCScriptProxyScript                            m_StartScript;
    eCScriptProxyScript                            m_StopScript;
    eCScriptProxyScript                            m_ProcessScript;
    bCString                                       m_strOther;
    bTPropertyContainer< gEEffectScriptOtherType > m_enumOtherType;
    GEInt                                          m_iParam;
    bTPropertyContainer< gEEffectScriptParamType > m_enumParamType;
    GEFloat                                        m_fDuration;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &                                              AccessDuration( void );
    bCString &                                             AccessOther( void );
    bTPropertyContainer< gEEffectScriptOtherType > &       AccessOtherType( void );
    GEInt &                                                AccessParam( void );
    bTPropertyContainer< gEEffectScriptParamType > &       AccessParamType( void );
    eCScriptProxyScript &                                  AccessProcessScript( void );
    eCScriptProxyScript &                                  AccessStartScript( void );
    eCScriptProxyScript &                                  AccessStopScript( void );
    GEFloat const &                                        GetDuration( void ) const;
    bCString const &                                       GetOther( void ) const;
    bTPropertyContainer< gEEffectScriptOtherType > const & GetOtherType( void ) const;
    GEInt const &                                          GetParam( void ) const;
    bTPropertyContainer< gEEffectScriptParamType > const & GetParamType( void ) const;
    eCScriptProxyScript const &                            GetProcessScript( void ) const;
    eCScriptProxyScript const &                            GetStartScript( void ) const;
    eCScriptProxyScript const &                            GetStopScript( void ) const;
    void                                                   SetDuration( GEFloat const & );
    void                                                   SetOther( bCString const & );
    void                                                   SetOtherType( bTPropertyContainer< gEEffectScriptOtherType > const & );
    void                                                   SetParam( GEInt const & );
    void                                                   SetParamType( bTPropertyContainer< gEEffectScriptParamType > const & );
    void                                                   SetProcessScript( eCScriptProxyScript const & );
    void                                                   SetStartScript( eCScriptProxyScript const & );
    void                                                   SetStopScript( eCScriptProxyScript const & );
public:
    gCEffectCommandRunScript & operator = ( gCEffectCommandRunScript const & );
public:
    gCEffectCommandRunScript( gCEffectCommandRunScript const & );
    gCEffectCommandRunScript( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandRunScript, 0x0040 )

#pragma warning( pop )

#endif
