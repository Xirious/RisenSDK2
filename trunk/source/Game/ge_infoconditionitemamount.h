#ifndef GE_INFOCONDITIONITEMAMOUNT_H_INCLUDED
#define GE_INFOCONDITIONITEMAMOUNT_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionItemAmount :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionItemAmount, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( eCEntityStringProxy,   m_Owner,         Owner )
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_Item,          Item )
    GE_DECLARE_PROPERTY( GEU32,                 m_u32ItemAmount, ItemAmount )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionItemAmount, 0x0018 )

#endif
