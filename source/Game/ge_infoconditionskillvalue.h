#ifndef GE_INFOCONDITIONSKILLVALUE_H_INCLUDED
#define GE_INFOCONDITIONSKILLVALUE_H_INCLUDED

enum gECompareOperation
{
    gECompareOperation_Equal,
    gECompareOperation_NotEqual,
    gECompareOperation_Less,
    gECompareOperation_LessEqual,
    gECompareOperation_Greater,
    gECompareOperation_GreaterEqual,
    gECompareOperation_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInfoConditionSkillValue'

class GE_DLLIMPORT gCInfoConditionSkillValue :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionSkillValue, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoConditionSkillValue( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,           m_strEntity,            Entity )
    GE_DECLARE_ENUMPROP( gECompareOperation, m_enumCompareOperation, CompareOperation )
    GE_DECLARE_PROPERTY( gCSkillValue,       m_SkillValue,           SkillValue )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionSkillValue, 0x0024 )

#pragma warning( pop )

#endif
