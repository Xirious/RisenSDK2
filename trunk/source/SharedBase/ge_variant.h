#ifndef GE_VARIANT_H_INCLUDED
#define GE_VARIANT_H_INCLUDED

class GE_DLLIMPORT bCVariant
{
public:
    enum bEType
    {
        bEType_Empty,
        bEType_U8,
        bEType_I8,
        bEType_U16,
        bEType_I16,
        bEType_U32,
        bEType_I32,
        bEType_Int,
        bEType_U64,
        bEType_I64,
        bEType_Bool,
        bEType_Float,
        bEType_Double,
        bEType_VoidPointer,
        bEType_String,
        bEType_ForceDWORD = GE_FORCE_DWORD
    };
    union bUType
    {
        GEU8     m_u8Data;
        GEI8     m_i8Data;
        GEU16    m_u16Data;
        GEI16    m_i16Data;
        GEU32    m_u32Data;
        GEI32    m_i32Data;
        GEU64    m_u64Data;
        GEI64    m_i64Data;
        GEInt    m_iData;
        GEBool   m_bData;
        GEFloat  m_fData;
        GEDouble m_dData;
        GELPVoid m_pData;
        GELPChar m_pcData;
    };
private:
    bEType m_Type;
           GE_PADDING( 4 )
    bUType m_Data;
protected:
    bUType & AccessData( void );
    bEType & AccessType( void );
    void     Init( void );
    void     SetData( bUType const & );
    void     SetType( bEType const & );
public:
    void             Clear( void );
    void             CopyFrom( bCVariant const & );
    void             CopyTo( bCVariant & ) const;
    bUType const &   GetData( void ) const;
    void             GetData( bUType & ) const;
    void             GetData( GEU8 & ) const;
    void             GetData( GEI8 & ) const;
    void             GetData( GEU16 & ) const;
    void             GetData( GEI16 & ) const;
    void             GetData( GEU32 & ) const;
    void             GetData( GEI32 & ) const;
    void             GetData( GEInt & ) const;
    void             GetData( GEU64 & ) const;
    void             GetData( GEI64 & ) const;
    void             GetData( GEBool & ) const;
    void             GetData( GEFloat & ) const;
    void             GetData( GEDouble & ) const;
    void             GetData( GELPVoid & ) const;
    void             GetData( GELPChar & ) const;
    GEU8 const &     GetU8( void ) const;
    GEI8 const &     GetI8( void ) const;
    GEU16 const &    GetU16( void ) const;
    GEI16 const &    GetI16( void ) const;
    GEU32 const &    GetU32( void ) const;
    GEI32 const &    GetI32( void ) const;
    GEInt const &    GetInt( void ) const;
    GEU64 const &    GetU64( void ) const;
    GEI64 const &    GetI64( void ) const;
    GEBool const &   GetBool( void ) const;
    GEFloat const &  GetFloat( void ) const;
    GEDouble const & GetDouble( void ) const;
    GELPVoid const & GetVoidPointer( void ) const;
    GELPChar const & GetString( void ) const;
    bEType const &   GetType( void ) const;
    void             GetType( bEType & ) const;
    void             SetData( GEU8 );
    void             SetData( GEI8 );
    void             SetData( GEU16 );
    void             SetData( GEI16 );
    void             SetData( GEU32 );
    void             SetData( GEI32 );
    void             SetData( GEInt );
    void             SetData( GEU64 );
    void             SetData( GEI64 );
    void             SetData( GEBool );
    void             SetData( GEFloat );
    void             SetData( GEDouble );
    void             SetData( GELPVoid );
    void             SetData( GELPChar );
public:
    bCVariant const & operator = ( GEU8 const & );
    bCVariant const & operator = ( GEI8 const & );
    bCVariant const & operator = ( GEU16 const & );
    bCVariant const & operator = ( GEI16 const & );
    bCVariant const & operator = ( GEU32 const & );
    bCVariant const & operator = ( GEI32 const & );
    bCVariant const & operator = ( GEInt const & );
    bCVariant const & operator = ( GEU64 const & );
    bCVariant const & operator = ( GEI64 const & );
    bCVariant const & operator = ( GEBool const & );
    bCVariant const & operator = ( GEFloat const & );
    bCVariant const & operator = ( GEDouble const & );
    bCVariant const & operator = ( GELPVoid const & );
    bCVariant const & operator = ( GELPChar const & );
    bCVariant const & operator = ( bCVariant const & );
public:
    bCVariant( GEU8 const & );
    bCVariant( GEI8 const & );
    bCVariant( GEU16 const & );
    bCVariant( GEI16 const & );
    bCVariant( GEU32 const & );
    bCVariant( GEI32 const & );
    bCVariant( GEInt const & );
    bCVariant( GEU64 const & );
    bCVariant( GEI64 const & );
    bCVariant( GEBool const & );
    bCVariant( GEFloat const & );
    bCVariant( GEDouble const & );
    bCVariant( GELPVoid const & );
    bCVariant( GELPChar const & );
    bCVariant( bCVariant const & );
    bCVariant( void );
   ~bCVariant( void );
};

#endif
