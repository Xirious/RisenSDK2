#ifndef GE_INTERACTIONADMIN_H_INCLUDED
#define GE_INTERACTIONADMIN_H_INCLUDED

class GE_DLLIMPORT gCInteractionAdmin :
    public eCEngineComponentBase
{
public:
    class GE_DLLIMPORT gCIterator
    {
    protected:
        gCInteraction_PS *   m_pInteraction;
        gEInteractionUseType m_enumUseType;
    public:
        GEBool IsValid( void ) const;
    public:
        GEBool                     operator == ( gCIterator const & ) const;
        GEBool                     operator != ( gCIterator const & ) const;
        gCInteraction_PS * &       operator *  ( void );
        gCInteraction_PS const * & operator *  ( void ) const;
        gCIterator                 operator ++ ( GEInt );
        gCIterator &               operator ++ ( void );
        gCIterator &               operator =  ( gCIterator const & );
    public:
        gCIterator( gEInteractionUseType );
        gCIterator( void );
    // ~gCIterator( void );  // not defined
    };
    GE_ASSERT_SIZEOF( gCIterator, 0x0008 )
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCInteractionAdmin( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x0128 - sizeof(eCEngineComponentBase) ];
protected:
    gCInteraction_PS * GetFirstInteractionInROI( gEInteractionUseType ) const;
    gCInteraction_PS * GetFirstInteractionInROI( void ) const;
    gCInteraction_PS * GetNextInteractionInROI( gCInteraction_PS * ) const;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCInteractionAdmin &       GE_STDCALL GetInstance( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool AddInteractionInROI( gCInteraction_PS * );
    void   Invalidate( void );
    GEBool RemoveInteractionInROI( gCInteraction_PS * );
public:
    gCInteractionAdmin & operator = ( gCInteractionAdmin const & );
public:
    gCInteractionAdmin( gCInteractionAdmin const & );
    gCInteractionAdmin( void );
};
GE_ASSERT_SIZEOF( gCInteractionAdmin, 0x0128 )

#endif
