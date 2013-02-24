#include "ColShape.h"
#include "ColShape_AddBox.h"
#include "ColShape_AddMesh.h"
#include "ColShape_RemoveShapeAt.h"
#include "../m_commandhandler.h"

GEInt GE_STDCALL CON_ColShape( gCScriptProcessingUnit * a_pSPU, GELPVoid, GELPVoid, GEInt a_iArgs )
{
    return mTCommandHandler< &CON_ColShape >::HandleCommandCall( L"ColShape", L"A collection of commands dealing with eCCollisionShape_PS and related classes.", L"ColShape <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< mCCommandHandler::SSubCommandDesc > & mTCommandHandler< &CON_ColShape >::GetSubCommandDescs( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< mCCommandHandler::SSubCommandDesc > s_arrSubCommandDescs;

#pragma warning( pop )

    if ( s_arrSubCommandDescs.GetCount() == 0 )
    {
        mCCommandHandler::SSubCommandDesc Desc;

        Desc.m_strName = L"AddBox";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 3;
        Desc.m_pfuncExecute = CON_ColShape_Sub::AddBox;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Adds a collision box with the specified center and extent to a dynamic entity's CollisionShape property set.\n" \
            L"The box's orientation in world space is the identity matrix.\n" \
            L"Usage:\n" \
            L"  ColShape AddBox <GUID> <Center> <Extent>\n" \
            L"Example:\n" \
            L"  ColShape AddBox {875C4596-D2CF-4B0D-B82E-2F6417344342} [0.0,0.0,0.0] [5.0,10.0,5.0]";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"AddMesh";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 2;
        Desc.m_pfuncExecute = CON_ColShape_Sub::AddMesh;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Adds a (triangle-) collision mesh to a dynamic entity's CollisionShape property set.\n" \
            L"Usage:\n" \
            L"  ColShape AddMesh <GUID> <xcom file name>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"RemoveShapeAt";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 2;
        Desc.m_pfuncExecute = CON_ColShape_Sub::RemoveShapeAt;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Removes a collision shape from a dynamic entity's CollisionShape property set.\n" \
            L"Use \"edit <entity name>\" and navigate to eCCollisionShape_PS to see its collision shapes.\n" \
            L"Usage:\n" \
            L"  ColShape RemoveShapeAt <GUID> <Index>";
        s_arrSubCommandDescs.Add( Desc );
    }

    return s_arrSubCommandDescs;
}