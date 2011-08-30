#ifndef GE_INFOCOMMANDSETGUARDSTATUS_H_INCLUDED
#define GE_INFOCOMMANDSETGUARDSTATUS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInfoCommandSetGuardStatus'

class GE_DLLIMPORT gCInfoCommandSetGuardStatus :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSetGuardStatus, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,      m_strEntity1,      Entity1 )
    GE_DECLARE_ENUMPROP( gEGuardStatus, m_enumGuardStatus, GuardStatus )
    eCEntityProxy                       m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSetGuardStatus, 0x001C )

#pragma warning( pop )

#endif
