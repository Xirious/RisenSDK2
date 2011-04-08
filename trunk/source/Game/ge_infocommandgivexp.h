#ifndef GE_INFOCOMMANDGIVEXP_H_INCLUDED
#define GE_INFOCOMMANDGIVEXP_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandGiveXP :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandGiveXP( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEU32 m_u32Amount;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &       AccessAmount( void );
    GEU32 const & GetAmount( void ) const;
    void          SetAmount( GEU32 const & );
public:
    gCInfoCommandGiveXP & operator = ( gCInfoCommandGiveXP const & );
public:
    gCInfoCommandGiveXP( gCInfoCommandGiveXP const & );
    gCInfoCommandGiveXP( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandGiveXP, 0x000C )

#endif
