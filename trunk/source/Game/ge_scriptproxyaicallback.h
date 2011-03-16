#ifndef GE_SCRIPTPROXYAICALLBACK_H_INCLUDED
#define GE_SCRIPTPROXYAICALLBACK_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCScriptProxyAICallback :
    public eCScriptProxy
{
protected: virtual eSScriptBase * QueryScript( bCString const & );  // [0000].0000
protected: virtual void           ReleaseScript( eSScriptBase * );  // [0000].0004
public:
    gCScriptProxyAICallback & operator = ( gCScriptProxyAICallback const & );
public:
    gCScriptProxyAICallback( gCScriptProxyAICallback const & );
    gCScriptProxyAICallback( bCString const & );
    gCScriptProxyAICallback( eSScriptBase * );
    gCScriptProxyAICallback( void );
   ~gCScriptProxyAICallback( void );
};
GE_ASSERT_SIZEOF( gCScriptProxyAICallback, 0x0008 )

#pragma warning( pop )

#endif
