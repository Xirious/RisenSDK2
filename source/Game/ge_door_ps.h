#ifndef GE_DOOR_PS_H_INCLUDED
#define GE_DOOR_PS_H_INCLUDED

enum gEDoorStatus
{
    gEDoorStatus_Open       = 0x00000000,
    gEDoorStatus_Closed     = 0x00000001,
    gEDoorStatus_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCDoor_PS'

class GE_DLLIMPORT gCDoor_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual bEResult                                   PostInitializeProperties( void );
public: virtual                                           ~gCDoor_PS( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual GEBool                                     IsEntityListener( void ) const;
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public: virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
public: virtual void                                       SetIsOpen( GEBool );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEDoorStatus > m_enumStatus;
    eCEntityProxy                       m_NavPathEntityProxy;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEDoorStatus > &       AccessStatus( void );
    eCEntityProxy &                             GetNavPathEntityProxy( void );
    bTPropertyContainer< gEDoorStatus > const & GetStatus( void ) const;
    void                                        SetNavPathEntityProxy( eCEntityProxy & );
    void                                        SetStatus( bTPropertyContainer< gEDoorStatus > const & );
public:
    gCDoor_PS & operator = ( gCDoor_PS const & );
public:
    gCDoor_PS( gCDoor_PS const & );
    gCDoor_PS( void );
};
GE_ASSERT_SIZEOF( gCDoor_PS, 0x0020 )

#pragma warning( pop )

#endif
