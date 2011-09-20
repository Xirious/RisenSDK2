#ifndef GE_EFFECTSYSTEM_H_INCLUDED
#define GE_EFFECTSYSTEM_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCEffectSystem'
                                   // class 'eTDocObjectMap<T>' needs to have dll-interface to be used by clients of class 'gCEffectSystem'

class GE_DLLIMPORT gCEffectSystem :
    public eCEffectSystemBase
{
public: virtual GEBool   IsEffectValid( GELPVoid );
public: virtual GEBool   IsEffectFinished( GELPVoid );
// eCEffectSystemBase
public: virtual GEBool   PrefetchEffect( bCString const & );
public: virtual GELPVoid StartEffect( bCString const &, eCEntity *, eCEntity *, bCMatrix const *, GEBool );
public: virtual GEBool   StopEffect( GELPVoid, GEBool );
public: virtual void     GetEffectDependencies( bCString const &, bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public: virtual         ~gCEffectSystem( void );
protected:
    bTValArray< gCEffect * >                   m_arrRunningEffects;
    eTDocObjectMap< gCEffectCommandSequence2 > m_mapItems;
    gEEffectQuality                            m_enumEffectQuality;
public:
    gCEffectSystem( void );
    gCEffectSystem( gCEffectSystem const & );
public:
    gCEffectSystem & operator = ( gCEffectSystem const & );
public:
    void                                               ApplyConfiguration( void );
    gEEffectQuality                                    GetEffectQuality( void ) const;
    eTDocObjectMap< gCEffectCommandSequence2 > &       GetItems( void );
    eTDocObjectMap< gCEffectCommandSequence2 > const & GetItems( void ) const;
    bTValArray< gCEffect * > const &                   GetRunningEffects( void ) const;
    gCEffectCommandSequence2 *                         LoadRawEffect( bCString const &, GEBool );
    void                                               Process( GEFloat );
    GEBool                                             ReadEffects( void );
    GEBool                                             SaveRawEffect( bCString const & );
    GEBool                                             SaveRawEffectAs( bCString const &, bCString const & );
protected:
    void DeleteAllEffects( void );
    void Destroy( void );
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCEffectSystem, 0x0028 )

#pragma warning( pop )

#endif
