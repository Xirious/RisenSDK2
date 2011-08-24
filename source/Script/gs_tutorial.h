#ifndef GS_TUTORIAL_H_INCLUDED
#define GS_TUTORIAL_H_INCLUDED

class GE_DLLIMPORT Tutorial
{
public:
    GEInt           GetDuration( bCString ) const;
    GEBool          GetEnable( void ) const;
    bCString        GetLoadingImage( void ) const;
    bCUnicodeString GetLoadingText( void ) const;
    GEBool          IsAvailable( bCString ) const;
    GEBool          IsCompleted( bCString ) const;
    GEBool          IsPermanent( bCString ) const;
    GEBool          IsRunning( bCString ) const;
    GEBool          ReadConfigUser( void ) const;
    void            SetEnable( GEBool );
    GEBool          StartEvent( bCString, GEBool );
    void            StopCurrentEvent( GEBool );
    void            StopEvent( bCString, GEBool );
    GEBool          WriteConfigUser( void ) const;
public:
    Tutorial & operator = ( Tutorial const & );
public:
    Tutorial( void );
   ~Tutorial( void );
};

GE_DLLIMPORT_EXTC Tutorial tutorial;

#endif
