#ifndef GE_COLLISIONSHAPEBASE_PS_H_INCLUDED
#define GE_COLLISIONSHAPEBASE_PS_H_INCLUDED

class GE_DLLIMPORT eCCollisionShapeBase_PS :
    public eCEntityPropertySet
{
public: virtual bEResult                   SetShape( eCCollisionShape * );
public: virtual bEResult                   SetShape( bCString const & );
public: virtual bEResult                   AddShape( eCCollisionShape * );
public: virtual bEResult                   AddShape( bCString const & );
public: virtual GEU32                      GetNumShapes( void ) const;
public: virtual eCCollisionShape *         GetShapeAtIndex( GEU32 ) const;
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                            ~eCCollisionShapeBase_PS( void );
public: virtual eEPropertySetType          GetPropertySetType( void ) const;
public: virtual GEBool                     IsEditorRelevant( void ) const;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             CreateObject( void );
    static bCPropertyObjectTypeBase & GetThisType( void );
    static void                       StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCCollisionShapeBase_PS & operator = ( eCCollisionShapeBase_PS const & );
public:
    eCCollisionShapeBase_PS( eCCollisionShapeBase_PS const & );
    eCCollisionShapeBase_PS( void );
};
GE_ASSERT_SIZEOF( eCCollisionShapeBase_PS, 0x0010 )
    
#endif
