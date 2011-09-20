#ifndef GE_EFFECTSYSTEMBASE_H_INCLUDED
#define GE_EFFECTSYSTEMBASE_H_INCLUDED

class GE_DLLIMPORT eCEffectSystemBase
{
public: virtual GEBool   PrefetchEffect( bCString const & ) = 0;
public: virtual GELPVoid StartEffect( bCString const &, eCEntity *, eCEntity *, bCMatrix const *, GEBool ) = 0;
public: virtual GEBool   StopEffect( GELPVoid, GEBool ) = 0;
public: virtual void     GetEffectDependencies( bCString const &, bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & ) = 0;
public: virtual         ~eCEffectSystemBase( void );
public:
    eCEffectSystemBase( void );
    eCEffectSystemBase( eCEffectSystemBase const & );
public:
    eCEffectSystemBase & operator = ( eCEffectSystemBase const & );
};
GE_ASSERT_SIZEOF( eCEffectSystemBase, 0x0004 )

#endif
