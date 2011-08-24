#ifndef GE_INVENTORYSTACK_H_INCLUDED
#define GE_INVENTORYSTACK_H_INCLUDED

enum gEStackType
{
    gEStackType_Normal     = 0x00000000,
    gEStackType_Trade      = 0x00000001,
    gEStackType_Hidden     = 0x00000002,
    gEStackType_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInventoryStack'

class GE_DLLIMPORT gCInventoryStack :
    public gCInventorySlot
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCInventoryStack( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt                             m_iQuickSlot;
    bTPropertyContainer< gEStackType> m_enumType;
    bTPropertyContainer< gEEquipSlot> m_enumEquipSlot;
    GEInt                             m_iRuntimeID;
                                      GE_PADDING( 4 )
    GEI64                             m_iAmount     : 21;
    GEI64                             m_iSelectLimit: 21;
    GEI64                             m_iSelection  : 21;
public:
    static GEU32 ms_u32NextRuntimeID;
protected:
    void  ApplyDefaults( void );
    GEInt CompareFocusName( gCInventoryStack const & ) const;
    void  Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEEquipSlot > &       AccessEquipSlot( void );
    GEInt &                                    AccessQuickSlot( void );
    bTPropertyContainer< gEStackType > &       AccessType( void );
    GEBool                                     CanMerge( gCInventoryStack const & ) const;
    GEInt                                      Compare( gCInventoryStack const & ) const;
    eCEntity *                                 Drop( eCEntity * );
    GEInt                                      GetAmount( void ) const;
    bTPropertyContainer< gEEquipSlot > const & GetEquipSlot( void ) const;
    GEInt                                      GetItemGoldValue( void ) const;
    GEInt const &                              GetQuickSlot( void ) const;
    GEInt                                      GetRuntimeID( void ) const;
    GEInt                                      GetSelectLimit( void ) const;
    GEInt                                      GetSelectRemain( void ) const;
    GEInt                                      GetSelection( void ) const;
    GEInt                                      GetStackGoldValue( void ) const;
    bTPropertyContainer< gEStackType > const & GetType( void ) const;
    GEBool                                     IsDisposable( void ) const;
    GEBool                                     IsEmpty( void ) const;
    GEBool                                     IsEquipped( void ) const;
    GEBool                                     IsEquippedInAlternative( void ) const;
    GEBool                                     IsEquippedInPrimary( void ) const;
    GEBool                                     IsEquippedToSlot( gEEquipSlot ) const;
    GEBool                                     IsMergable( void ) const;
    GEBool                                     Merge( gCInventoryStack & );
    GEBool                                     MustSplitBeforeLinking( gESlot, eCEntity * ) const;
    void                                       SetAmount( GEInt const & );
    void                                       SetEquipSlot( bTPropertyContainer< gEEquipSlot > const & );
    void                                       SetMaxSelectLimit( void );
    void                                       SetMaxSelection( void );
    void                                       SetMinSelectLimit( void );
    void                                       SetMinSelection( void );
    void                                       SetQuickSlot( GEInt const & );
    void                                       SetSelectLimit( GEInt const & );
    void                                       SetSelection( GEInt const & );
    void                                       SetType( bTPropertyContainer< gEStackType > const & );
    GEBool                                     Split( GEInt, gCInventoryStack & );
public:
    gCInventoryStack & operator = ( gCInventoryStack const & );
public:
    gCInventoryStack( gCInventoryStack const & );
    gCInventoryStack( void );
};
GE_ASSERT_SIZEOF( gCInventoryStack, 0x0038 )

#pragma warning( pop )

#endif
