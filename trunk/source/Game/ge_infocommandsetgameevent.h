#ifndef GE_INFOCOMMANDSETGAMEEVENT_H_INCLUDED
#define GE_INFOCOMMANDSETGAMEEVENT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSetGameEvent :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSetGameEvent, gCInfoCommand )
public:    virtual void           Destroy( void );
protected: virtual GEBool         OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual               ~gCInfoCommandSetGameEvent( void );
public:    virtual gEInfoCommand  GetCommandType( void ) const;
public:    virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public:    virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public:    using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strGameEvent, GameEvent )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSetGameEvent, 0x000C )

#endif
