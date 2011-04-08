#ifndef GE_INFOCOMMANDRUNINFO_H_INCLUDED
#define GE_INFOCOMMANDRUNINFO_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRunInfo :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandRunInfo( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strInfo;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessInfo( void );
    bCString const & GetInfo( void ) const;
    void             SetInfo( bCString const & );
public:
    gCInfoCommandRunInfo & operator = ( gCInfoCommandRunInfo const & );
public:
    gCInfoCommandRunInfo( gCInfoCommandRunInfo const & );
    gCInfoCommandRunInfo( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunInfo, 0x000C )

#endif
