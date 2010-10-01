#ifndef GE_ACCESSORPROPERTYOBJECT_H_INCLUDED
#define GE_ACCESSORPROPERTYOBJECT_H_INCLUDED

class GE_DLLIMPORT bCAccessorPropertyObject
{
private:
    bCPropertyObjectTypeBase * m_pBase;
    bCObjectBase *             m_pObject;
protected:
    void Invalidate( void );
    void SetInstance( bCObjectBase * );
    void SetInstance( bCObjectRefBase * );
public:
    bCAccessorPropertyObject         Clone( void ) const;
    GEBool                           Compare( bCAccessorPropertyObject const & ) const;
    void                             CopyFrom( bCAccessorPropertyObject const & );
    void                             CopyTo( bCAccessorPropertyObject & ) const;
    GEBool                           Deserialize( bCXMLParserNode * );
    void                             DumpOutputDebugString( GEBool );
    bCAccessorPropertyObject         GetBaseClass( void ) const;
    bCString const &                 GetClassName( void ) const;
    bCObjectBase *                   GetNativeObject( void );
    bCObjectBase const *             GetNativeObject( void ) const;
    bCObjectBase *                   GetPropertyObject( void );
    bCObjectBase const *             GetPropertyObject( void ) const;
    bCString                         GetPropertyObjectHeader( void ) const;
    bCPropertyObjectTypeBase const * GetPropertyObjectType( void ) const;
    GEBool                           HasBaseClass( void ) const;
    GEBool                           HasPropertyObject( void ) const;
    GEBool                           IsDerivedFrom( bCAccessorPropertyObject const & ) const;
    GEBool                           IsDerivedFrom( bCPropertyObjectTypeBase const * ) const;
    GEBool                           IsKindOf( bCAccessorPropertyObject const & ) const;
    GEBool                           IsValid( void ) const;
    GEU16                            Read( bCIStream & );
    GEBool                           Serialize( bCXMLParserNode * );
    void                             Write( bCOStream & );
public:
    bCAccessorPropertyObject const & operator =  ( bCAccessorPropertyObject const & );
    bCOStream &                      operator >> ( bCOStream & );
    bCIStream &                      operator << ( bCIStream & );
    GEBool                           operator == ( bCAccessorPropertyObject const & ) const;
    GEBool                           operator != ( bCAccessorPropertyObject const & ) const;
    bCAccessorPropertyObject         operator ++ ( GEInt );
    bCAccessorPropertyObject &       operator ++ ( void );
public:
    bCAccessorPropertyObject( bCAccessorCreator const & );
    bCAccessorPropertyObject( bCString const & );
    bCAccessorPropertyObject( bCObjectBase * );
    bCAccessorPropertyObject( bCObjectRefBase * );
    bCAccessorPropertyObject( bCObjectBase const * );
    bCAccessorPropertyObject( bCObjectRefBase const * );
    bCAccessorPropertyObject( bCAccessorPropertyObject const & );
    bCAccessorPropertyObject( void );
   ~bCAccessorPropertyObject( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, bCAccessorPropertyObject & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, bCAccessorPropertyObject & );
};

#endif
