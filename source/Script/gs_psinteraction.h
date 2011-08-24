#ifndef GS_PSINTERACTION_H_INCLUDED
#define GS_PSINTERACTION_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSInteraction, gCInteraction_PS )
public:
    GS_DECLARE_PROPERTY( EnterROIScript,     eCScriptProxyScript )
    GS_DECLARE_PROPERTY( ExitROIScript,      eCScriptProxyScript )
    GS_DECLARE_PROPERTY( FocusNameType,      gEFocusNameType )
    GS_DECLARE_PROPERTY( GroundBias,         GEBool )
    GS_DECLARE_PROPERTY( InteractionCounter, GEInt )
    GS_DECLARE_PROPERTY( RoutineTask,        gCScriptProxyAIState )
    GS_DECLARE_PROPERTY( UseType,            gEInteractionUseType )
public:
    Entity                  AttachToSlot( Template & );
    GEBool                  BeginInteraction( Entity );
    GEBool                  BeginInteraction( Entity, gEInteractionType );
    GEBool                  CanAttachToSlot( Template & ) const;
    GEBool                  CanInteractWith( Entity );
    GEBool                  CanInteractWith( Entity, gEInteractionType );
    GEBool                  DetachToSlot( Entity & );
    GEBool                  EndInteraction( void );
    Entity                  GetAnchorPoint( void ) const;
    eCScriptProxyScript     GetCurrentCanInteractScript( void );
    GEInt                   GetCurrentIntParam( void );
    gCScriptProxyAIFunction GetCurrentInteractScript( void );
    gCScriptProxyAIFunction GetCurrentPreInteractScript( void );
    Entity                  GetCurrentTarget( void ) const;
    Entity                  GetCurrentUser( void ) const;
    bCUnicodeString         GetFocusName( void ) const;
    Entity                  GetNavigationZone( void ) const;
    Entity                  GetOwner( void ) const;
    Entity                  GetSlotAttachedTo( void );
    GEInt                   GetSlotCount( void );
    Entity                  GetSpell( void ) const;
    gEInteractionUseType    GetUseType( void ) const;
    GEBool                  HasFreeSlot( void ) const;
    GEBool                  HasInteractionOfType( gEInteractionType );
    GEBool                  IsAttachedToSlot( void );
    GEBool                  IsAttachedToSlot( Entity & ) const;
    GEBool                  IsFreeDestination( Entity );
    GEBool                  IsValid( void ) const;
    GEBool                  PlayerUseQuickSlot( GEInt );
    GEBool                  PlayerUseStack( GEInt );
    void                    SetCurrentCanInteractScript( eCScriptProxyScript & );
    void                    SetCurrentInteractScript( gCScriptProxyAIFunction & );
    void                    SetCurrentPreInteractScript( gCScriptProxyAIFunction & );
    GEBool                  SetOwner( Entity const & );
    void                    SetSpell( Entity const & );
};

#endif
