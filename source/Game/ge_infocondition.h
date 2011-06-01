#ifndef GE_INFOCONDITION_H_INCLUDED
#define GE_INFOCONDITION_H_INCLUDED

class GE_DLLIMPORT gCInfoCondition :
    public bCObjectRefBase
{
public: virtual bCString                   GetConditionName( void ) const;
public: virtual GEBool                     IsSatisfied( gCInfo const & );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
public: virtual gCInfoCondition *          Clone( void ) const;
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCondition( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCInfoCondition & operator = ( gCInfoCondition const & );
public:
    gCInfoCondition( gCInfoCondition const & );
    gCInfoCondition( void );
};
GE_ASSERT_SIZEOF( gCInfoCondition, 0x0008 )

#endif;
