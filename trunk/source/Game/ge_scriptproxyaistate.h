#ifndef GE_SCRIPTPROXYAISTATE_H_INCLUDED
#define GE_SCRIPTPROXYAISTATE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCScriptProxyAIState :
    public eCScriptProxy
{
protected: virtual eSScriptBase * QueryScript( bCString const & );  
protected: virtual void           ReleaseScript( eSScriptBase * );  
public:
    gCScriptProxyAIState & operator = ( gCScriptProxyAIState const & );
public:
    gCScriptProxyAIState( gCScriptProxyAIState const & );
    gCScriptProxyAIState( bCString const & );
    gCScriptProxyAIState( eSScriptBase * );
    gCScriptProxyAIState( void );
   ~gCScriptProxyAIState( void );
};
GE_ASSERT_SIZEOF( gCScriptProxyAIState, 0x0008 )

#pragma warning( pop )

#endif
