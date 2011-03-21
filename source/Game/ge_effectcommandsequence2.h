#ifndef GE_EFFECTCOMMANDSEQUENCE2_H_INCLUDED
#define GE_EFFECTCOMMANDSEQUENCE2_H_INCLUDED

class gCEffectCommandSequence2 :
    public eCDocObject
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
protected: virtual void                       Destroy( void );
protected: virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCEffectCommandSequence2( void );
public:    virtual bCString                   GetRawExt( void ) const;
public:    virtual bCString                   GetRawPath( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTRefPropertyArray< gCEffectCommand * > m_arrCommands;
    GEBool                                  m_bPlayerOnly;
                                            GE_PADDING( 3 )
    GEFloat                                 m_fDistToPlayer;
protected:
    static GEInt GE_CCALL CompareItems( GELPCVoid, GELPCVoid );
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL GetClassRawExt( void );
    static bCString                   GE_STDCALL GetClassRawPath( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static gCEffectCommandSequence2 * GE_STDCALL LoadBinary( bCIStream & );
    static gCEffectCommandSequence2 * GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTRefPropertyArray< gCEffectCommand * > &       AccessCommands( void );
    GEFloat &                                       AccessDistToPlayer( void );
    GEBool &                                        AccessPlayerOnly( void );
    bTRefPropertyArray< gCEffectCommand * > const & GetCommands( void ) const;
    GEFloat const &                                 GetDistToPlayer( void ) const;
    GEFloat                                         GetEndTime( void ) const;
    gCEffectCommand *                               GetItem( GEInt ) const;
    GEInt                                           GetItemCount( void ) const;
    GEBool const &                                  GetPlayerOnly( void ) const;
    GEInt                                           InsertItem( gCEffectCommand * );
    GEBool                                          IsValidIndex( GEInt ) const;
    void                                            RemoveAllItems( void );
    GEBool                                          RemoveItem( GEInt );
    GEBool                                          RemoveItem( gCEffectCommand * );
    void                                            SetCommands( bTRefPropertyArray< gCEffectCommand * > const & );
    void                                            SetDistToPlayer( GEFloat const & );
    void                                            SetPlayerOnly( GEBool const & );
    void                                            SortItems( void );
public:
    gCEffectCommand *          operator [] ( GEInt ) const;
    gCEffectCommandSequence2 & operator =  ( gCEffectCommandSequence2 const & );
public:
    gCEffectCommandSequence2( gCEffectCommandSequence2 const & );
    gCEffectCommandSequence2( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandSequence2, 0x0020 )

#endif
