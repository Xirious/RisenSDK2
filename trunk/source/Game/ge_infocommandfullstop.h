#ifndef GE_INFOCOMMANDFULLSTOP_H_INCLUDED
#define GE_INFOCOMMANDFULLSTOP_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandFullStop :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandFullStop( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString      m_strEntity1;
    eCEntityProxy m_EntityProxy1;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessEntity1( void );
    bCString const & GetEntity1( void ) const;
    void             SetEntity1( bCString const & );
public:
    gCInfoCommandFullStop & operator = ( gCInfoCommandFullStop const & );
public:
    gCInfoCommandFullStop( gCInfoCommandFullStop const & );
    gCInfoCommandFullStop( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandFullStop, 0x0014 )

#endif
