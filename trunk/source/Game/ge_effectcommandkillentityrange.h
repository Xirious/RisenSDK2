#ifndef GE_EFFECTCOMMANDKILLENTITYRANGE_H_INCLUDED
#define GE_EFFECTCOMMANDKILLENTITYRANGE_H_INCLUDED

enum gEEffectKillRange
{
    gEEffectKillRange_All        = 0x00000000,
    gEEffectKillRange_Range      = 0x00000001,
    gEEffectKillRange_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandKillEntityRange'

class GE_DLLIMPORT gCEffectCommandKillEntityRange :
    public gCEffectCommandEntity
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandKillEntityRange( void );
public: virtual GEInt                      GetCommandPriority( void ) const;
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEEffectKillRange > m_enumRange;
    GEInt                                    m_iMinEntityIndex;
    GEInt                                    m_iMaxEntityIndex;
    GEBool                                   m_bDecay;
                                             GE_PADDING( 3 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                                         AccessDecay( void );
    GEInt &                                          AccessMaxEntityIndex( void );
    GEInt &                                          AccessMinEntityIndex( void );
    bTPropertyContainer< gEEffectKillRange > &       AccessRange( void );
    GEBool const &                                   GetDecay( void ) const;
    GEInt const &                                    GetMaxEntityIndex( void ) const;
    GEInt const &                                    GetMinEntityIndex( void ) const;
    bTPropertyContainer< gEEffectKillRange > const & GetRange( void ) const;
    void                                             SetDecay( GEBool const & );
    void                                             SetMaxEntityIndex( GEInt const & );
    void                                             SetMinEntityIndex( GEInt const & );
    void                                             SetRange( bTPropertyContainer< gEEffectKillRange > const & );
public:
    gCEffectCommandKillEntityRange & operator = ( gCEffectCommandKillEntityRange const & );
public:
    gCEffectCommandKillEntityRange( gCEffectCommandKillEntityRange const & );
    gCEffectCommandKillEntityRange( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandKillEntityRange, 0x0024 )

#pragma warning( pop )

#endif
