#ifndef GE_EFFECTCOMMANDSPAWNENTITY_H_INCLUDED
#define GE_EFFECTCOMMANDSPAWNENTITY_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandSpawnEntity'

class GE_DLLIMPORT gCEffectCommandSpawnEntity :
    public gCEffectCommandEntity
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandSpawnEntity( void );
public: virtual GEInt                      GetCommandPriority( void ) const;
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
public: virtual GEBool                     Prefetch( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt                              m_iEntityIndex;
    eCTemplateEntityProxy              m_TemplateEntity;
    bCString                           m_strBoneName;
    bTPropertyContainer< gEEffectLink> m_enumCoordinateSystem;
    bCMotion                           m_Offset;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                  AccessBoneName( void );
    bTPropertyContainer< gEEffectLink > &       AccessCoordinateSystem( void );
    GEInt &                                     AccessEntityIndex( void );
    bCMotion &                                  AccessOffset( void );
    eCTemplateEntityProxy &                     AccessTemplateEntity( void );
    bCString const &                            GetBoneName( void ) const;
    bTPropertyContainer< gEEffectLink > const & GetCoordinateSystem( void ) const;
    GEInt const &                               GetEntityIndex( void ) const;
    bCMotion const &                            GetOffset( void ) const;
    eCTemplateEntityProxy const &               GetTemplateEntity( void ) const;
    void                                        SetBoneName( bCString const & );
    void                                        SetCoordinateSystem( bTPropertyContainer< gEEffectLink > const & );
    void                                        SetEntityIndex( GEInt const & );
    void                                        SetOffset( bCMotion const & );
    void                                        SetTemplateEntity( eCTemplateEntityProxy const & );
public:
    gCEffectCommandSpawnEntity & operator = ( gCEffectCommandSpawnEntity const & );
public:
    gCEffectCommandSpawnEntity( gCEffectCommandSpawnEntity const & );
    gCEffectCommandSpawnEntity( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandSpawnEntity, 0x0040 )

#pragma warning( pop )

#endif
