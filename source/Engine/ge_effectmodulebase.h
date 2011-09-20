#ifndef GE_EFFECTMODULEBASE_H_INCLUDED
#define GE_EFFECTMODULEBASE_H_INCLUDED

class GE_DLLIMPORT eCEffectModuleBase :
    public eCEngineComponentBase
{
public: virtual eCEffectSystemBase * GetSystemBase( void ) const = 0;
// eCEngineComponentBase
public: virtual                     ~eCEffectModuleBase( void );
public:
    eCEffectModuleBase( void );
    eCEffectModuleBase( eCEffectModuleBase const & );
public:
    eCEffectModuleBase & operator = ( eCEffectModuleBase const & );
};
GE_ASSERT_SIZEOF( eCEffectModuleBase, 0x0010 )

#endif
