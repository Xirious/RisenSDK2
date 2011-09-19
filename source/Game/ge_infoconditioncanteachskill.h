#ifndef GE_INFOCONDITIONCANTEACHSKILL_H_INCLUDED
#define GE_INFOCONDITIONCANTEACHSKILL_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionCanTeachSkill :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionCanTeachSkill, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoConditionCanTeachSkill( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( gCSkillValue, m_TeachSkill, TeachSkill )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionCanTeachSkill, 0x0018 )

#endif
