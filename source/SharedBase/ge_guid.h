#ifndef GE_GUID_H_INCLUDED
#define GE_GUID_H_INCLUDED

class GE_DLLIMPORT bCGuid
{
private:
    bSGuid m_Guid;   // 0000
    GEBool m_Valid;  // 0010
           GE_PADDING( 3 )
    // sizeof(bCGuid)   0014
protected:
    GEBool IsEqualTo( bCGuid const & ) const;
    GEBool IsGreaterThan( bCGuid const & ) const;
    GEBool IsLessThan( bCGuid const & ) const;
    GEInt  Compare( bCGuid const & ) const;
    void   Clear( void );
    void   Init( void );
public:
    static bCGuid const & GE_STDCALL GetInvalidGuid( void );
    static bCGuid const & GE_STDCALL GetNullGuid( void );
public:
    bSGuid *       GetGuid( void );
    bSGuid const * GetGuid( void ) const;
    bCString       GetText( void ) const;
    GEBool         IsNull( void ) const;
    GEBool         IsValid( void ) const;
    GEBool         SetText( bCString const & );
    void           CopyFrom( bCGuid const & );
    void           CopyTo( bCGuid & ) const;
    void           Generate( void );
    void           MakeInvalidGuid( void );
    void           MakeNullGuid( void );
    void           SetGuid( bSGuid const & );
    void           SetGuid( bSGuid const * );
    void           SetGuid( bCString const & );
public:
    bCGuid & operator =              ( bSGuid const & );
    bCGuid & operator =              ( bSGuid const * );
    bCGuid & operator =              ( bCGuid const & );
    bCGuid & operator =              ( bCString const & );
    GEBool   operator !=             ( bCGuid const & ) const;
    GEBool   operator <              ( bCGuid const & ) const;
    GEBool   operator <=             ( bCGuid const & ) const;
    GEBool   operator ==             ( bCGuid const & ) const;
    GEBool   operator >              ( bCGuid const & ) const;
    GEBool   operator >=             ( bCGuid const & ) const;
             operator bSGuid &       ( void );
             operator bSGuid *       ( void );
             operator bSGuid const & ( void ) const;
             operator bSGuid const * ( void ) const;
public:
    bCGuid( bSGuid const & );
    bCGuid( bSGuid const * );
    bCGuid( bCGuid const & );
    bCGuid( bCString const & );
    bCGuid( void );
   ~bCGuid( void );
};

template<>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue< bCGuid >( bCGuid const & );

#endif
