#ifndef GE_INFOCOMMAND_H_INCLUDED
#define GE_INFOCOMMAND_H_INCLUDED

class GE_DLLIMPORT gCInfoCommand :
    public bCObjectRefBase
{
public:
    enum ETableAppendixColumn
    {
        //FIXME: gCInfoCommand::ETableAppendixColumn constants.
        ETableAppendixColumn_ForceDWORD = GE_FORCE_DWORD
    };
    enum ETableLanguageColumn
    {
        //FIXME: gCInfoCommand::ETableLanguageColumn constants.
        ETableLanguageColumn_ForceDWORD = GE_FORCE_DWORD
    };

public: virtual bCString        GetCommandName( void ) const;
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual GEBool          GetDialogDescription( SDialogDescription *, gCRuntimeInfo * );
public: virtual void            OldFormatWrite( bCString &, bCString &, bCString &, bCString &, bCString & ) const;
public: virtual void            OldFormatRead( GEInt, bCString const &, bCString const &, bCString const &, bCString const &, bCString const & );
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual void            GetTableKeys( bTObjArray< bCString > & );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: virtual void            OnAttachedToInfo( gCInfo const & );
public: virtual bCString        ToString( void ) const;
public: virtual void            FromString( bCString const & );
public: virtual gCInfoCommand * Clone( void ) const;
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommand, bCObjectRefBase )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommand( void );
public: using  bCObjectRefBase::IsValid;
public:
    bCString &          AccessEntity1( void );
    bCString &          AccessEntity2( void );
    eCLocString &       AccessText( void );
    bCString const &    GetEntity1( void ) const;
    bCString const &    GetEntity2( void ) const;
    GEBool              GetTableValue( bCString const &, ETableAppendixColumn, gCInfo const &, GEInt, bCString & ) const;
    GEBool              GetTableValue( bCString const &, ETableLanguageColumn, gCInfo const &, bCString const &, bCString & ) const;
    eCLocString const & GetText( void ) const;
    GEBool              StartScriptState( bCString );
    GEBool              UpdateTable( CFXTable &, bTObjMap< bCString, GEInt> &, GEInt &, GEInt &, gCInfo const & );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommand, 0x0008 )

#endif
