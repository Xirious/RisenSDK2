#ifndef GE_MESSAGE_H_INCLUDED
#define GE_MESSAGE_H_INCLUDED

GE_C_LINKAGE GE_DLLIMPORT GEChar g_carrMsgBuffer[ 2048 ];
GE_C_LINKAGE GE_DLLIMPORT GEInt const g_iDefaultMessagePriority;

#ifdef _DEBUG
#define GE_MESSAGE_OK( MESSAGE ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_OK, MESSAGE, 0, __FILE__, __LINE__, g_iDefaultMessagePriority )
#define GE_MESSAGE_OK_EX( MESSAGE, DETAIL ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_OK, MESSAGE, DETAIL, __FILE__, __LINE__, g_iDefaultMessagePriority )
#define GE_MESSAGE_WARN( MESSAGE ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_Warn, MESSAGE, 0, __FILE__, __LINE__, g_iDefaultMessagePriority )
#define GE_MESSAGE_WARN_EX( MESSAGE, DETAIL ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_Warn, MESSAGE, DETAIL, __FILE__, __LINE__, g_iDefaultMessagePriority )
#else
#define GE_MESSAGE_OK( MESSAGE )
#define GE_MESSAGE_OK_EX( MESSAGE, DETAIL )
#define GE_MESSAGE_WARN( MESSAGE )
#define GE_MESSAGE_WARN_EX( MESSAGE, DETAIL )
#endif

#define GE_MESSAGE( PRIORITY, MESSAGE )
#define GE_MESSAGE_INFO( PRIORITY, MESSAGE )
#define GE_MESSAGE_INFO_EX( PRIORITY, MESSAGE, DETAIL )
//FIXME: In Debug builds this functions are implemented (and exported?).
//TODO: Fix the function names if they are exported from the SharedBase.
void GE_MESSAGEF_OK( GELPCChar, ... );
void GE_MESSAGEF_OK_EX( GELPCChar, GELPCChar, ... );
void GE_MESSAGEF_INFO( GEInt, GELPCChar, ... );
void GE_MESSAGEF_INFO_EX( GEInt, GELPCChar, GELPCChar, ... );
void GE_MESSAGEF_WARN( GELPCChar, ... );
void GE_MESSAGEF_WARN_EX( GELPCChar, GELPCChar, ... );

#define GE_OBSOLETE_METHOD( METHOD, DETAIL ) GE_MESSAGEF_WARN( "The obsolete method %s was called! %s", METHOD, DETAIL )
#define GE_OBSOLETE_METHOD_EX( DETAIL ) GE_OBSOLETE_METHOD( __FUNCTION__, DETAIL )

#define GE_IMPROPER_USAGE( METHOD, DETAIL ) GE_MESSAGEF_WARN( "The method %s detected an improper usage! \nHint:%s ", METHOD, DETAIL )
#define GE_IMPROPER_USAGE_EX( DETAIL ) GE_IMPROPER_USAGE( __FUNCTION__, DETAIL )

#endif
