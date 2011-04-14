#ifndef GE_OCTTREE_H_INCLUDED
#define GE_OCTTREE_H_INCLUDED

class bCOctTree;

//FIXME: bCOctTreeEntryBase declarations/definitions.
//FIXME: Is bCOctTree used at all and is there a bTOctTreeEntry template?
class bCOctTreeEntryBase
{
private:
    bCBox                m_Box;
    bCOctTree *          m_pTree;
    bCOctTreeEntryBase * m_pTraversed;
private:
    bCOctTreeEntryBase const & operator = ( bCOctTreeEntryBase const & );  // not defined
    bCOctTreeEntryBase( bCOctTreeEntryBase const & );                      // not defined
};

class GE_DLLIMPORT bCOctTree
{
public:
    enum bEOctTreeCull
    {
        //FIXME: bCOctTree::bEOctTreeCull constants.
        bEOctTreeCull_ForceDWORD = GE_FORCE_DWORD
    };
    typedef bEOctTreeCull (GE_STDCALL * bFCullingCallback)( bCBox const & );
    typedef void          (GE_STDCALL * bFTouchCallback)( bCOctTreeEntryBase *, bCOctTreeEntryBase *, GEBool );
    typedef void          (GE_STDCALL * bFTraverseCallback)( bCOctTreeEntryBase * );

private:
    void *            m_pRoot;  //FIXME: bCOctTreeNode *
    bFTouchCallback   m_funcTouchCallback;
    bFCullingCallback m_funcCullingCallback;
private:
    void              ExpandBox( GEInt, GEInt, GEInt );
    void              AddEntry( bCOctTreeEntryBase * );
    void              Check( void );
    void              CleanUp( void );
    void              IncludeBox( bCBox const & );
    void              MoveEntry( bCOctTreeEntryBase *, bCBox const & );
    void              RemoveEntry( bCOctTreeEntryBase * );
    bFCullingCallback SetCullingCallback( bFCullingCallback );
    bFTouchCallback   SetTouchCallback( bFTouchCallback );
    void              Traverse( bFTraverseCallback, bCBox const & );
    void              Traverse( bFTraverseCallback, bCVector const & );
    void              Traverse( bFTraverseCallback, bCPlane const *, GEInt );
    void              Traverse( bFTraverseCallback, bCPlane const *, GEInt, bCPlane const & );
public:
    bCOctTree & operator = ( bCOctTree const & );
public:
    bCOctTree( bCBox const & );
   ~bCOctTree( void );
};

#endif
