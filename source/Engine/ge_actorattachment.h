#ifndef GE_ACTORATTACHMENT_H_INCLUDED
#define GE_ACTORATTACHMENT_H_INCLUDED

class GE_DLLIMPORT eCActorAttachment
{
public:
    typedef GEBool (GE_STDCALL * eFUpdateCallback)( eCActorAttachment * );
protected:
    eCAnimation_PS * m_pAnimationPS;
    eCEntityProxy    m_Entity;
    bCMatrix         m_matTransform;
    bCString         m_strSlot;
    GEInt            m_iSlot;
    GEU8             m_u8Flags;
                     GE_PADDING( 3 )
    GEU32            m_u32LifeTimeEnd;
    eFUpdateCallback m_funcUpdateCallback;
public:
    void             Create( eCAnimation_PS *, eCGeometryEntity *, bCString const &, bCMatrix const *, GEU32, GEBool );
    void             Destroy( void );
    eCAnimation_PS * GetAnimationPS( void ) const;
    eCEntity *       GetEntity( void );
    bCMatrix const & GetTransform( void ) const;
    eFUpdateCallback GetUpdateCallback( void ) const;
    GEBool           IsEntityValid( void );
    GEBool           Process( GEU32 );
    void             SetLifeTime( GEU32 );
    void             SetTransform( bCMatrix const & );
    void             SetUpdateCallback( eFUpdateCallback );
public:
    eCActorAttachment & operator = ( eCActorAttachment const & );
public:
    eCActorAttachment( eCActorAttachment const & );
    eCActorAttachment( void );
   ~eCActorAttachment( void );
};
GE_ASSERT_SIZEOF( eCActorAttachment, 0x0060 )

#endif
