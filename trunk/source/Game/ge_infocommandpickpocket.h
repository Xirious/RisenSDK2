#ifndef GE_INFOCOMMANDPICKPOCKET_H_INCLUDED
#define GE_INFOCOMMANDPICKPOCKET_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandPickPocket'

class GE_DLLIMPORT gCInfoCommandPickPocket :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandPickPocket, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual void            GetTableKeys( bTObjArray< bCString > & );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: virtual void            OnAttachedToInfo( gCInfo const & );
public: virtual bCString        ToString( void ) const;
public: virtual void            FromString( bCString const & );
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( GEU32,           m_u32Difficulty, Difficulty )
    GE_DECLARE_PROPERTY( bCString,        m_strSpeaker,    Speaker )
    GE_DECLARE_PROPERTY( bCString,        m_strListener,   Listener )
    GE_DECLARE_PROPERTY( gCInfoLocString, m_locText,       Text )
    GE_DECLARE_PROPERTY( bCString,        m_strSVMID,      SVMID )
    GE_DECLARE_PROPERTY( gCInfoLocString, m_locSVMText,    SVMText )
    GE_DECLARE_ENUMPROP( gEInfoGesture,   m_enumGesture,   Gesture )
    eCEntityProxy                         m_EntityProxy1;
    eCEntityProxy                         m_EntityProxy2;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandPickPocket, 0x0048 )

#pragma warning( pop )

#endif
