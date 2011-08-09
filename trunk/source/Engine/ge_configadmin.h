#ifndef GE_CONFIGADMIN_H_INCLUDED
#define GE_CONFIGADMIN_H_INCLUDED

enum eECfgLayer
{
    eECfgLayer_Global,
    eECfgLayer_Local,
    eECfgLayer_Options,
    eECfgLayer_Override,
    eECfgLayer_Count,
    eECfgLayer_ForceDWORD = GE_FORCE_DWORD
};

struct eSCfgKeyValuePair
{
    bCString m_strKey;
    bCString m_strValue;
};
GE_ASSERT_SIZEOF( eSCfgKeyValuePair, 0x0008 )

class GE_DLLIMPORT eCConfigAdmin
{
public: virtual ~eCConfigAdmin( void );
protected:
    bCXMLParserNode * m_pXMLParserNode;
public:
    static GELPChar s_strCfgLayer[ eECfgLayer_Count ];
    static GELPChar s_strOptionsPath;
protected:
    static void     GE_STDCALL ConvertFromString( bCString const &, GEInt & );
    static void     GE_STDCALL ConvertFromString( bCString const &, GEU32 & );
    static void     GE_STDCALL ConvertFromString( bCString const &, GEFloat & );
    static void     GE_STDCALL ConvertFromString( bCString const &, bCString & );
    static void     GE_STDCALL ConvertFromString( bCString const &, GEBool & );
    static bCString GE_STDCALL ConvertToString( GEInt const & );
    static bCString GE_STDCALL ConvertToString( GEU32 const & );
    static bCString GE_STDCALL ConvertToString( GEFloat const & );
    static bCString GE_STDCALL ConvertToString( bCString const & );
    static bCString GE_STDCALL ConvertToString( GEBool const & );
protected:
    GEBool GetValueString( bCString const &, bCString &, bCString const & );
    GEBool SetValueString( bCString const &, bCString const & );
public:
    static eCConfigAdmin & GE_STDCALL GetInstance( void );
public:
    GEBool   CreateConfig( bCString const & );
    GEBool   CreateConfig( eECfgLayer );
    bCString FindNextCfgEntry( bCString const & );
    GEBool   GetAttributesFromNode( bTObjArray< eSCfgKeyValuePair > &, bCString const & );
    GEBool   GetKeysFromNode( bTObjArray< bCString > &, bCString const & );
    GEBool   LoadConfigXML( bCString const &, bCString const &, GEBool );
    GEBool   LoadConfigXML( bCString const &, eECfgLayer, GEBool );
    GEBool   RemoveValue( bCString const & );
    GEBool   RemoveValue( eECfgLayer, bCString const & );
    GEBool   SaveConfigXML( bCString const &, bCString const & );
    GEBool   SaveConfigXML( bCString const &,eECfgLayer );
public:
    eCConfigAdmin & operator = ( eCConfigAdmin const & );
public:
    eCConfigAdmin( eCConfigAdmin const & );
    eCConfigAdmin( void );
};
GE_ASSERT_SIZEOF( eCConfigAdmin, 0x0008 )

#endif
