#ifndef GE_INFOCOMMANDADDNPCINFO_H_INCLUDED
#define GE_INFOCOMMANDADDNPCINFO_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandAddNPCInfo'

class GE_DLLIMPORT gCInfoCommandAddNPCInfo :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCInfoCommandAddNPCInfo( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                              m_strNPC;
    bTPropertyContainer< gEInfoLocation > m_enumLocation;
    bTPropertyContainer< gEInfoNPCType >  m_enumType;
    gCNPCInfoLocString                    m_locDescription;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCNPCInfoLocString &                          AccessDescription( void );
    bTPropertyContainer< gEInfoLocation > &       AccessLocation( void );
    bCString &                                    AccessNPC( void );
    bTPropertyContainer< gEInfoNPCType > &        AccessType( void );
    gCNPCInfoLocString const &                    GetDescription( void ) const;
    bTPropertyContainer< gEInfoLocation > const & GetLocation( void ) const;
    bCString const &                              GetNPC( void ) const;
    bTPropertyContainer< gEInfoNPCType > const &  GetType( void ) const;
    void                                          SetDescription( gCNPCInfoLocString const & );
    void                                          SetLocation( bTPropertyContainer< gEInfoLocation > const & );
    void                                          SetNPC( bCString const & );
    void                                          SetType( bTPropertyContainer< gEInfoNPCType > const & );
public:
    gCInfoCommandAddNPCInfo & operator = ( gCInfoCommandAddNPCInfo const & );
public:
    gCInfoCommandAddNPCInfo( gCInfoCommandAddNPCInfo const & );
    gCInfoCommandAddNPCInfo( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandAddNPCInfo, 0x0028 )

#pragma warning( pop )

#endif
