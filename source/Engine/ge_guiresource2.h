#ifndef GE_GUIRESOURCE2_H_INCLUDED
#define GE_GUIRESOURCE2_H_INCLUDED

class GE_DLLIMPORT eCGuiResource2 :
    public eCDocObject,
    virtual public IFFUnknown
{
public:    virtual void                       OnFinalRelease( void );                        
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;                   
public:    virtual GEU32                      AddReference( void );                          
public:    virtual GEU32                      ReleaseReference( void );                      
public:    virtual GEU32                      GetReferenceCount( void );                     
public:    virtual                           ~eCGuiResource2( void );                        
public:    virtual bCString                   GetRawExt( void ) const;                       
public:    virtual bCString                   GetRawPath( void ) const;                      
public:    virtual GEU32                      AddRef( void );                                
public:    virtual GEU32                      Release( void );                               
public:    virtual GEU32                      QueryInterface( FFGUID const &, FFLPVoid * );  
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    // sizeof(eCGuiResource2) 0018
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL GetClassRawExt( void );
    static bCString                   GE_STDCALL GetClassRawPath( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static eCGuiResource2 *           GE_STDCALL LoadBinary( bCIStream & );
    static eCGuiResource2 *           GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static char s_carrAllocBuffer[];
public:
    eCGuiResource2 & operator = ( eCGuiResource2 const & );
public:
    eCGuiResource2( eCGuiResource2 const & );
    eCGuiResource2( void );
};

#endif
