#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <stdio.h>
#include <stdarg.h>
#include "../SharedBase.h"

namespace detail
{
    GEBool OnMessage( bEMessageTypes a_enumType, GELPCChar a_pcMessage, va_list a_pArgs = 0, GEInt a_iPriority = g_iDefaultMessagePriority )
    {
        GELPCChar pcMessage = a_pcMessage;
        if( a_pcMessage && a_pArgs )
        {
            GE_THREAD_LOCAL static char s_pcMessage[ 0x1000 ];
            if( vsprintf( s_pcMessage, a_pcMessage, a_pArgs ) > 0 )
                pcMessage = s_pcMessage;
        }
        return bCMessageAdmin::GetInstance().OnMessage( a_enumType, pcMessage, 0, 0, -1, a_iPriority );
    }

    GEBool OnMessageEx( bEMessageTypes a_enumType, GELPCChar a_pcMethod, GELPCChar a_pcMessage, va_list a_pArgs = 0, GEInt a_iPriority = g_iDefaultMessagePriority )
    {
        GELPCChar pcMessage = a_pcMessage;
        if( a_pcMethod && a_pcMessage )
        {
            GE_THREAD_LOCAL static char s_pcMessage[ 0x1000 ];
            if( sprintf( s_pcMessage, "[%s] %s", a_pcMethod, a_pcMessage ) > 0 )
                pcMessage = s_pcMessage;
        }
        return OnMessage( a_enumType, pcMessage, a_pArgs, a_iPriority );
    }
}

void GE_MESSAGEF_OK( GELPCChar a_pcFormat, ... )
{
    va_list pArgs;
    va_start( pArgs, a_pcFormat );
    detail::OnMessage( bEMessageType_OK, a_pcFormat, pArgs );
    va_end( pArgs );
}

void GE_MESSAGEF_OK_EX( GELPCChar a_pcMethod, GELPCChar a_pcFormat, ... )
{
    va_list pArgs;
    va_start( pArgs, a_pcFormat );
    detail::OnMessageEx( bEMessageType_OK, a_pcMethod, a_pcFormat, pArgs );
    va_end( pArgs );
}

void GE_MESSAGEF_INFO( GEInt a_iPriority, GELPCChar a_pcFormat, ... )
{
    va_list pArgs;
    va_start( pArgs, a_pcFormat );
    detail::OnMessage( bEMessageType_Info, a_pcFormat, pArgs, a_iPriority );
    va_end( pArgs );
}

void GE_MESSAGEF_INFO_EX( GEInt a_iPriority, GELPCChar a_pcMethod, GELPCChar a_pcFormat, ... )
{
    va_list pArgs;
    va_start( pArgs, a_pcFormat );
    detail::OnMessageEx( bEMessageType_Info, a_pcMethod, a_pcFormat, pArgs, a_iPriority );
    va_end( pArgs );
}

void GE_MESSAGEF_WARN( GELPCChar a_pcFormat, ... )
{
    va_list pArgs;
    va_start( pArgs, a_pcFormat );
    detail::OnMessage( bEMessageType_Warn, a_pcFormat, pArgs );
    va_end( pArgs );
}

void GE_MESSAGEF_WARN_EX( GELPCChar a_pcMethod, GELPCChar a_pcFormat, ... )
{
    va_list pArgs;
    va_start( pArgs, a_pcFormat );
    detail::OnMessageEx( bEMessageType_Warn, a_pcMethod, a_pcFormat, pArgs );
    va_end( pArgs );
}

