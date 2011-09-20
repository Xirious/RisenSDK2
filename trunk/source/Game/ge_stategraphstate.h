#ifndef GE_STATEGRAPHSTATE_H_INCLUDED
#define GE_STATEGRAPHSTATE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCStateGraphState'
                                   // class 'bTRefPtrArray<T>' needs to have dll-interface to be used by clients of class 'gCStateGraphState'

class GE_DLLIMPORT gCStateGraphState :
    public bCObjectRefBase
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphState, bCObjectRefBase )
public:    virtual GEBool                 OnRead( bCIStream & );
public:    virtual GEBool                 OnWrite( bCOStream & );
public:    virtual bEResult               Create( void );
protected: virtual void                   Destroy( void );
public:    virtual GEBool                 OnCopyFrom( bCObjectBase const & );
public:    virtual GEBool                 OnCopyPatchableOnly( bCObjectBase const & );
public:    virtual GEInt                  GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;
public:    virtual                       ~gCStateGraphState( void );
protected:
    GE_DECLARE_PROPERTY( bCString,        m_strName, Name )
    gCStateGraph_PS *                     m_pGraph;
    bTObjArray< gCStateGraphTransition >  m_arrTransitions;
    bTRefPtrArray< gCStateGraphAction * > m_arrActions;
    void *                                __FIXME_0028;
    gCStateGraphState *                   m_pNextState;
    bCRect                                m_rectEditorLayout;
    GEFloat                               m_fStateTime;
public:
    GEBool                         AddAction( gCStateGraphAction * );
    GEBool                         AddTransition( gCStateGraphState * );
    gCStateGraphAction *           GetActionAt( GEInt ) const;
    GEInt                          GetActionCount( void ) const;
    GEInt                          GetActionIndex( gCStateGraphAction * ) const;
    void                           GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
    bCRect &                       GetEditorLayout( void );
    gCStateGraph_PS *              GetGraph( void ) const;
    gCStateGraphState *            GetNextState( void ) const;
    GEFloat                        GetStateTime( void ) const;
    gCStateGraphTransition const & GetTransitionAt( GEInt ) const;
    GEInt                          GetTransitionCount( void ) const;
    GEInt                          GetTransitionIndex( gCStateGraphState * ) const;
    void                           OnEnter( void );
    void                           OnEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
    void                           OnExit( void );
    void                           OnProcess( void );
    GEBool                         RemoveAction( gCStateGraphAction * );
    GEBool                         RemoveTransition( gCStateGraphState * );
    void                           SetNextState( gCStateGraphState * );
protected:
    GEBool CopyActionsFrom( gCStateGraphState const *, GEBool );
    void   Invalidate( void );
    void   SetGraph( gCStateGraph_PS * );
};
GE_ASSERT_SIZEOF( gCStateGraphState, 0x0044 )

#pragma warning( pop )

#endif
