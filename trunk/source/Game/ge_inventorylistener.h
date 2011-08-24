#ifndef GE_INVENTORYLISTENER_H_INCLUDED
#define GE_INVENTORYLISTENER_H_INCLUDED

class GE_DLLIMPORT gCInventoryListener
{
public: virtual void OnStackCreate( GEInt, gCInventoryStack const * ) = 0;
public: virtual void OnStackChange( GEInt, gCInventoryStack const * ) = 0;
public: virtual void OnStackDelete( GEInt, gCInventoryStack const * ) = 0;
public: virtual void OnSortInventory( void )                          = 0;
public: virtual void OnDestroyInventory( void )                       = 0;
public:
    gCInventoryListener & operator = ( gCInventoryListener const & );
public:
    gCInventoryListener( gCInventoryListener const & );
    gCInventoryListener( void );
// ~gCInventoryListener( void );  // not defined
};
GE_ASSERT_SIZEOF( gCInventoryListener, 0x0004 )

#endif
