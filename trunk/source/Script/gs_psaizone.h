#ifndef GS_PSAIZONE_H_INCLUDED
#define GS_PSAIZONE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSAIZone )
public:
    GS_DECLARE_PROPERTY( Group,             bCString )
    GS_DECLARE_PROPERTY( Guild,             gEGuild )
    GS_DECLARE_PROPERTY( SecurityLevelFunc, eCScriptProxyScript )
public:
    gESecurityLevel GetSecurityLevel( void ) const;
    GEBool          IsValid( void ) const;
protected:
                  operator gCAIZone_PS *       ( void );
                  operator gCAIZone_PS const * ( void ) const;
    gCAIZone_PS * operator ->                  ( void );
public:
    gCAIZone_PS const * operator -> ( void ) const;
};

#endif
