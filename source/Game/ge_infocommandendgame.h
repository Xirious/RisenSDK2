#ifndef GE_INFOCOMMANDENDGAME_H_INCLUDED
#define GE_INFOCOMMANDENDGAME_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandEndGame :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandEndGame( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCInfoCommandEndGame & operator = ( gCInfoCommandEndGame const & );
public:
    gCInfoCommandEndGame( gCInfoCommandEndGame const & );
    gCInfoCommandEndGame( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandEndGame, 0x0008 )

#endif
