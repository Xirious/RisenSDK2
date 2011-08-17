#ifndef GE_COMBATMOVESCRIPTSTATE_H_INCLUDED
#define GE_COMBATMOVESCRIPTSTATE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatMoveScriptState'

class GE_DLLIMPORT gCCombatMoveScriptState :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveScriptState( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gECombatAction> m_enumMoveCombatAction;
    gCScriptProxyAIFunction              m_AIFunction;
    eCScriptProxyScript                  m_OnGetFAIWeight;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCScriptProxyAIFunction &                     AccessAIFunction( void );
    bTPropertyContainer< gECombatAction > &       AccessMoveCombatAction( void );
    eCScriptProxyScript &                         AccessOnGetFAIWeight( void );
    gCScriptProxyAIFunction const &               GetAIFunction( void ) const;
    bTPropertyContainer< gECombatAction > const & GetMoveCombatAction( void ) const;
    eCScriptProxyScript const &                   GetOnGetFAIWeight( void ) const;
    void                                          SetAIFunction( gCScriptProxyAIFunction const & );
    void                                          SetMoveCombatAction( bTPropertyContainer< gECombatAction > const & );
    void                                          SetOnGetFAIWeight( eCScriptProxyScript const & );
public:
    gCCombatMoveScriptState & operator = ( gCCombatMoveScriptState const & );
public:
    gCCombatMoveScriptState( gCCombatMoveScriptState const & );
    gCCombatMoveScriptState( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveScriptState, 0x002C )

#pragma warning( pop )

#endif
