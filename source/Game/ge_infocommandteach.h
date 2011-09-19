#ifndef GE_INFOCOMMANDTEACH_H_INCLUDED
#define GE_INFOCOMMANDTEACH_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandTeach :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandTeach, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandTeach( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual GEBool          GetDialogDescription( SDialogDescription *, gCRuntimeInfo * );
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,     m_strEntity1, Entity1 )
    GE_DECLARE_PROPERTY( gCSkillValue, m_TeachSkill, TeachSkill )
    eCEntityProxy                      m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandTeach, 0x0024 )

#endif
