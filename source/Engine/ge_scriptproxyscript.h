#ifndef GE_SCRIPTPROXYSCRIPT_H_INCLUDED
#define GE_SCRIPTPROXYSCRIPT_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT eCScriptProxyScript :
    public eCScriptProxy
{
protected: virtual eSScriptBase * QueryScript( bCString const & );  
protected: virtual void           ReleaseScript( eSScriptBase * );  
protected:
    GEInt CallScript( eCEntity *, eCEntity *, GEInt ) const;
public:
    eCScriptProxyScript & operator =  ( eCScriptProxyScript const & );
    GEInt                 operator () ( eCEntity *, eCEntity *, GEInt ) const;
public:
    eCScriptProxyScript( eCScriptProxyScript const & );
    eCScriptProxyScript( bCString const & );
    eCScriptProxyScript( eSScriptBase * );
    eCScriptProxyScript( void );
   ~eCScriptProxyScript( void );
};
GE_ASSERT_SIZEOF( eCScriptProxyScript, 0x0008 )

#pragma warning( pop )

#endif
