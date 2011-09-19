#ifndef GE_INFOCONDITIONPLAYERNOTKNOWS_H_INCLUDED
#define GE_INFOCONDITIONPLAYERNOTKNOWS_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionPlayerNotKnows :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionPlayerNotKnows, gCInfoCondition )
public:    virtual void           Destroy( void );
protected: virtual GEBool         OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual               ~gCInfoConditionPlayerNotKnows( void );
public:    virtual GEBool         IsSatisfied( gCInfo const & );
public:    virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public:    using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strPlayerNotKnows, PlayerNotKnows )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionPlayerNotKnows, 0x000C )

#endif
