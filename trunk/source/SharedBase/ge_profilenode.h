#ifndef GE_PROFILENODE_H_INCLUDED
#define GE_PROFILENODE_H_INCLUDED

struct bSProfileStats
{
    GEFloat m_fFrameTime;
    GEFloat m_fTotalTime;
    GEFloat m_fAverageTime;
    GEFloat m_fMaximumTime;
    GEFloat m_fPeakTime;
    GEFloat m_fFramePercent;
    GEFloat m_fTotalPercent;
    GEInt   m_iFrameCalls;
    GEU32   m_iTotalCalls;
    GEFloat m_fAverageCalls;
    GEU32   m_iMaximumCalls;
    GEU32   m_iPeakCalls;
    GEU32   m_iFrameCount;
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValQueue<>' needs to have dll-interface to be used by clients of class 'bCProfileNode'

class GE_DLLIMPORT bCProfileNode
{
private:
    struct bSFrame
    {
        GEI64 m_i64TimeCount;
        GEInt m_iCalls;
              GE_PADDING( 4 )
    };
    GELPCChar             m_pcName;
    GEInt                 m_iCalls;
    GEI64                 m_i64TimeCount;
    GEI64                 m_i64StartTimeCount;
    GEInt                 m_iCallDepth;
    GEBool                m_bAbsolute;
                          GE_PADDING( 3 )
    bTValQueue< bSFrame > m_queFrames;
    bSProfileStats        m_Stats;
    bCProfileNode *       m_pParent;
    bCProfileNode *       m_pChild;
    bCProfileNode *       m_pSibling;
                          GE_PADDING1( 4 )
public:
    void                   Call( void );
    GEInt                  GetCalls( void ) const;
    bCProfileNode *        GetChild( void ) const;
    GELPCChar              GetName( void ) const;
    bCProfileNode *        GetParent( void ) const;
    bCProfileNode *        GetSibling( void ) const;
    bSProfileStats const & GetStats( void ) const;
    bCProfileNode *        GetSubNode( GELPCChar, GEBool );
    GEBool                 IsAbsolute( void ) const;
    GEBool                 IsChildOf( bCProfileNode const * ) const;
    void                   NextFrame( GEBool );
    void                   PrepareStats( GEInt );
    GEBool                 Return( GEFloat );
    GEBool                 Return( void );
    void                   SetQueueLength( GEInt );
public:
    bCProfileNode & operator = ( bCProfileNode const & );
public:
    bCProfileNode( bCProfileNode const & );
    bCProfileNode( GELPCChar, bCProfileNode *, GEBool );
   ~bCProfileNode( void );
};

#pragma warning( pop )

#endif
