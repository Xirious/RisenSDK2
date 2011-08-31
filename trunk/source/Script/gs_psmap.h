#ifndef GS_PSMAP_H_INCLUDED
#define GS_PSMAP_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSMap, gCMap_PS )
public:
    GS_DECLARE_PROPERTY( Priority, GEU32 )
public:
    GEBool  CanUse( void ) const;
    GEBool  ContainsContent( void ) const;
    GEBool  ContainsEntity( bCString const & ) const;
    GEBool  ContainsQuest( bCString const & ) const;
    GEFloat GetImageAspectRatio( void ) const;
    GEFloat GetWorldAspectRatio( void ) const;
    GEU32   GetWorldSize( void ) const;
    GEBool  InsertEntity( bCString const &, bCString const & );
    GEBool  InsertQuest( bCString const & );
    GEBool  IsValid( void ) const;
    GEBool  RemoveEntity( bCString const &, bCString const & );
    GEBool  RemoveQuest( bCString const & );
};

#endif
