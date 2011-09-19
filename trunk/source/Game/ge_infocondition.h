#ifndef GE_INFOCONDITION_H_INCLUDED
#define GE_INFOCONDITION_H_INCLUDED

class GE_DLLIMPORT gCInfoCondition :
    public bCObjectRefBase
{
public: virtual bCString          GetConditionName( void ) const;
public: virtual GEBool            IsSatisfied( gCInfo const & );
public: virtual GEBool            IsValid( bCString &, gCInfo const & ) const;
public: virtual gCInfoCondition * Clone( void ) const;
GE_DECLARE_PROPERTY_OBJECT( gCInfoCondition, bCObjectRefBase )
public: virtual void              Destroy( void );
public: virtual                  ~gCInfoCondition( void );
public: using    bCObjectRefBase::IsValid;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCondition, 0x0008 )

#endif;
