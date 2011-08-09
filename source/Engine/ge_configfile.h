#ifndef GE_CONFIGFILE_H_INCLUDED
#define GE_CONFIGFILE_H_INCLUDED

class GE_DLLIMPORT eCConfigFile_KeyObject
{
protected:
    bCString m_strKey;
    bCString m_strValue;
    bCString m_strComment;
    GEU16    m_u16Whitespaces;
             GE_PADDING( 2 )
public:
    void             Clear( void );
    void             CopyFrom( eCConfigFile_KeyObject const & );
    void             Create( void );
    void             Destroy( void );
    bCString const & GetComment( void ) const;
    bCString const & GetKey( void ) const;
    bCString &       GetValue( void );
    bCString const & GetValue( void ) const;
    GEBool           HasKeyOnly( void ) const;
    void             Invalidate( void );
    GEBool           IsComment( void ) const;
    GEBool           IsEmpty( void ) const;
    void             SetComment( bCString const & );
    void             SetKey( bCString const & );
    void             SetValue( bCString const & );
    void             Write( bCOStream & );
public:
    eCConfigFile_KeyObject const & operator = ( eCConfigFile_KeyObject const & );
public:
             eCConfigFile_KeyObject( bCString const &, bCString const &, bCString const & );
             eCConfigFile_KeyObject( bCString const &, bCString const & );
    explicit eCConfigFile_KeyObject( bCString const & );
             eCConfigFile_KeyObject( eCConfigFile_KeyObject & );
             eCConfigFile_KeyObject( void );
            ~eCConfigFile_KeyObject( void );
};
GE_ASSERT_SIZEOF( eCConfigFile_KeyObject, 0x0010 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'eCConfigFile_SectionObject'

class GE_DLLIMPORT eCConfigFile_SectionObject
{
protected:
    bCString                             m_strSectionName;
    bTObjArray< eCConfigFile_KeyObject > m_arrKeyArray;
    GEU16                                m_u16Whitespaces;
                                         GE_PADDING( 2 )
protected:
    GEInt                    GetKeyIndex( bCString const & ) const;
    eCConfigFile_KeyObject & InsertNewEmptyKey( void );
    GEBool                   IsValidKey( bCString const & ) const;
    GEBool                   SetKey( bCString const &, bCString const & );
    GEBool                   SetKey( bCString const & );
    void                     SetSectionName( bCString const & );
    void                     SetWhitespaces( GEU16 );
public:
    void                           Clear( void );
    void                           CopyFrom( eCConfigFile_SectionObject const & );
    void                           Create( void );
    void                           Destroy( void );
    GEInt                          GetKeyCount( void ) const;
    eCConfigFile_KeyObject const * GetKeyObject( GEInt ) const;
    bCString const &               GetSectionName( void ) const;
    bCString const &               GetValue( bCString const & ) const;
    GEBool                         GetValue( bCString const &, bCString & ) const;
    void                           Invalidate( void );
    GEBool                         IsValidKey( GEInt ) const;
    GEBool                         RemoveKey( bCString const & );
    GEBool                         RemoveValue( bCString const & );
    void                           Write( bCOStream & );
public:
    bCString &                         operator [] ( bCString const & );
    bCString const &                   operator [] ( bCString const & ) const;
    eCConfigFile_SectionObject const & operator =  ( eCConfigFile_SectionObject const & );
public:
    eCConfigFile_SectionObject( eCConfigFile_SectionObject & );
    eCConfigFile_SectionObject( void );
   ~eCConfigFile_SectionObject( void );
};
GE_ASSERT_SIZEOF( eCConfigFile_SectionObject, 0x0014 )

#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'eCConfigFile'
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT eCConfigFile
{
public:
    struct eSConfigValue
    {
        bCString * m_pstrKey;
        bCString * m_pstrValue;
    };
    GE_ASSERT_SIZEOF( eSConfigValue, 0x0008 )
public: virtual GEBool ReadFile( bCIStream & );
protected:
    bCString                                 m_strFilePath;
    bTObjArray< eCConfigFile_SectionObject > m_arrSectionArray;
    GEBool                                   m_bValid;
                                             GE_PADDING( 3 )
protected:
    eCConfigFile_SectionObject * AccessSection( bCString const & );
public:
    void                                             AddComment( bCString const & );
    void                                             AddEmptyLine( void );
    void                                             Clear( void );
    GEBool                                           Contains( bCString const &, bCString const & ) const;
    GEBool                                           Contains( bCString const & ) const;
    void                                             CopyFrom( eCConfigFile const & );
    void                                             Create( void );
    void                                             Destroy( void );
    GEBool                                           GetBool( bCString const &, bCString const & ) const;
    GEBool                                           GetBool( bCString const &, bCString const &, GEBool ) const;
    bCString const &                                 GetFilePath( void ) const;
    GEFloat                                          GetFloat( bCString const &, bCString const & ) const;
    GEFloat                                          GetFloat( bCString const &, bCString const &, GEFloat ) const;
    GEI16                                            GetI16( bCString const &, bCString const & ) const;
    GEI16                                            GetI16( bCString const &, bCString const &, GEI16 ) const;
    GEI32                                            GetI32( bCString const &, bCString const & ) const;
    GEI32                                            GetI32( bCString const &, bCString const &, GEI32 ) const;
    GEI8                                             GetI8( bCString const &, bCString const & ) const;
    GEI8                                             GetI8( bCString const &, bCString const &, GEI8 ) const;
    GEInt                                            GetInt( bCString const &, bCString const & ) const;
    GEInt                                            GetInt( bCString const &, bCString const &, GEInt ) const;
    eCConfigFile_SectionObject const *               GetSection( bCString const & ) const;
    bTObjArray< eCConfigFile_SectionObject > &       GetSectionArray( void );
    bTObjArray< eCConfigFile_SectionObject > const & GetSectionArray( void ) const;
    GEBool                                           GetSectionBlock( bCString, bTObjArray< eSConfigValue > & ) const;
    GEBool                                           GetSections( bTObjArray< bCString > & ) const;
    bCString &                                       GetString( bCString const &, bCString const & ) const;
    bCString &                                       GetString( bCString const &, bCString const &, bCString const & ) const;
    GEU16                                            GetU16( bCString const &, bCString const & ) const;
    GEU16                                            GetU16( bCString const &, bCString const &, GEU16 ) const;
    GEU32                                            GetU32( bCString const &, bCString const & ) const;
    GEU32                                            GetU32( bCString const &, bCString const &, GEU32 ) const;
    GEU8                                             GetU8( bCString const &, bCString const & ) const;
    GEU8                                             GetU8( bCString const &, bCString const &, GEU8 ) const;
    bCString &                                       GetValue( bCString const &, bCString const & );
    bCString const &                                 GetValue( bCString const &, bCString const & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEI8 & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEU8 & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEI16 & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEU16 & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEInt & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEI32 & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEU32 & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEFloat & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEDouble & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, bCString & ) const;
    GEBool                                           GetValue( bCString const &, bCString const &, GEBool & ) const;
    void                                             Invalidate( void );
    GEBool                                           IsOpen( void ) const;
    GEBool                                           ReadFile( bCString const & );
    GEBool                                           RemoveKey( bCString const &, bCString const & );
    GEBool                                           RemoveSection( bCString const & );
    GEBool                                           RemoveValue( bCString const &, bCString const & );
    GEBool                                           SetSection( bCString const &, bCString const & );
    GEBool                                           SetSection( bCString const & );
    GEBool                                           SetValue( bCString const &, bCString const &, bCString const & );
    GEBool                                           SetValue( bCString const &, bCString const &, GEI8 );
    GEBool                                           SetValue( bCString const &, bCString const &, GEU8 );
    GEBool                                           SetValue( bCString const &, bCString const &, GEI16 );
    GEBool                                           SetValue( bCString const &, bCString const &, GEU16 );
    GEBool                                           SetValue( bCString const &, bCString const &, GEInt );
    GEBool                                           SetValue( bCString const &, bCString const &, GEI32 );
    GEBool                                           SetValue( bCString const &, bCString const &, GEU32 );
    GEBool                                           SetValue( bCString const &, bCString const &, GEFloat );
    GEBool                                           SetValue( bCString const &, bCString const &, GEDouble );
    GEBool                                           SetValue( bCString const &, bCString const &, GEBool );
    GEBool                                           Sort( void );
    GEBool                                           Update( void );
    GEBool                                           WriteFile( bCString const & );
    GEBool                                           WriteFile( void );
protected:
    eCConfigFile const & operator = ( eCConfigFile const & );
public:
    bCOStream &      operator >> ( bCOStream & );
    bCIStream &      operator << ( bCIStream & );
    bCString &       operator () ( bCString const &, bCString const & );
    bCString const & operator () ( bCString const &, bCString const & ) const;
public:
    explicit eCConfigFile( bCString const & );
             eCConfigFile( eCConfigFile const & );
             eCConfigFile( void );
            ~eCConfigFile( void );
};
GE_ASSERT_SIZEOF( eCConfigFile, 0x0018 )

#pragma warning( pop )

#endif
