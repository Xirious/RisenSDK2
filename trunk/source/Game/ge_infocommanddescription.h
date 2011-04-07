#ifndef GE_INFOCOMMANDDESCRIPTION_H_INCLUDED
#define GE_INFOCOMMANDDESCRIPTION_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandDescription :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual GEBool                     HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
public: virtual                           ~gCInfoCommandDescription( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual void                       GetTableKeys( bTObjArray< bCString > & );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCInfoLocString m_locText;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCInfoLocString &       AccessText( void );
    gCInfoLocString const & GetText( void ) const;
    void                    SetText( gCInfoLocString const & );
public:
    gCInfoCommandDescription & operator = ( gCInfoCommandDescription const & );
public:
    gCInfoCommandDescription( gCInfoCommandDescription const & );
    gCInfoCommandDescription( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandDescription, 0x0014 )

#endif
