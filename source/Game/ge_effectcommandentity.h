#ifndef GE_EFFECTCOMMANDENTITY_H_INCLUDED
#define GE_AFFECTCOMMANDENTITY_H_INCLUDED

class GE_DLLIMPORT gCEffectCommandEntity :
    public gCEffectCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCEffectCommandEntity( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt m_iDummy;
protected:
    void Kill( bTObjMap< GEInt, eCEntityProxy > &, GEInt, GEBool ) const;
    void KillAll( bTObjMap< GEInt, eCEntityProxy> &, GEBool ) const;
    void KillRange( bTObjMap< GEInt, eCEntityProxy> &, GEInt, GEInt, GEBool ) const;
    void Spawn( eCTemplateEntity *, GEInt, gEEffectLink, bCString const &, bCMotion const &, eCEntity *, eCEntity *, bCMatrix const *, bTObjMap< GEInt, eCEntityProxy > &, bTObjArray< eCEntityProxy > &, GEBool ) const;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEInt &       AccessDummy( void );
    GEInt const & GetDummy( void ) const;
    void          SetDummy( GEInt const & );
public:
    gCEffectCommandEntity & operator = ( gCEffectCommandEntity const & );
public:
    gCEffectCommandEntity( gCEffectCommandEntity const & );
    gCEffectCommandEntity( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandEntity, 0x0010 )

#endif
