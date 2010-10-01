#ifndef GE_TRACKBITFIELD_H_INCLUDED
#define GE_TRACKBITFIELD_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<>' needs to have dll-interface to be used by clients of class 'bCTrackBitField'

class GE_DLLIMPORT bCTrackBitField
{
public:
    enum bEIndex
    {
        bEIndex_Invalid = 0xFFFFFFFFL
    };
private:
    bTValArray< GEU32 > m_arrSlots;
    GEInt               m_iCount;
    GEInt               m_iEnabled;
    GEInt               m_iIndex;
protected:
    static GEU32 const bEBits_All;
protected:
    GEU32 GetMask( GEInt ) const;
    GEInt GetOffset( GEInt ) const;
    GEInt GetSlotIndex( GEInt ) const;
public:
    GEU32 * AccessBitField( void );
    void    And( bCTrackBitField const & );
    void    CopyFrom( bCTrackBitField const & );
    void    CopyTo( bCTrackBitField & ) const;
    void    Disable( GEInt );
    void    DisableAll( void );
    void    Enable( GEInt );
    void    EnableAll( void );
    void    ExpandAnd( bCTrackBitField const & );
    void    ExpandOr( bCTrackBitField const & );
    void    ExpandXor( bCTrackBitField const & );
    GEBool  GetAt( GEInt ) const;
    GEInt   GetCapacity( void ) const;
    GEInt   GetCount( void ) const;
    GEInt   GetCountDisabled( void ) const;
    GEInt   GetCountEnabled( void ) const;
    GEInt   GetFirstDisabled( void ) const;
    GEInt   GetFirstEnabled( void ) const;
    GEInt   GetNextDisabled( void ) const;
    GEInt   GetNextEnabled( void ) const;
    GEInt   GetUpperBound( void ) const;
    void    Invert( void );
    GEBool  IsAnyDisabled( void ) const;
    GEBool  IsAnyEnabled( void ) const;
    GEBool  IsDisabled( GEInt ) const;
    GEBool  IsEmpty( void ) const;
    GEBool  IsEnabled( GEInt ) const;
    GEBool  IsValidIndex( GEInt ) const;
    void    Or( bCTrackBitField const & );
    void    SetAt( GEInt, GEBool );
    void    SetCount( GEInt );
    void    ShiftLeft( GEI32 );
    void    ShiftRight( GEI32 );
    void    Toggle( GEInt );
    void    Xor( bCTrackBitField const & );
public:
    bCTrackBitField const & operator >>  ( GEI32 ) const;                    // inline local: static bCTrackBitField arrResult;
    bCTrackBitField const & operator <<  ( GEI32 ) const;                    // inline local: static bCTrackBitField arrResult;
    GEBool                  operator ==  ( bCTrackBitField const & ) const;
    GEBool                  operator !=  ( bCTrackBitField const & ) const;
    GEBool                  operator []  ( GEInt ) const;
    bCTrackBitField const & operator &   ( bCTrackBitField const & ) const;  // inline local: static bCTrackBitField arrResult;
    bCTrackBitField const & operator ~   ( void ) const;                     // inline local: static bCTrackBitField arrResult;
    bCTrackBitField const & operator ^   ( bCTrackBitField const & ) const;  // inline local: static bCTrackBitField arrResult;
    bCTrackBitField const & operator |   ( bCTrackBitField const & ) const;  // inline local: static bCTrackBitField arrResult;
    bCTrackBitField &       operator >>= ( GEI32 );
    bCTrackBitField &       operator <<= ( GEI32 );
    bCTrackBitField &       operator &=  ( bCTrackBitField const & );
    bCTrackBitField &       operator |=  ( bCTrackBitField const & );
    bCTrackBitField &       operator ^=  ( bCTrackBitField const & );
    bCIStream &             operator <<  ( bCIStream & );
    bCOStream &             operator >>  ( bCOStream & ) const;
    bCTrackBitField &       operator =   ( bCTrackBitField const & );
public:
    bCTrackBitField( bCTrackBitField const & );
    bCTrackBitField( GEInt = 64 );
   ~bCTrackBitField( void );
};

#pragma warning( pop )

#endif
