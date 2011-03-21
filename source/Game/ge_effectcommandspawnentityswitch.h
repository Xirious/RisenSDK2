#ifndef GE__H_INCLUDED
#define GE__H_INCLUDED

struct gSEffectCommandSpawnEntitySwitchItem
{
    eCTemplateEntityProxy __FIXME_0000;
    GEInt                 __FIXME_0004;
};
GE_ASSERT_SIZEOF( gSEffectCommandSpawnEntitySwitchItem, 0x0008 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandSpawnEntitySwitch'

class GE_DLLIMPORT gCEffectCommandSpawnEntitySwitch :
    public gCEffectCommandEntity
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandSpawnEntitySwitch( void );
public: virtual GEInt                      GetCommandPriority( void ) const;
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
public: virtual GEBool                     Prefetch( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt                                              m_iEntityIndex;
    bCString                                           m_strBoneName;
    bTPropertyContainer< gEEffectLink >                m_enumCoordinateSystem;
    bCMotion                                           m_Offset;
    bTObjArray< gSEffectCommandSpawnEntitySwitchItem > m_arrItems;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                                 AccessBoneName( void );
    bTPropertyContainer< gEEffectLink > &                      AccessCoordinateSystem( void );
    GEInt &                                                    AccessEntityIndex( void );
    bTObjArray< gSEffectCommandSpawnEntitySwitchItem > &       AccessItems( void );
    bCMotion &                                                 AccessOffset( void );
    bCString const &                                           GetBoneName( void ) const;
    bTPropertyContainer< gEEffectLink > const &                GetCoordinateSystem( void ) const;
    GEInt const &                                              GetEntityIndex( void ) const;
    bTObjArray< gSEffectCommandSpawnEntitySwitchItem > const & GetItems( void ) const;
    bCMotion const &                                           GetOffset( void ) const;
    GEInt                                                      SelectTemplate( void ) const;
    void                                                       SetBoneName( bCString const & );
    void                                                       SetCoordinateSystem( bTPropertyContainer< gEEffectLink > const & );
    void                                                       SetEntityIndex( GEInt const & );
    void                                                       SetItems( bTObjArray< gSEffectCommandSpawnEntitySwitchItem > const & );
    void                                                       SetOffset( bCMotion const & );
public:
    gCEffectCommandSpawnEntitySwitch & operator = ( gCEffectCommandSpawnEntitySwitch const & );
public:
    gCEffectCommandSpawnEntitySwitch( gCEffectCommandSpawnEntitySwitch const & );
    gCEffectCommandSpawnEntitySwitch( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandSpawnEntitySwitch, 0x0048 )

#pragma warning( pop )

#endif
