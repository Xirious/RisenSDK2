#ifndef GE_EFFECTCOMMANDKILLENTITY_H_INCLUDED
#define GE_EFFECTCOMMANDKILLENTITY_H_INCLUDED

class GE_DLLIMPORT gCEffectCommandKillEntity :
    public gCEffectCommandEntity
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandKillEntity( void );
public: virtual GEInt                      GetCommandPriority( void ) const;
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt  m_iEntityIndex;
    GEBool m_bDecay;
           GE_PADDING( 3 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public: 
    GEBool &       AccessDecay( void );
    GEInt &        AccessEntityIndex( void );
    GEBool const & GetDecay( void ) const;
    GEInt const &  GetEntityIndex( void ) const;
    void           SetDecay( GEBool const & );
    void           SetEntityIndex( GEInt const & );
public:
    gCEffectCommandKillEntity & operator = ( gCEffectCommandKillEntity const & );
public:
    gCEffectCommandKillEntity( gCEffectCommandKillEntity const & );
    gCEffectCommandKillEntity( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandKillEntity, 0x0018 )

#endif
