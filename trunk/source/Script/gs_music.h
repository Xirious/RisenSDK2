#ifndef GS_MUSIC_H_INCLUDED
#define GS_MUSIC_H_INCLUDED

class GE_DLLIMPORT Music
{
public:
    void    EnableAutoUpdate( GEBool );
    GEFloat GetMusicVolume( void );
    void    Request( bCString, GEInt, GEFloat );
    void    SetMusicVolume( GEFloat );
    void    StartOverlay( bCString );
    void    Stop( void );
    void    StopOverlay( void );
private:
    Music( void );  // hide constructor
   ~Music( void );  // hide destructor
private:
    Music & operator = ( Music const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC Music music;

#endif
