#ifndef GE_GFXOBJECT_H_INCLUDED
#define GE_GFXOBJECT_H_INCLUDED

class GE_DLLIMPORT eCGfxObject :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          
public:    virtual                           ~eCGfxObject( void );                  
private:
    static bCPropertyObjectTypeBase thisType;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCGfxObject & operator = ( eCGfxObject const & );
public:
    eCGfxObject( eCGfxObject const & );
    eCGfxObject( void );
};

GE_ASSERT_SIZEOF( eCGfxObject, 0x0008 )

#endif
