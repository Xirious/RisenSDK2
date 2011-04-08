#ifndef GE_INFOCOMMANDREMOVENPC_H_INCLUDED
#define GE_INFOCOMMANDREMOVENPC_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRemoveNPC :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandRemoveNPC( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString      m_strNPC;
    eCEntityProxy m_EntityProxy1;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessNPC( void );
    bCString const & GetNPC( void ) const;
    void             SetNPC( bCString const & );
public:
    gCInfoCommandRemoveNPC & operator = ( gCInfoCommandRemoveNPC const & );
public:
    gCInfoCommandRemoveNPC( gCInfoCommandRemoveNPC const & );
    gCInfoCommandRemoveNPC( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRemoveNPC, 0x0014 )

#endif
