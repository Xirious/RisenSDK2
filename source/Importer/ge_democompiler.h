#ifndef GE_DEMOCOMPILER_H_INCLUDED
#define GE_DEMOCOMPILER_H_INCLUDED

class GE_DLLIMPORT iCDemoCompiler :
    public bCObjectRefBase
{
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual         ~iCDemoCompiler( void );
protected:
    char __FIXME[ 0x0048 - sizeof(bCObjectRefBase) ];
protected:
    GEInt AddDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
    void  CopyFiles( bCString const &, GEBool );
    void  DeleteFiles( bCString const &, GEBool );
    void  GetTemplateDependencies( eCTemplateEntity *, bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
    void  Invalidate( void );
    void  MakeDir( bCString const & );
public:
    void   AddDependency( eCEntity * );
    GEBool BuildDemo( gCWorld *, eCConfigFile const & );
    GEBool IsCompileSuccessfull( void ) const;
    GEBool ParseCommandLine( bCCommandLine const & );
public:
    iCDemoCompiler & operator = ( iCDemoCompiler const & );
protected:
    iCDemoCompiler( iCDemoCompiler const & );
public:
    iCDemoCompiler( void );
};
GE_ASSERT_SIZEOF( iCDemoCompiler, 0x0048 )

#endif
