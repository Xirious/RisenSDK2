#ifndef GE_PROPERTYOBJECTTYPEBASE_H_INCLUDED
#define GE_PROPERTYOBJECTTYPEBASE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<>' needs to have dll-interface to be used by clients of class 'bCPropertyObjectTypeBase'

class GE_DLLIMPORT bCPropertyObjectTypeBase
{
public:
    typedef bCObjectBase * (GE_STDCALL * bFCreateNewObject)( void );
    typedef void           (GE_STDCALL * bFRegisterTypeCallback)( bCPropertyObjectTypeBase & );
private:
    static bCPropertyObjectTypeBase *   ms_pList;
    static bCPropertyObjectTypeBase * * ms_pMap;
    static bCPropertyObjectTypeBase *   ms_pRoot;
private:
    bTPtrArray< bCPropertyTypeBase * > m_arrPropertyTypes;
    bCPropertyObjectTypeBase *         m_pBase;
    bCPropertyObjectTypeBase *         m_pNext;
    bCPropertyObjectTypeBase *         m_pDerived;
    bCPropertyObjectTypeBase *         m_pMapNext;
    bCPropertyObjectTypeBase *         m_pListNext;
    bFCreateNewObject                  m_funcCreateNewObject;
    bFRegisterTypeCallback             m_funcRegisterTypeCallback;
    bCString                           m_strClassName;
    GELPCChar                          m_pcLabel;
    GELPCChar                          m_pcDescription;
    GEU32                              m_u32Flags;
private:
    static GEBool GE_STDCALL _ReadObject( bCIStream &, bCObjectBase & );
private:
    GEInt GetPropertyTemplateIndex( bCPropertyTypeBase const & ) const;
    void  InitTypeMap( void );
    void  RegisterType( void );
public:
    static bCPropertyObjectTypeBase * GE_STDCALL FromName( GELPCChar );
    static bCPropertyObjectTypeBase * GE_STDCALL GetListHead( void );
    static GEUInt                     GE_STDCALL GetTypeHash( GELPCChar );
    static bCObjectBase *             GE_STDCALL QueryNewObject( GELPCChar );
    static bCObjectBase *             GE_STDCALL ReadObject( bCIStream & );
    static GEBool                     GE_STDCALL ReadObject( bCIStream &, bCObjectBase & );
    static GEU16                      GE_STDCALL ReadSkip( bCIStream & );
    static GEU16                      GE_STDCALL ReadSkipObject( bCIStream & );
    static void                       GE_STDCALL WriteObject( bCOStream &, bCObjectBase * );
public:
    bTPtrArray< bCPropertyTypeBase * >::bCConstIterator BeginIterator( void ) const;
    bCObjectBase *                                      CreateNewObject( void );
    bTPtrArray< bCPropertyTypeBase * >::bCConstIterator EndIterator( void ) const;
    bCPropertyTypeBase const *                          FindPropertyTemplate( bCString const & ) const;
    bCPropertyObjectTypeBase *                          GetBase( void ) const;
    bCString const &                                    GetBaseClassName( void ) const;
    bCString const &                                    GetClassName( void ) const;
    bCPropertyObjectTypeBase *                          GetDerived( void ) const;
    GELPCChar                                           GetDescription( void ) const;
    GEU32                                               GetFlags( void ) const;
    GELPCChar                                           GetLabel( void ) const;
    bCPropertyObjectTypeBase *                          GetListNext( void ) const;
    GELPCChar                                           GetName( void ) const;
    bCPropertyObjectTypeBase *                          GetNext( void ) const;
    bCPropertyTypeBase const &                          GetPropertyType( GEInt ) const;
    GEInt                                               GetPropertyTypeCount( void ) const;
    GEUInt                                              GetTypeHash( void ) const;
    GEBool                                              HasFlag( GEU32 ) const;
    GEBool                                              IsDerivedFrom( bCPropertyObjectTypeBase const * ) const;
    GEBool                                              IsKindOf( bCPropertyObjectTypeBase const * ) const;
    GEBool                                              IsPropertyTypeValid( GEInt ) const;
    bCObjectBase *                                      ReadNewObject( bCIStream & );
    GEBool                                              RegisterPropertyTemplate( bCPropertyTypeBase const * );
    GEBool                                              UnregisterPropertyTemplate( bCPropertyTypeBase const * );
public:
    bCPropertyObjectTypeBase( GELPCChar, GELPCChar, GELPCChar, bCPropertyObjectTypeBase *, bFCreateNewObject, bFRegisterTypeCallback, GEU32 );
   ~bCPropertyObjectTypeBase( void );
};

#pragma warning( pop )

#endif
