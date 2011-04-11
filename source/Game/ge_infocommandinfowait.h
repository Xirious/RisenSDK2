#ifndef GE_INFOCOMMANDINFOWAIT_H_INCLUDED
#define GE_INFOCOMMANDINFOWAIT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandInfoWait :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandInfoWait( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual gEInfoCommand              GetCommandTypeForScript( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEU32 m_u32Time;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &       AccessTime( void );
    GEU32 const & GetTime( void ) const;
    void          SetTime( GEU32 const & );
public:
    gCInfoCommandInfoWait & operator = ( gCInfoCommandInfoWait const & );
public:
    gCInfoCommandInfoWait( gCInfoCommandInfoWait const & );
    gCInfoCommandInfoWait( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandInfoWait, 0x000C )

#endif