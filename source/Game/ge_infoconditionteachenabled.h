#ifndef GE_INFOCONDITIONTEACHENABLED_H_INCLUDED
#define GE_INFOCONDITIONTEACHENABLED_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionTeachEnabled :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionTeachEnabled, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoConditionTeachEnabled( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( GEBool, m_bTeachEnabled, TeachEnabled )
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionTeachEnabled, 0x000C )

#endif
