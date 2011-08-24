#ifndef GE_RESOURCEOUTPUTSTREAM2_H_INCLUDED
#define GE_RESOURCEOUTPUTSTREAM2_H_INCLUDED

class GE_DLLIMPORT eCResourceOutputStream2 :
    public bCMemoryStream
{
public: virtual ~eCResourceOutputStream2( void );
public:
    eCResourceOutputStream2 & operator = ( eCResourceOutputStream2 const & );
public:
    eCResourceOutputStream2( eCResourceOutputStream2 const & );
    eCResourceOutputStream2( void );
};
GE_ASSERT_SIZEOF( eCResourceOutputStream2, 0x0020 );

#endif
