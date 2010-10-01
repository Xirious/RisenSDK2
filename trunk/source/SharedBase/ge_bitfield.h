#ifndef GE_BITFIELD_H_INCLUDED
#define GE_BITFIELD_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<>' needs to have dll-interface to be used by clients of class 'bCBitField'

class GE_DLLIMPORT bCBitField
{
public:
    enum bEIndex
    {
        bEIndex_Invalid = 0xFFFFFFFFL
    };
private:
    bTValArray< GEU32 > m_arrSlots;
    GEInt               m_iCount;
    GEInt               m_iIndex;
protected:
    static GEU32 const bEBits_All;
protected:
    GEU32 GetMask( GEInt ) const;
    GEInt GetOffset( GEInt ) const;
    GEInt GetSlotIndex( GEInt ) const;
public:
    GEU32 * AccessBitField( void );
    void    And( bCBitField const & );
    void    CopyFrom( bCBitField const & );
    void    CopyTo( bCBitField & ) const;
    void    Disable( GEInt );
    void    DisableAll( void );
    void    Enable( GEInt );
    void    EnableAll( void );
    void    ExpandAnd( bCBitField const & );
    void    ExpandOr( bCBitField const & );
    void    ExpandXor( bCBitField const & );
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
    void    Or( bCBitField const & );
    void    SetAt( GEInt, GEBool );
    void    SetCount( GEInt );
    void    ShiftLeft( GEI32 );
    void    ShiftRight( GEI32 );
    void    Toggle( GEInt );
    void    Xor( bCBitField const & );
public:
    GEBool             operator ==  ( bCBitField const & ) const;
    GEBool             operator !=  ( bCBitField const & ) const;
    GEBool             operator []  ( GEInt ) const;
    bCBitField const & operator >>  ( GEI32 ) const;               // inline local: static bCBitField arrResult;
    bCBitField const & operator <<  ( GEI32 ) const;               // inline local: static bCBitField arrResult;
    bCBitField const & operator &   ( bCBitField const & ) const;  // inline local: static bCBitField arrResult;
    bCBitField const & operator ~   ( void ) const;                // inline local: static bCBitField arrResult;
    bCBitField const & operator ^   ( bCBitField const & ) const;  // inline local: static bCBitField arrResult;
    bCBitField const & operator |   ( bCBitField const & ) const;  // inline local: static bCBitField arrResult;
    bCBitField &       operator >>= ( GEI32 );
    bCBitField &       operator <<= ( GEI32 );
    bCBitField &       operator &=  ( bCBitField const & );
    bCBitField &       operator |=  ( bCBitField const & );
    bCBitField &       operator ^=  ( bCBitField const & );
    bCIStream &        operator <<  ( bCIStream & );
    bCOStream &        operator >>  ( bCOStream & ) const;
    bCBitField &       operator =   ( bCBitField const & );
public:
    bCBitField( bCBitField const & );
    bCBitField( GEInt = 64 );
   ~bCBitField( void );
};

#pragma warning( pop )

#endif
