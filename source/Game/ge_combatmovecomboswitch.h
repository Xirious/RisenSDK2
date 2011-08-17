#ifndef GE_COMBATMOVECOMBOSWITCH_H_INCLUDED
#define GE_COMBATMOVECOMBOSWITCH_H_INCLUDED

class gCCombatMoveSwitch :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCCombatMoveSwitch( void );
public:
    GEFloat  m_fTime;
    bCString m_strMove;
//NOTE: The class is not exported. Use the property system to create objects.
private:
    gCCombatMoveSwitch & operator = ( gCCombatMoveSwitch const & );  // not defined
private:
    gCCombatMoveSwitch( gCCombatMoveSwitch const & );                // not defined
    gCCombatMoveSwitch( void );                                      // not defined
};
GE_ASSERT_SIZEOF( gCCombatMoveSwitch, 0x000C )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCCombatMoveComboSwitch'

class GE_DLLIMPORT gCCombatMoveComboSwitch :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveComboSwitch( void );
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTObjArray< gCCombatMoveSwitch > m_arrComboMoves;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTObjArray< gCCombatMoveSwitch > &       AccessComboMoves( void );
    bTObjArray< gCCombatMoveSwitch > const & GetComboMoves( void ) const;
    void                                     SetComboMoves( bTObjArray< gCCombatMoveSwitch > const & );
public:
    gCCombatMoveComboSwitch & operator = ( gCCombatMoveComboSwitch const & );
public:
    gCCombatMoveComboSwitch( gCCombatMoveComboSwitch const & );
    gCCombatMoveComboSwitch( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveComboSwitch, 0x0020 )

#pragma warning( pop )

#endif
