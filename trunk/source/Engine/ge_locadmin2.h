#ifndef GE_LOCADMIN2_H_INCLUDED
#define GE_LOCADMIN2_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'eCLocAdmin2'

class GE_DLLIMPORT eCLocAdmin2
{
protected:
    bCString               m_strTextLanguage;
    bCString               m_strVoiceLanguage;
    bTObjArray< bCString > m_arrLanguages;
public:
    static eCLocAdmin2 & GE_STDCALL GetInstance( void );
public:
   ~eCLocAdmin2( void );
public:
    void            ApplyConfiguration( void );
    GEBool          CloneID( bCString const &, bCString const & );
    GEBool          ExistsID( bCString const & ) const;
    GEBool          ExistsLanguage( bCString const & ) const;
    bCString        FindLanguage( GEInt ) const;
    GEInt           FindLanguageIndex( bCString const & ) const;
    void            GetIDList( bTObjArray< bCString > & ) const;
    GEInt           GetLanguageCount( void ) const;
    bCUnicodeString GetStageDirection( bCString const &, bCString const & ) const;
    bCUnicodeString GetStageDirection( bCString const & ) const;
    bCUnicodeString GetString( bCString const &, bCString const & ) const;
    bCUnicodeString GetString( bCString const & ) const;
    bCString        GetTextLanguage( void ) const;
    bCString        GetVoiceLanguage( void ) const;
    GEBool          IsModified( void ) const;
    void            LanguageToStageDirectionColumn( bCString const &, bCString & ) const;
    void            LanguageToTextColumn( bCString const &, bCString & ) const;
    GEBool          Read( void );
    GEBool          RemoveID( bCString const & );
    GEBool          RenameID( bCString const &, bCString const & );
    void            ReserveID( bCString const & );
    GEBool          SetPair( bCString const &, bCUnicodeString const &, bCUnicodeString const & );
    GEBool          SetPair( bCString const &, bCString const &, bCUnicodeString const &, bCUnicodeString const & );
    GEBool          SetStageDirection( bCString const &, bCUnicodeString const & );
    GEBool          SetStageDirection( bCString const &, bCString const &, bCUnicodeString const & );
    GEBool          SetString( bCString const &, bCUnicodeString const & );
    GEBool          SetString( bCString const &, bCString const &, bCUnicodeString const & );
    void            SetTextLanguage( bCString const &, GEBool, GEBool );
    void            SetVoiceLanguage( bCString const & );
    GEBool          Write( void );
protected:
    eCLocAdmin2( void ); 
    eCLocAdmin2( eCLocAdmin2 const & );
protected:
    eCLocAdmin2 & operator = ( eCLocAdmin2 const & );
protected:
    void BuildLanguages( void );
    void Initialize( void );
    void ProcessPrefixes( bCString const & );
};
GE_ASSERT_SIZEOF( eCLocAdmin2, 0x0014 )

#pragma warning( pop )

#endif
