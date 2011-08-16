#ifndef GE_COMBATSTYLERANGED_H_INCLUDED
#define GE_COMBATSTYLERANGED_H_INCLUDED

class GE_DLLIMPORT gCCombatStyleRanged :
    public gCCombatStyle
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatStyleRanged( void );
public:    virtual gCCombatMove *             GetMove( gECombatMove ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strAttackSec;
    bCString m_strAim;
    bCString m_strSniper;
    bCString m_strReload;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessAim( void );
    bCString &       AccessAttackSec( void );
    bCString &       AccessReload( void );
    bCString &       AccessSniper( void );
    bCString const & GetAim( void ) const;
    bCString const & GetAttackSec( void ) const;
    bCString const & GetReload( void ) const;
    bCString const & GetSniper( void ) const;
    void             SetAim( bCString const & );
    void             SetAttackSec( bCString const & );
    void             SetReload( bCString const & );
    void             SetSniper( bCString const & );
public:
    gCCombatStyleRanged & operator = ( gCCombatStyleRanged const & );
public:
    gCCombatStyleRanged( gCCombatStyleRanged const & );
    gCCombatStyleRanged( void );
};
GE_ASSERT_SIZEOF( gCCombatStyleRanged, 0x008C )

#endif
