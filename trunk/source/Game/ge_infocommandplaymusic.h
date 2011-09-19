#ifndef GE_INFOCOMMANDPLAYMUSIC_H_INCLUDED
#define GE_INFOCOMMANDPLAYMUSIC_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandPlayMusic :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandPlayMusic, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoCommandPlayMusic( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strSituation, Situation )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandPlayMusic, 0x000C )

#endif
