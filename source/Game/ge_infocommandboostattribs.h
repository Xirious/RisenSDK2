#ifndef GE_INFOCOMMANDBOOSTATTRIBS_H_INCLUDED
#define GE_INFOCOMMANDBOOSTATTRIBS_H_INCLUDED

enum gEBoostTarget
{
    gEBoostTarget_Strength     = 0x00000000,
    gEBoostTarget_Dexterity    = 0x00000001,
    gEBoostTarget_Intelligence = 0x00000002,
    gEBoostTarget_ForceDWORD   = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandBoostAttribs'

class GE_DLLIMPORT gCInfoCommandBoostAttribs :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandBoostAttribs( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                             m_strEntity1;
    bTPropertyContainer< gEBoostTarget > m_enumBoostTarget;
    eCEntityProxy                        m_EntityProxy1;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEBoostTarget > &       AccessBoostTarget( void );
    bCString &                                   AccessEntity1( void );
    bTPropertyContainer< gEBoostTarget > const & GetBoostTarget( void ) const;
    bCString const &                             GetEntity1( void ) const;
    void                                         SetBoostTarget( bTPropertyContainer< gEBoostTarget > const & );
    void                                         SetEntity1( bCString const & );
public:
    gCInfoCommandBoostAttribs & operator = ( gCInfoCommandBoostAttribs const & );
public:
    gCInfoCommandBoostAttribs( gCInfoCommandBoostAttribs const & );
    gCInfoCommandBoostAttribs( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandBoostAttribs, 0x001C )

#pragma warning( pop )

#endif
