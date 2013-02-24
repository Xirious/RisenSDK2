#include "OnTradeInfo_CreateTradeItems.h"

GEInt GE_STDCALL OnTradeInfo_CreateTradeItems( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    Entity Self;
    Entity Other;
    if ( a_pSelfEntity )
        Self = *static_cast< Entity * >( a_pSelfEntity );
    else
        Self.AttachTo( a_pSPU->GetSelfEntity() );
    if ( a_pOtherEntity )
        Other = *static_cast< Entity * >( a_pOtherEntity );
    else
        Other.AttachTo( a_pSPU->GetOtherEntity() );
    Template ItemTemplate = Other.GetTemplate();
    if ( Self.GetPropertySet< PSInventory >().IsValid() && ItemTemplate.IsValid() )
        Self.AccessPropertySet< PSInventory >().CreateItems( ItemTemplate, a_iArgs, gEStackType_Trade );
    return 1;
}