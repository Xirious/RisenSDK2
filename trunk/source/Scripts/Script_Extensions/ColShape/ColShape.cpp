#include "ColShape.h"

enum { EColShape = 924 };

GEInt GE_STDCALL ColShape( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    UNREFERENCED_PARAMETER( a_pSelfEntity );
    UNREFERENCED_PARAMETER( a_pOtherEntity );

    return CmdManagement::HandleCmdCall< EColShape >( L"ColShape", L"A collection of commands dealing with eCCollisionShape_PS and related classes.", L"ColShape <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< CmdManagement::SubCmdInfo > & CmdManagement::GetSubCmdInfos< EColShape >( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< CmdManagement::SubCmdInfo > SubCommands;

#pragma warning( pop )

    if ( SubCommands.GetCount() == 0 )
    {
        CmdManagement::SubCmdInfo Info;

        Info.strName = L"AddBox";
        Info.uParamCount = 3;
        Info.pFunction = CON_ColShape::AddBox;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Adds a collision box with the specified center and extent to a dynamic entity.\n" \
            L"The box's orientation in world space is the identity matrix.\n" \
            L"Usage:\n" \
            L"  ColShape AddBox <GUID> <Center> <Extent>\n" \
            L"Example:\n" \
            L"  ColShape AddBox {875C4596-D2CF-4B0D-B82E-2F6417344342} [0.0,0.0,0.0] [5.0,10.0,5.0]";
        SubCommands.Add( Info );
        
        Info.strName = L"AddMesh";
        Info.uParamCount = 2;
        Info.pFunction = CON_ColShape::AddMesh;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Adds a (triangle-) collision mesh to a dynamic entity.\n" \
            L"Usage:\n" \
            L"  ColShape AddMesh <GUID> <xcom file name>";
        SubCommands.Add( Info );
        
        Info.strName = L"RemoveShapeAt";
        Info.uParamCount = 2;
        Info.pFunction = CON_ColShape::RemoveShapeAt;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Removes a collision shape from a dynamic entity.\n" \
            L"Use \"edit <entity name>\" and navigate to eCCollisionShape_PS to see its collision shapes.\n" \
            L"Usage:\n" \
            L"  ColShape RemoveShapeAt <GUID> <Index>";
        SubCommands.Add( Info );
    }

    return SubCommands;
}