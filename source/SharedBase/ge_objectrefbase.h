#ifndef GE_OBJECTREFBASE_H_INCLUDED
#define GE_OBJECTREFBASE_H_INCLUDED

#define GE_ADDREF( OBJECT )     \
{                               \
    if( 0 != OBJECT )           \
    {                           \
        OBJECT->AddReference(); \
    }                           \
}
#define GE_RELEASE( OBJECT )        \
{                                   \
    if( 0 != OBJECT )               \
    {                               \
        OBJECT->ReleaseReference(); \
        OBJECT = 0;                 \
    }                               \
}
#define GE_RELEASE_REF( OBJECT )    \
{                                   \
    if( 0 != OBJECT )               \
    {                               \
        OBJECT->ReleaseReference(); \
    }                               \
}

//NOTE: 'const' attribute missing in bCObjectBase::GetReferenceCount.

class GE_DLLIMPORT bCObjectRefBase :
    public bCObjectBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          
public:    virtual GEU16                      GetVersion( void ) const;             
public:    virtual GEBool                     IsValid( void ) const;                
public:    virtual GEBool                     OnRead( bCIStream & );                
public:    virtual GEBool                     OnWrite( bCOStream & );               
public:    virtual bEResult                   Create( void );                       
public:    virtual void                       Destroy( void );                      
public:    virtual GEU32                      AddReference( void );                 
public:    virtual GEU32                      ReleaseReference( void );             
public:    virtual                           ~bCObjectRefBase( void );              
private:
    static bCPropertyObjectTypeBase thisType;
private:
    GEU32 m_u32ReferenceCount: 31;
    GEU32 m_bIsValid         :  1;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    public: using bCObjectBase::GetReferenceCount;
    GEU32 GetReferenceCount( void ) const;
public:
    bCObjectRefBase & operator = ( bCObjectRefBase const & );
public:
    bCObjectRefBase( bCObjectRefBase const & );
    bCObjectRefBase( void );
};
GE_ASSERT_SIZEOF( bCObjectRefBase, 0x0008 )

#endif
