#ifndef GE_INFOCOMMANDADDINFOSYSTEMENDSCRIPT_H_INCLUDED
#define GE_INFOCOMMANDADDINFOSYSTEMENDSCRIPT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandAddInfoSystemEndScript :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandAddInfoSystemEndScript, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual bEResult       PostInitializeProperties( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( eCScriptProxyScript, m_Script, Script )
    GE_DECLARE_PROPERTY( bCString,            m_strSelf, Self )
    GE_DECLARE_PROPERTY( bCString,            m_strOther, Other )
    GE_DECLARE_PROPERTY( GEInt,               m_iParam, Param )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandAddInfoSystemEndScript, 0x001C )

#endif
