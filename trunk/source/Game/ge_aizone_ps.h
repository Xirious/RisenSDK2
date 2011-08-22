#ifndef GE_AIZONE_PS_H_INCLUDED
#define GE_AIZONE_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCAIZone_PS'

class GE_DLLIMPORT gCAIZone_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual                                           ~gCAIZone_PS( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual GEBool                                     IsReferencedByTemplate( void ) const;
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEGuild > m_enumGuild;
    bCString                       m_strGroup;
    eCScriptProxyScript            m_SecurityLevelFunc;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                             AccessGroup( void );
    bTPropertyContainer< gEGuild > &       AccessGuild( void );
    eCScriptProxyScript &                  AccessSecurityLevelFunc( void );
    bCString const &                       GetGroup( void ) const;
    bTPropertyContainer< gEGuild > const & GetGuild( void ) const;
    eCScriptProxyScript const &            GetSecurityLevelFunc( void ) const;
    void                                   SetGroup( bCString const & );
    void                                   SetGuild( bTPropertyContainer< gEGuild > const & );
    void                                   SetSecurityLevelFunc( eCScriptProxyScript const & );
public:
    gCAIZone_PS & operator = ( gCAIZone_PS const & );
public:
    gCAIZone_PS( gCAIZone_PS const & );
    gCAIZone_PS( void );
};
GE_ASSERT_SIZEOF( gCAIZone_PS, 0x0024 )

#pragma warning( pop )

#endif

