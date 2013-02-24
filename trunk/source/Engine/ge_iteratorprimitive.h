#ifndef GE_ITERATORPRIMITIVE_H_INCLUDED
#define GE_ITERATORPRIMITIVE_H_INCLUDED

class GE_DLLIMPORT eCIteratorPrimitive
{
public: virtual void     Destroy( void );
public: virtual bEResult Create( void );
public: virtual bEResult CopyFrom( eCIteratorPrimitive const & );
public: virtual void     Render( bCMatrix const *, eCGfxShared::eECmpFunc, GEBool, GEU8 );
public: virtual GEBool   IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCPrimitiveCollisionDesc * * ) const;
public: virtual GEBool   IntersectsVolume( bCVolume &, bCMatrix const &, GEBool ) const;
public: virtual         ~eCIteratorPrimitive( void );
public:
    eCIteratorPrimitive( eCIteratorPrimitive const & );
    eCIteratorPrimitive( void );
public:
    eCIteratorPrimitive & operator = ( eCIteratorPrimitive const & );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCIteratorPrimitive, 0x0004 );

#endif