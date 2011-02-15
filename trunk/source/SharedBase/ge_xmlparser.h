#ifndef GE_XMLPARSER_H_INCLUDED
#define GE_XMLPARSER_H_INCLUDED

class GE_DLLIMPORT bCXMLParser
{
public:
    enum EEncoding
    {
        EEncoding_Default    = 1,
        EEncoding_ForceDWORD = GE_FORCE_DWORD
    };
private:
    GELPVoid m_pParser;
public:
    GEBool            Create( EEncoding );
    void              Destroy( void );
    bCXMLParserNode * Parse( bCString const & );
public:
    bCXMLParser & operator = ( bCXMLParser const & );
public:
    bCXMLParser( void );
   ~bCXMLParser( void );
};

#endif
