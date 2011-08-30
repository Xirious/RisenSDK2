#ifndef GE_INFOCOMMANDTHINK_H_INCLUDED
#define GE_INFOCOMMANDTHINK_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInfoCommandThink'

class GE_DLLIMPORT gCInfoCommandThink :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandThink, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual void            GetTableKeys( bTObjArray< bCString > & );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,        m_strSpeaker,  Speaker )
    GE_DECLARE_PROPERTY( gCInfoLocString, m_locText,     Text )
    GE_DECLARE_ENUMPROP( gEInfoGesture,   m_enumGesture, Gesture )
    eCEntityProxy                         m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandThink, 0x0028 )

#pragma warning( pop )

#endif
