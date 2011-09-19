#ifndef GE_INFOCONDITIONOWNERNEARENTITY_H_INCLUDED
#define GE_INFOCONDITIONOWNERNEARENTITY_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionOwnerNearEntity :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionOwnerNearEntity, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoConditionOwnerNearEntity( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( eCEntityStringProxy, m_Entity, Entity )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionOwnerNearEntity, 0x0010 )

#endif
