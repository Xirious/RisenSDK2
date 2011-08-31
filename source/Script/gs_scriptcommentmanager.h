#ifndef GS_SCRIPTCOMMENTMANAGER_H_INCLUDED
#define GS_SCRIPTCOMMENTMANAGER_H_INCLUDED

//NOTE: ScriptCommentManager is not used in the original scripts.

enum ECommentType
{
    ECommentType_0,
    ECommentType_1,
    ECommentType_2,
    ECommentType_3,
    ECommentType_4,
    ECommentType_5,
    ECommentType_6,
    ECommentType_7,
    ECommentType_8,
    ECommentType_9,
    ECommentType_10,
    ECommentType_11,
    ECommentType_12,
    ECommentType_13,
    ECommentType_14,
    ECommentType_Count,
    ECommentType_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT ScriptCommentManager
{
protected:
    GEFloat m_pfPlayingTimes[ ECommentType_Count ];
public:
    GEBool CanComment( Entity, ECommentType );
    GEBool SaySVM( Entity, Entity, ECommentType, bCString );
private:
    ScriptCommentManager( void );  // hide constructor
   ~ScriptCommentManager( void );  // hide destructor
private:
    ScriptCommentManager & operator = ( ScriptCommentManager const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC ScriptCommentManager CommentManager;

#endif
