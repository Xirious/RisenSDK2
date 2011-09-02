#ifndef GS_SCRIPTDESTINATIONCOLLECTOR_H_INCLUDED
#define GS_SCRIPTDESTINATIONCOLLECTOR_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<T>' needs to have dll-interface to be used by clients of class 'ScriptDestinationCollector'

class GE_DLLIMPORT ScriptDestinationCollector
{
protected:
    eCEntity *               m_pEntity;
    eCEntity const *         m_pCurrentDestination;
    eCEntity *               m_pInteractionAnchor;
    eCPortalRoom_PS *        m_pPortalRoom;
    bTPtrArray< eCEntity * > m_arrChoices;
public:
    ScriptDestinationCollector( Entity const & );
    ScriptDestinationCollector( Entity const &, GEBool );
    ScriptDestinationCollector( ScriptDestinationCollector const & );
   ~ScriptDestinationCollector( void );
public:
    ScriptDestinationCollector & operator = ( ScriptDestinationCollector const & );
public:
    void   AddChoice( gEInteractionUseType, GEInt, GEFloat );
    Entity GetAlternative( Entity &, GEInt, GEFloat );
    void   Init( Entity const &, GEBool );
    Entity Pick( gEInteractionUseType, GEFloat );
    Entity PickFirstValidChoice( void );
    Entity PickRandomChoice( void );
protected:
    static GEInt GE_CCALL SortEntities( GELPCVoid, GELPCVoid );
protected:
    eCEntity * FindNearestFreeDestination( gEInteractionUseType, GEFloat );
};
GE_ASSERT_SIZEOF( ScriptDestinationCollector, 0x001C )

#pragma warning( pop )

#endif
