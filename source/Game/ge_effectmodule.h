#ifndef GE_EFFECTMODULE_H_INCLUDED
#define GE_EFFECTMODULE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'gCEffectModule::CProcessor' needs to have dll-interface to be used by clients of class 'gCEffectModule'

class GE_DLLIMPORT gCEffectModule :
    public eCEffectModuleBase
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
        gCEffectModule * m_pEffectModule;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( gCEffectModule, eCEffectModuleBase )
public: virtual                     ~gCEffectModule( void );
public: virtual bEResult             Initialize( void );
public: virtual bEResult             PostInitialize( void );
public: virtual bEResult             Shutdown( void );
public: virtual void                 ApplyConfiguration( void );
public: virtual void                 Process( void );
public: virtual eCEffectSystemBase * GetSystemBase( void ) const;
protected:
    CProcessor       m_Processor;
    gCEffectSystem * m_pSystem;
public:
    static gCEffectModule & GE_STDCALL GetInstance( void );
public:
    gCEffectSystem * GetSystem( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCEffectModule, 0x0024 )

#pragma warning( pop )

#endif
