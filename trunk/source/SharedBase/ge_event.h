#ifndef GE_EVENT_H_INCLUDED
#define GE_EVENT_H_INCLUDED

class GE_DLLIMPORT bCEvent :
    public bCObjectRefBase
{
public:    virtual GEBool   OnRead( bCIStream & );
public:    virtual GEBool   OnWrite( bCOStream & );
public:    virtual bEResult Create( void );
public:    virtual void     Destroy( void );
protected: virtual         ~bCEvent( void );
public:    virtual GEBool   IsDeleteable( void );
public:
    bCString m_strName;
    GEBool   m_bReserved;
             GE_PADDING( 3 )
    GEU32    m_u32Reserved;
protected:
    void Invalidate( void );
public:
    bCEvent & operator = ( bCEvent const & );
public:
    bCEvent( bCEvent const & );
    bCEvent( void );
};

#endif
