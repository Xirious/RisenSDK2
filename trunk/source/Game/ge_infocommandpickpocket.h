#ifndef GE_INFOCOMMANDPICKPOCKET_H_INCLUDED
#define GE_INFOCOMMANDPICKPOCKET_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandPickPocket'

class GE_DLLIMPORT gCInfoCommandPickPocket :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandPickPocket( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual gEInfoCommand              GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy &            GetEntityProxy2( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual void                       GetTableKeys( bTObjArray< bCString > & );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
public: virtual void                       OnAttachedToInfo( gCInfo const & );
public: virtual bCString                   ToString( void ) const;
public: virtual void                       FromString( bCString const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEU32                                m_u32Difficulty;
    bCString                             m_strSpeaker;
    bCString                             m_strListener;
    gCInfoLocString                      m_locText;
    bCString                             m_strSVMID;
    gCInfoLocString                      m_locSVMText;
    bTPropertyContainer< gEInfoGesture > m_enumGesture;
    eCEntityProxy                        m_EntityProxy1;
    eCEntityProxy                        m_EntityProxy2;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &                                      AccessDifficulty( void );
    bTPropertyContainer< gEInfoGesture > &       AccessGesture( void );
    bCString &                                   AccessListener( void );
    bCString &                                   AccessSVMID( void );
    gCInfoLocString &                            AccessSVMText( void );
    bCString &                                   AccessSpeaker( void );
    gCInfoLocString &                            AccessText( void );
    GEU32 const &                                GetDifficulty( void ) const;
    bTPropertyContainer< gEInfoGesture > const & GetGesture( void ) const;
    bCString const &                             GetListener( void ) const;
    bCString const &                             GetSVMID( void ) const;
    gCInfoLocString const &                      GetSVMText( void ) const;
    bCString const &                             GetSpeaker( void ) const;
    gCInfoLocString const &                      GetText( void ) const;
    void                                         SetDifficulty( GEU32 const & );
    void                                         SetGesture( bTPropertyContainer< gEInfoGesture > const & );
    void                                         SetListener( bCString const & );
    void                                         SetSVMID( bCString const & );
    void                                         SetSVMText( gCInfoLocString const & );
    void                                         SetSpeaker( bCString const & );
    void                                         SetText( gCInfoLocString const & );
public:
    gCInfoCommandPickPocket & operator = ( gCInfoCommandPickPocket const & );
public:
    gCInfoCommandPickPocket( gCInfoCommandPickPocket const & );
    gCInfoCommandPickPocket( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandPickPocket, 0x0048 )

#pragma warning( pop )

#endif
