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
public:
    Music & operator = ( Music const & );
public:
    Music( void );
   ~Music( void );
};

GE_DLLIMPORT_EXTC Music music;

#endif
