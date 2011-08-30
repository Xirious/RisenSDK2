#ifndef GE_INFOCONDITIONQUESTSTATUS_H_INCLUDED
#define GE_INFOCONDITIONQUESTSTATUS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInfoConditionQuestStatus'

class GE_DLLIMPORT gCInfoConditionQuestStatus :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionQuestStatus, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,       m_strQuest,         Quest )
    GE_DECLARE_ENUMPROP( gEInfoCondType, m_enumCondType,     CondType )
    GE_DECLARE_PROPERTY( GEBool,         m_bIsCurrentStatus, IsCurrentStatus )
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionQuestStatus, 0x0018 )

#pragma warning( pop )

#endif
