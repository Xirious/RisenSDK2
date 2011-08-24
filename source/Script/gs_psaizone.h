#ifndef GS_PSAIZONE_H_INCLUDED
#define GS_PSAIZONE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSAIZone, gCAIZone_PS )
public:
    GS_DECLARE_PROPERTY( Group,             bCString )
    GS_DECLARE_PROPERTY( Guild,             gEGuild )
    GS_DECLARE_PROPERTY( SecurityLevelFunc, eCScriptProxyScript )
public:
    gESecurityLevel GetSecurityLevel( void ) const;
    GEBool          IsValid( void ) const;
};

#endif
