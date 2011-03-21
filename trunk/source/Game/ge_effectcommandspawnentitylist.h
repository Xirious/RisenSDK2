#ifndef GE_EFFECTCOMMANDSPAWNENTITYLIST_H_INCLUDED
#define GE_EFFECTCOMMANDSPAWNENTITYLIST_H_INCLUDED

struct gSEffectCommandSpawnEntityListItem
{
    eCTemplateEntityProxy __FIXME_0000;
    GEInt                 __FIXME_0004;
};
GE_ASSERT_SIZEOF( gSEffectCommandSpawnEntityListItem, 0x0008 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandSpawnEntityList'

class GE_DLLIMPORT gCEffectCommandSpawnEntityList :
    public gCEffectCommandEntity
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandSpawnEntityList( void );
public: virtual GEInt                      GetCommandPriority( void ) const;
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
public: virtual GEBool                     Prefetch( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                                         m_strBoneName;
    bTPropertyContainer< gEEffectLink >              m_enumCoordinateSystem;
    bCMotion                                         m_Offset;
    bTObjArray< gSEffectCommandSpawnEntityListItem > m_arrItems;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                               AccessBoneName( void );
    bTPropertyContainer< gEEffectLink > &                    AccessCoordinateSystem( void );
    bTObjArray< gSEffectCommandSpawnEntityListItem > &       AccessItems( void );
    bCMotion &                                               AccessOffset( void );
    bCString const &                                         GetBoneName( void ) const;
    bTPropertyContainer< gEEffectLink > const &              GetCoordinateSystem( void ) const;
    bTObjArray< gSEffectCommandSpawnEntityListItem > const & GetItems( void ) const;
    bCMotion const &                                         GetOffset( void ) const;
    void                                                     SetBoneName( bCString const & );
    void                                                     SetCoordinateSystem( bTPropertyContainer< gEEffectLink > const & );
    void                                                     SetItems( bTObjArray< gSEffectCommandSpawnEntityListItem > const & );
    void                                                     SetOffset( bCMotion const & );
public:
    gCEffectCommandSpawnEntityList & operator = ( gCEffectCommandSpawnEntityList const & );
public:
    gCEffectCommandSpawnEntityList( gCEffectCommandSpawnEntityList const & );
    gCEffectCommandSpawnEntityList( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandSpawnEntityList, 0x0044 )

#pragma warning( pop )

#endif
