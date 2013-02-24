#include "OnTradeInfo_ClearTradeInventory.h"

GEInt GE_STDCALL OnTradeInfo_ClearTradeInventory( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt )
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
    PSInventory & TraderInventory = Self.AccessPropertySet< PSInventory >();
    if ( TraderInventory.IsValid() )
        for ( GEInt i = TraderInventory.GetStackCount(); i--; )
            if ( TraderInventory.GetStackType( i ) == gEStackType_Trade )
                TraderInventory.DeleteStack( i );
    return 1;
}