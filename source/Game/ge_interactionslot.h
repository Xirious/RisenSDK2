#ifndef GE_INTERACTIONSLOT_H_INCLUDED
#define GE_INTERACTIONSLOT_H_INCLUDED

class GE_DLLIMPORT gCInteractionSlot :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCInteractionSlot( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCMatrix      m_matOffset;
    eCEntityProxy m_Item;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCEntityProxy &       AccessItem( void );
    bCMatrix &            AccessOffset( void );
    eCEntity *            Attach( gCInteraction_PS *, eCTemplateEntity * );
    GEBool                CanAttach( gCInteraction_PS *, eCTemplateEntity * ) const;
    GEBool                Detach( gCInteraction_PS *, eCEntity * );
    eCEntityProxy const & GetItem( void ) const;
    bCMatrix const &      GetOffset( void ) const;
    GEBool                IsFree( void ) const;
    void                  SetItem( eCEntityProxy const & );
    void                  SetOffset( bCMatrix const & );
public:
    GEBool              operator == ( gCInteractionSlot const & ) const;
    gCInteractionSlot & operator =  ( gCInteractionSlot const & );
public:
    gCInteractionSlot( gCInteractionSlot const & );
    gCInteractionSlot( void );
};
GE_ASSERT_SIZEOF( gCInteractionSlot, 0x004C )

#endif
