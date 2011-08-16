#ifndef GE_COMBATAI_H_INCLUDED
#define GE_COMBATAI_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatAI'

class GE_DLLIMPORT gCCombatAI :
    public gCCombatObject
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatAI( void );
public:    virtual gECombatMove               SelectNextMove( gCCombatSystem_PS *, eCGeometryEntity *, gECombatMove );
public:    virtual gECombatMove               SelectComboMove( gCCombatSystem_PS *, eCGeometryEntity *, gECombatMove );
public:    virtual GEBool                     IsToNear( gCCombatSystem_PS *, GEFloat );
public:    virtual GEBool                     IsToFar( gCCombatSystem_PS *, GEFloat );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEWalkMode > m_enumCombatWalkMode;
    GEFloat                           m_fMinDistance;
    GEFloat                           m_fMaxDistance;
    GEFloat                           m_fMinWalkDuration;
    GEFloat                           m_fMaxWalkDuration;
    GEFloat                           m_fMinWaitDuration;
    GEFloat                           m_fMaxWaitDuration;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEWalkMode > &       AccessCombatWalkMode( void );
    GEFloat &                                 AccessMaxDistance( void );
    GEFloat &                                 AccessMaxWaitDuration( void );
    GEFloat &                                 AccessMaxWalkDuration( void );
    GEFloat &                                 AccessMinDistance( void );
    GEFloat &                                 AccessMinWaitDuration( void );
    GEFloat &                                 AccessMinWalkDuration( void );
    bTPropertyContainer< gEWalkMode > const & GetCombatWalkMode( void ) const;
    GEBool                                    GetDistance( gCCombatSystem_PS *, eCGeometryEntity *, GEFloat & );
    GEBool                                    GetDistance( gCCombatSystem_PS *, eCGeometryEntity *, GEFloat, GEFloat & );
    GEFloat const &                           GetMaxDistance( void ) const;
    GEFloat const &                           GetMaxWaitDuration( void ) const;
    GEFloat const &                           GetMaxWalkDuration( void ) const;
    GEFloat const &                           GetMinDistance( void ) const;
    GEFloat const &                           GetMinWaitDuration( void ) const;
    GEFloat const &                           GetMinWalkDuration( void ) const;
    GEBool                                    IsFreeLOS( gCCombatSystem_PS *, eCGeometryEntity * );
    GEBool                                    IsToFar( gCCombatSystem_PS *, eCGeometryEntity * );
    GEBool                                    IsToNear( gCCombatSystem_PS *, eCGeometryEntity * );
    void                                      SetCombatWalkMode( bTPropertyContainer< gEWalkMode > const & );
    void                                      SetMaxDistance( GEFloat const & );
    void                                      SetMaxWaitDuration( GEFloat const & );
    void                                      SetMaxWalkDuration( GEFloat const & );
    void                                      SetMinDistance( GEFloat const & );
    void                                      SetMinWaitDuration( GEFloat const & );
    void                                      SetMinWalkDuration( GEFloat const & );
public:
    gCCombatAI & operator = ( gCCombatAI const & );
public:
    gCCombatAI( gCCombatAI const & );
    gCCombatAI( void );
};
GE_ASSERT_SIZEOF( gCCombatAI, 0x0030 )

#pragma warning( pop )

#endif
