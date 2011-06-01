#ifndef GE_SCRIPTPROXYAIFUNCTION_H_INCLUDED
#define GE_SCRIPTPROXYAIFUNCTION_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCScriptProxyAIFunction :
    public eCScriptProxy
{
protected: virtual eSScriptBase * QueryScript( bCString const & );  
protected: virtual void           ReleaseScript( eSScriptBase * );  
public:
    gCScriptProxyAIFunction & operator = ( gCScriptProxyAIFunction const & );
public:
    gCScriptProxyAIFunction( gCScriptProxyAIFunction const & );
    gCScriptProxyAIFunction( bCString const & );
    gCScriptProxyAIFunction( eSScriptBase * );
    gCScriptProxyAIFunction( void );
   ~gCScriptProxyAIFunction( void );
};
GE_ASSERT_SIZEOF( gCScriptProxyAIFunction, 0x0008 )

#pragma warning( pop )

#endif
