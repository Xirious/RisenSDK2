#ifndef GS_QUESTMANAGER_H_INCLUDED
#define GS_QUESTMANAGER_H_INCLUDED

class GE_DLLIMPORT QuestManager
{
public:
    static GEBool GE_STDCALL CancelQuest( bCString const & );
    static GEBool GE_STDCALL CloseQuest( bCString const & );
    static GEBool GE_STDCALL FailQuest( bCString const & );
    static GEBool GE_STDCALL InsertQuestActor( bCString const &, bCString const &, gEQuestActor );
    static GEBool GE_STDCALL IsCancelled( bCString const & );
    static GEBool GE_STDCALL IsFailed( bCString const & );
    static GEBool GE_STDCALL IsFinished( bCString const & );
    static GEBool GE_STDCALL IsObsolete( bCString const & );
    static GEBool GE_STDCALL IsOpen( bCString const & );
    static GEBool GE_STDCALL IsRunning( bCString const & );
    static GEBool GE_STDCALL IsSucceeded( bCString const & );
    static GEBool GE_STDCALL OnEnter( Entity const &, bCString const & );
    static GEBool GE_STDCALL OnLeave( Entity const &, bCString const & );
    static GEBool GE_STDCALL OnNPCDefeated( Entity const & );
    static GEBool GE_STDCALL OnNPCKilled( Entity const & );
    static GEBool GE_STDCALL OpenQuest( bCString const & );
    static GEBool GE_STDCALL RemoveQuestActor( bCString const &, bCString const &, gEQuestActor );
    static GEBool GE_STDCALL RunQuest( bCString const & );
    static GEBool GE_STDCALL SucceedQuest( bCString const & );
private:
    QuestManager( void );                  // not defined
    QuestManager( QuestManager const & );  // not defined
private:
    QuestManager & operator = ( QuestManager const & );  // hide copy assignment operator
};

#endif
