#ifndef GE_INFOCONDITIONOWNERINAREA_H_INCLUDED
#define GE_INFOCONDITIONOWNERINAREA_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionOwnerInArea :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionOwnerInArea, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strAreaPropertyName, AreaPropertyName )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionOwnerInArea, 0x000C )

#endif
