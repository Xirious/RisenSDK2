#ifndef GE_EFFECT_H_INCLUDED
#define GE_EFFECT_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<>' needs to have dll-interface to be used by clients of class 'gCEffect'
                                   // class 'bTObjMap<>' needs to have dll-interface to be used by clients of class 'gCEffect'

class GE_DLLIMPORT gCEffect
{
public: virtual ~gCEffect( void );
protected:
    gCEffectCommandSequence2 *            m_pCommandSequence;
    bTObjArray< gSEffectCommandInstance > m_arrCommandInstances;
    eCEntityProxy                         m_Target;
    eCEntityProxy                         m_Owner;
    bCMatrix                              m_matTargetMatrix;
    bTObjArray< eCEntityProxy >           m_arrSpawnedEntities;
    bTObjMap< GEInt, eCEntityProxy >      m_mapSpawnedEntityMap;
    GEFloat                               m_fTime;
    GEBool                                m_bIsPermanentEnabled;
    GEBool                                __FIXME_0085;
    GEBool                                __FIXME_0086;
                                          GE_PADDING( 1 )
protected:
    void Destroy( void );
    void Invalidate( void );
    void KillSpawnees( void );
    void Reset( void );
    void StopAllCommands( void );
public:
    void                                    EnablePermanent( GEBool );
	gCEffectCommandSequence2 *              GetCommandSequence( void );
    gCEffectCommandSequence2 const *        GetCommandSequence( void ) const;
	eCEntity *                              GetOwner( void ) const;
    bTObjArray< eCEntityProxy > &           GetSpawnedEntities( void );
    bTObjArray< eCEntityProxy > const &     GetSpawnedEntities( void ) const;
    bTObjMap< GEInt, eCEntityProxy> &       GetSpawnedEntityMap( void );
    bTObjMap< GEInt, eCEntityProxy> const & GetSpawnedEntityMap( void ) const;
    eCEntity *                              GetTarget( void ) const;
    bCMatrix const &                        GetTargetMatrix( void ) const;
    GEFloat                                 GetTime( void ) const;
    GEBool                                  IsFinished( void ) const;
    GEBool                                  IsPermanentEnabled( void ) const;
    GEBool                                  IsPlayerInRange( void ) const;
    GEBool                                  Process( GEFloat );
    void                                    SetCommandSequence( gCEffectCommandSequence2 * );
    void                                    Start( eCEntity *, eCEntity *, bCMatrix const &, GEBool );
    void                                    Stop( GEBool );
public:
    gCEffect & operator = ( gCEffect const & );
public:
    gCEffect( gCEffect const & );
    gCEffect( void );
};
GE_ASSERT_SIZEOF( gCEffect, 0x0088 )

#pragma warning( pop )

#endif
