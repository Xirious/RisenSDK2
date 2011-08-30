#ifndef GE_INFOCONDITIONPLAYERKNOWS_H_INCLUDED
#define GE_INFOCONDITIONPLAYERKNOWS_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionPlayerKnows :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionPlayerKnows, gCInfoCondition )
public:    virtual void           Destroy( void );
protected: virtual GEBool         OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual GEBool         IsSatisfied( gCInfo const & );
public:    virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public:    using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strPlayerKnows, PlayerKnows )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionPlayerKnows, 0x000C )

#endif
