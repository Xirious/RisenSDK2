#include "OnTradeInfo_RemoveTradeItems.h"

GEInt GE_STDCALL OnTradeInfo_RemoveTradeItems( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
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
    PSInventory & TraderInventory = Self.AccessPropertySet< PSInventory >();
    if ( !ItemTemplate.IsValid() || !TraderInventory.IsValid() )
        return 1;
    GEInt iStackIndex = TraderInventory.FindStackIndex( ItemTemplate, gEStackType_Trade, -1, GETrue );
    if ( iStackIndex >= 0 )
    {
        GEUInt uMax = static_cast< GEUInt >( TraderInventory.GetAmount( iStackIndex ) );
        if ( static_cast< GEUInt >( a_iArgs ) > uMax )
            a_iArgs = static_cast< GEInt >( uMax );
        TraderInventory.DeleteItems( iStackIndex, a_iArgs );
    }
    return 1;
}