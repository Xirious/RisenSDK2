#ifndef GE_INTERACTION_H_INCLUDED
#define GE_INTERACTION_H_INCLUDED

enum gEInteractionType
{
    gEInteractionType_Interact_NPC        = 0x00000000,
    gEInteractionType_Interact_Player     = 0x00000001,
    gEInteractionType_InventoryUse_Player = 0x00000002,
    gEInteractionType_QuickUse_Player     = 0x00000003,
    gEInteractionType_Magic               = 0x00000004,
    gEInteractionType_ForceDWORD          = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInteraction'

class GE_DLLIMPORT gCInteraction :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual                           ~gCInteraction( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEInteractionType > m_enumType;
    eCScriptProxyScript                      m_CanInteractScript;
    gCScriptProxyAIFunction                  m_PreInteractScript;
    gCScriptProxyAIFunction                  m_InteractScript;
    eCScriptProxyScript                      m_PostInteractScript;
    gCInteraction_PS *                       m_pInteractiveObject;
protected:
    void Invalidate( void );
    void SetInteractiveObject( gCInteraction_PS * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCScriptProxyScript &                            AccessCanInteractScript( void );
    gCScriptProxyAIFunction &                        AccessInteractScript( void );
    eCScriptProxyScript &                            AccessPostInteractScript( void );
    gCScriptProxyAIFunction &                        AccessPreInteractScript( void );
    bTPropertyContainer< gEInteractionType > &       AccessType( void );
    GEBool                                           BeginInteraction( eCEntity *, GEInt );
    GEBool                                           CanInteractWith( eCEntity *, GEInt ) const;
    GEBool                                           EndInteraction( eCEntity * );
    eCScriptProxyScript const &                      GetCanInteractScript( void ) const;
    gCScriptProxyAIFunction const &                  GetInteractScript( void ) const;
    gCInteraction_PS *                               GetInteractiveObject( void ) const;
    eCScriptProxyScript const &                      GetPostInteractScript( void ) const;
    gCScriptProxyAIFunction const &                  GetPreInteractScript( void ) const;
    bTPropertyContainer< gEInteractionType > const & GetType( void ) const;
    void                                             SetCanInteractScript( eCScriptProxyScript const & );
    void                                             SetInteractScript( gCScriptProxyAIFunction const & );
    void                                             SetPostInteractScript( eCScriptProxyScript const & );
    void                                             SetPreInteractScript( gCScriptProxyAIFunction const & );
    void                                             SetType( bTPropertyContainer< gEInteractionType > const & );
public:
    gCInteraction & operator = ( gCInteraction const & );
public:
    gCInteraction( gCInteraction const & );
    gCInteraction( void );
};
GE_ASSERT_SIZEOF( gCInteraction, 0x0034 )

#pragma warning( pop )

#endif
