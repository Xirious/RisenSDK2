#ifndef GE_MESSAGE_H_INCLUDED
#define GE_MESSAGE_H_INCLUDED

GE_DLLIMPORT_EXTC GEChar g_carrMsgBuffer[ 2048 ];
GE_DLLIMPORT_EXTC GEInt const g_iDefaultMessagePriority;

#ifdef _DEBUG
#define GE_MESSAGE_OK_EX( METHOD, TEXT ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_OK, TEXT, METHOD, __FILE__, __LINE__, g_iDefaultMessagePriority );
#define GE_MESSAGE_OK( TEXT ) GE_MESSAGE_OK_EX( 0, TEXT )
#define GE_MESSAGE_INFO_EX( LEVEL, METHOD, TEXT ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_Info, TEXT, METHOD, __FILE__, __LINE__, LEVEL );
#define GE_MESSAGE_INFO( LEVEL, TEXT ) GE_MESSAGE_OK_EX( LEVEL, 0, TEXT )
#define GE_MESSAGE_WARN_EX( METHOD, TEXT ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_Warn, TEXT, METHOD, __FILE__, __LINE__, g_iDefaultMessagePriority );
#define GE_MESSAGE_WARN( TEXT ) GE_MESSAGE_WARN_EX( 0, TEXT )
#else
#define GE_MESSAGE_OK_EX( METHOD, TEXT ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_OK, TEXT, METHOD, 0, -1, g_iDefaultMessagePriority );
#define GE_MESSAGE_OK( TEXT ) GE_MESSAGE_OK_EX( 0, TEXT )
#define GE_MESSAGE_INFO_EX( LEVEL, METHOD, TEXT ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_Info, TEXT, METHOD, 0, 0, LEVEL );
#define GE_MESSAGE_INFO( LEVEL, TEXT ) GE_MESSAGE_OK_EX( LEVEL, 0, TEXT )
#define GE_MESSAGE_WARN_EX( METHOD, TEXT ) bCMessageAdmin::GetInstance().OnMessage( bEMessageType_Warn, TEXT, METHOD, 0, -1, g_iDefaultMessagePriority );
#define GE_MESSAGE_WARN( TEXT ) GE_MESSAGE_WARN_EX( 0, TEXT )
#endif

//FIXME: In Debug builds this functions are implemented (and exported?).
//TODO: Fix the function names if they are exported from the SharedBase.
void GE_MESSAGEF_OK( GELPCChar a_pcFormat, ... );
void GE_MESSAGEF_OK_EX( GELPCChar a_pcMethod, GELPCChar a_pcFormat, ... );
void GE_MESSAGEF_INFO( GEInt a_iPriority, GELPCChar a_pcFormat, ... );
void GE_MESSAGEF_INFO_EX( GEInt a_iPriority, GELPCChar a_pcMethod, GELPCChar a_pcFormat, ... );
void GE_MESSAGEF_WARN( GELPCChar a_pcFormat, ... );
void GE_MESSAGEF_WARN_EX( GELPCChar a_pcMethod, GELPCChar a_pcFormat, ... );

#define GE_OBSOLETE_METHOD_EX( METHOD, DETAIL ) GE_MESSAGEF_WARN( "The obsolete method %s was called! %s", METHOD, DETAIL );
#define GE_OBSOLETE_METHOD( DETAIL ) GE_OBSOLETE_METHOD_EX( __FUNCTION__, DETAIL )

#define GE_IMPROPER_USAGE_EX( METHOD, DETAIL ) GE_MESSAGEF_WARN( "The method %s detected an improper usage! \nHint:%s ", METHOD, DETAIL );
#define GE_IMPROPER_USAGE( DETAIL ) GE_IMPROPER_USAGE_EX( __FUNCTION__, DETAIL )

#endif
