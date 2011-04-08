#ifndef GE_INFOCOMMANDREMOVENPCINFO_H_INCLUDED
#define GE_INFOCOMMANDREMOVENPCINFO_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandRemoveNPCInfo'

class GE_DLLIMPORT gCInfoCommandRemoveNPCInfo :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCInfoCommandRemoveNPCInfo( void );
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
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEInfoLocation > &       AccessLocation( void );
    bCString &                                    AccessNPC( void );
    bTPropertyContainer< gEInfoNPCType > &        AccessType( void );
    bTPropertyContainer< gEInfoLocation > const & GetLocation( void ) const;
    bCString const &                              GetNPC( void ) const;
    bTPropertyContainer< gEInfoNPCType > const &  GetType( void ) const;
    void                                          SetLocation( bTPropertyContainer< gEInfoLocation > const & );
    void                                          SetNPC( bCString const & );
    void                                          SetType( bTPropertyContainer< gEInfoNPCType > const & );
public:
    gCInfoCommandRemoveNPCInfo & operator = ( gCInfoCommandRemoveNPCInfo const & );
public:
    gCInfoCommandRemoveNPCInfo( gCInfoCommandRemoveNPCInfo const & );
    gCInfoCommandRemoveNPCInfo( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRemoveNPCInfo, 0x001C )

#pragma warning( pop )

#endif
