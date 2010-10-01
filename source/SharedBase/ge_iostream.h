#ifndef GE_IOSTREAM_H_INCLUDED
#define GE_IOSTREAM_H_INCLUDED

class GE_DLLIMPORT bCIOStream :
    public bCIStream,
    public bCOStream
{
public: using bCIStream::Read;
public: virtual         ~bCIOStream( void );
public: using bCOStream::Write;
public:
    bCIOStream & operator = ( bCIOStream const & );
public:
    bCIOStream( bCIOStream const & );
    bCIOStream( void );
};

#endif
