#ifndef GE_DOCARCHIVE_H_INCLUDED
#define GE_DOCARCHIVE_H_INCLUDED

//FIXME: bTRefPropertyArray
template< typename T >
class bTRefPropertyArray :
    public bTPtrArray< T >
{
};

struct eSDocArchiveConfig
{
    bCString               m_strBinaryPath;
    bCString               m_strBinaryName;
    bCString               m_strBinaryExt;
    bCString               m_strRawPath;
    bTObjArray< bCString > m_arrRawExts;
    __forceinline eSDocArchiveConfig( GELPCChar a_pcBinaryPath, GELPCChar a_pcBinaryName, GELPCChar a_pcBinaryExt, GELPCChar a_pcRawPath ) :
        m_strBinaryPath( a_pcBinaryPath ), m_strBinaryName( a_pcBinaryName ), m_strBinaryExt( a_pcBinaryExt ), m_strRawPath( a_pcRawPath )
    {
    }
    __forceinline ~eSDocArchiveConfig( void )
    {
    }
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTRefPropertyArray<>' needs to have dll-interface to be used by clients of class 'eCDocArchive'

class GE_DLLIMPORT eCDocArchive
{
private:
    class CHeader
    {
        SFFFileTime m_RawFileTime;
        bCString    m_strRawFileName;
    };
protected: virtual void OnClearDocs( void );
protected: virtual void OnRegisterDoc( eCDocObject * );
public:    virtual     ~eCDocArchive( void );
private:
    eSDocArchiveConfig                  m_Config;
    bTRefPropertyArray< eCDocObject * > m_arrDocuments;
private:
    void   ClearDocs( void );
    GEBool CollectHeaders( bTObjArray< CHeader > & );
    GEBool ExportFile( eCDocObject * );
    GEBool ImportFile( bCString const & );
    GEBool ImportPath( bCString const &, bTObjArray< bCString > const & );
    GEBool IsBinaryValid( void );
    GEBool IsUpToDate( bTObjArray< CHeader > const & );
    GEBool IsUpToDate( CHeader const & );
    GEBool IsUpToDate( bCString const &, bTObjArray< bCString > const &, bTObjArray< CHeader > & );
    GEBool RegisterDoc( eCDocObject * );
public:
    void                                        Create( eSDocArchiveConfig const & );
    void                                        Destroy( void );
    GEBool                                      ExportRaw( void );
    bTRefPropertyArray< eCDocObject * > &       GetDocuments( void );
    bTRefPropertyArray< eCDocObject * > const & GetDocuments( void ) const;
    GEBool                                      ImportRaw( void );
    GEBool                                      Load( void );
    GEBool                                      ReadBinary( void );
    GEBool                                      WriteBinary( void );
public:
    eCDocArchive & operator = ( eCDocArchive const & );
public:
    eCDocArchive( eCDocArchive const & );
    eCDocArchive( void );
};

#pragma warning( pop )

#endif
