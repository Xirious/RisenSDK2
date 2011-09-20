#ifndef GE_STATEGRAPHACTION_H_INCLUDED
#define GE_STATEGRAPHACTION_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCStateGraphAction'

class GE_DLLIMPORT gCStateGraphAction :
    public bCObjectRefBase
{
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
protected: virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnStateFinished( void );
public:    virtual void     OnExit( void );
public:    virtual void     OnEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
public:    virtual void     GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphAction, bCObjectRefBase )
public:    virtual GEBool   OnRead( bCIStream & );
public:    virtual GEBool   OnWrite( bCOStream & );
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual GEBool   OnCopyFrom( bCObjectBase const & );
public:    virtual GEBool   OnCopyPatchableOnly( bCObjectBase const & );
public:    virtual         ~gCStateGraphAction( void );
protected:
    GE_DECLARE_ENUMPROP( gEStateGraphEventType,                      m_enumEventType,  EventType )
    GE_DECLARE_PROPERTY( bTRefPtrArray< gCStateGraphEventFilter * >, m_arrEventFilter, EventFilter )
    gCStateGraphState *                                              m_pState;
    GEBool                                                           __FIXME_0020;
    GE_PADDING( 3 )
public:
    eCEntity *          GetEntity( void ) const;
    gCStateGraph_PS *   GetGraph( void ) const;
    gCStateGraphState * GetState( void ) const;
protected:
    GEBool CopyEventFilterFrom( gCStateGraphAction const *, GEBool );
    void   DoEnter( void );
    void   DoEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
    void   DoExit( void );
    GEBool DoProcess( void );
    void   DoStateFinished( void );
    void   Invalidate( void );
    void   SetState( gCStateGraphState * );
};
GE_ASSERT_SIZEOF( gCStateGraphAction, 0x0024 )

#pragma warning( pop )

#endif
