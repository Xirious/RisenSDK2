#ifndef GE_XMLPARSERNODE_H_INCLUDED
#define GE_XMLPARSERNODE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTArrayMap<>' needs to have dll-interface to be used by clients of class 'bCXMLParserNode'

class GE_DLLIMPORT bCXMLParserNode
{
public: virtual ~bCXMLParserNode( void );
private:
    bCString                        m_strTag;
    bCString                        m_strText;
    bTArrayMap< bCString, bCString> m_mapAttributes;
    bCXMLParserNode *               m_pParent;
    bCXMLParserNode *               m_pPrevSibling;
    bCXMLParserNode *               m_pNextSibling;
    bCXMLParserNode *               m_pFirstChild;
public:
    void                                     Dump( GEInt ) const;
    void                                     DumpNode( GEInt, GEBool ) const;
    GEBool                                   GetAttribute( bCString const &, GEI8 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEChar & ) const;
    GEBool                                   GetAttribute( bCString const &, GEU8 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEI16 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEU16 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEInt & ) const;
    GEBool                                   GetAttribute( bCString const &, GEUInt & ) const;
    GEBool                                   GetAttribute( bCString const &, GEI32 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEU32 & ) const;
    GEBool                                   GetAttribute( bCString const &, float & ) const;
    GEBool                                   GetAttribute( bCString const &, double & ) const;
    GEBool                                   GetAttribute( bCString const &, bCString & ) const;
    GEBool                                   GetAttribute( bCString const &, bCGuid & ) const;
    GEBool                                   GetAttribute( bCString const &, bCUnicodeString & ) const;
    GEBool                                   GetAttribute( bCString const &, GEI64 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEU64 & ) const;
    GEBool                                   GetAttribute( bCString const &, GEBool & ) const;
    bTArrayMap< bCString, bCString > &       GetAttributes( void );
    bTArrayMap< bCString, bCString > const & GetAttributes( void ) const;
    bCXMLParserNode *                        GetChild( bCString const & ) const;
    GEInt                                    GetChildCount( void ) const;
    bCXMLParserNode *                        GetFirstChild( void ) const;
    bCXMLParserNode *                        GetFirstSibling( void ) const;
    bCXMLParserNode *                        GetLastChild( void ) const;
    bCXMLParserNode *                        GetLastSibling( void ) const;
    GEInt                                    GetLevel( void ) const;
    bCXMLParserNode *                        GetNextSibling( void ) const;
    bCXMLParserNode *                        GetParent( void ) const;
    bCXMLParserNode *                        GetPrevSibling( void ) const;
    bCXMLParserNode *                        GetRoot( void ) const;
    bCString                                 GetTag( void ) const;
    bCString                                 GetText( void ) const;
    bCString                                 GetXML( GEInt, GEBool ) const;
    GEBool                                   GetXML( bCString &, GEInt, GEBool ) const;
    bCXMLParserNode *                        InsertChild( void );
    GEBool                                   InsertChild( bCXMLParserNode * );
    GEBool                                   IsAncestor( bCXMLParserNode const * ) const;
    GEBool                                   IsChild( bCXMLParserNode const * ) const;
    GEBool                                   IsDescendant( bCXMLParserNode const * ) const;
    GEBool                                   IsParent( bCXMLParserNode const * ) const;
    GEBool                                   IsPredecessor( bCXMLParserNode const * ) const;
    GEBool                                   IsSibling( bCXMLParserNode const * ) const;
    GEBool                                   IsSuccessor( bCXMLParserNode const * ) const;
    void                                     RemoveAllChildren( void );
    GEBool                                   RemoveChild( bCXMLParserNode * );
    void                                     SetAttribute( bCString const &, bCString const & );
    void                                     SetAttribute( bCString const &, bCGuid const & );
    void                                     SetAttribute( bCString const &, bCUnicodeString const & );
    void                                     SetAttribute( bCString const &, GEI8 );
    void                                     SetAttribute( bCString const &, GEChar );
    void                                     SetAttribute( bCString const &, GEU8 );
    void                                     SetAttribute( bCString const &, GEI16 );
    void                                     SetAttribute( bCString const &, GEU16 );
    void                                     SetAttribute( bCString const &, GEInt );
    void                                     SetAttribute( bCString const &, GEUInt );
    void                                     SetAttribute( bCString const &, GEI32 );
    void                                     SetAttribute( bCString const &, GEU32 );
    void                                     SetAttribute( bCString const &, GEFloat );
    void                                     SetAttribute( bCString const &, GEDouble );
    void                                     SetAttribute( bCString const &, GELPChar );
    void                                     SetAttribute( bCString const &, GEI64 );
    void                                     SetAttribute( bCString const &, GEU64 );
    void                                     SetAttribute( bCString const &, GEBool );
    void                                     SetAttributes( GELPCChar * );
    void                                     SetTag( bCString const & );
    void                                     SetText( bCString const & );
public:
    bCXMLParserNode & operator = ( bCXMLParserNode const & );
public:
    bCXMLParserNode( bCXMLParserNode const & );
    bCXMLParserNode( void );
};

#pragma warning( pop )

#endif
