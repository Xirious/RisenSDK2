#ifndef GE_ARENA_PS_H_INCLUDED
#define GE_ARENA_PS_H_INCLUDED

enum gEArenaStatus
{
    gEArenaStatus_None       = 0x00000000,
    gEArenaStatus_Running    = 0x00000001,
    gEArenaStatus_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCArena_PS'

class GE_DLLIMPORT gCArena_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual                                           ~gCArena_PS( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public: virtual void                                       GetBoundary( bCBox &, GEBool );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEArenaStatus > m_enumStatus;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEArenaStatus > &       AccessStatus( void );
    bTPropertyContainer< gEArenaStatus > const & GetStatus( void ) const;
    void                                         SetStatus( bTPropertyContainer< gEArenaStatus > const & );
public:
    gCArena_PS & operator = ( gCArena_PS const & );
public:
    gCArena_PS( gCArena_PS const & );
    gCArena_PS( void );
};
GE_ASSERT_SIZEOF( gCArena_PS, 0x0018 )

#pragma warning( pop )

#endif
