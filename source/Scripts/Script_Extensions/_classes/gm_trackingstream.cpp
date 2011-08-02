#include "gm_trackingstream.h"

#pragma warning( push )
#pragma warning( disable : 4191 )

mCFunctionTracer mCTrackingStream::s_Tracer( &TracerInit, reinterpret_cast< mCFunctionTracer::CallbackFuncPtr >( &HandleCall ) );

#pragma warning( pop )

mCTrackingStream * mCTrackingStream::s_pCurrent = 0;

GELPCChar const mCTrackingStream::s_arrTraced[ ETraced_Count ] = {
    "BYTE[]",
    "bCString",
    "GEI8",
    "GEU8",
    "GEI16",
    "GEU16",
    "GEI32",
    "GEU32",
    "GEInt",
    "GEUInt",
    "GEI64",
    "GEU64",
    "GEBool",
    "GEFloat",
    "GEDouble",
    "GEChar",
    "bCUnicodeString",
    "bCGuid",
    "bCDateTime",
    "bCVariant",
    "[Text line]",
    "bCAxisAngle",
    "bCBitField",
    "bCBox",
    "bCByteAlphaColor",
    "bCByteColor",
    "bCCapsule",
    "bCEulerAngles",
    "bCFloatColor",
    "bCFloatAlphaColor",
    "bCInfCylinder",
    "bCInfDoubleCylinder",
    "bCLine",
    "bCMatrix",
    "bCMatrix2",
    "bCMatrix3",
    "bCOrientedBox",
    "bCPlane",
    "bCPoint",
    "bCPropertyID",
    "bCQuaternion",
    "bCRange1",
    "bCRange2",
    "bCRange3",
    "bCRange4",
    "bCRay",
    "bCRect",
    "bCSphere",
    "bCSphericalRotation",
    "bCStretch",
    "bCTrackBitField",
    "bCTriangle",
    "bCUnitedRay",
    "bCVector",
    "bCVector2",
    "bCVector4"
};

#pragma auto_inline( off )

mCTrackingStream::mCTrackingStream() :
    m_StartPosition( -1 )
{
}

mCTrackingStream::~mCTrackingStream()
{
}

void mCTrackingStream::GenerateDataDocumentation( bCString a_strStructName, bCMemoryStream & a_Dest )
{
    enum { E_Trash = ( ETraced_Count + 1 ), E_Tail = ( ETraced_Count + 2 ) };

    bTObjArray< GEU8 > _DataMap;
    _DataMap.SetCount( ( GEInt )( GetSize() ) );
    GEU8 * DataMap = _DataMap.AccessArray();
    memset( DataMap, E_Trash, ( GEU32 )( _DataMap.GetCount() ) );

    GEU32 MaxTypeStringSize = strlen( s_arrTraced[ ETraced_Write_Buffer ] );
    for ( GEInt i = 0, ie = m_arrLogs.GetCount(); i != ie; ++i )
    {
        Log & CurrentLog = m_arrLogs[ i ];
        GEU8 * pData = DataMap + CurrentLog.u32Position;
        MaxTypeStringSize = max( MaxTypeStringSize, strlen( s_arrTraced[ CurrentLog.enuFunction ] ) );

        // Remove signatures in the current log's data range.
        for ( GEU8 * j = pData, * je = ( pData + CurrentLog.u32Size ); j != je; ++j )
        {
            if ( *j == E_Trash )
                continue;
            GEU8 * k = j;
            while ( *k == E_Tail )
                --k;
            *k = E_Tail;
            while ( *k == E_Tail )
                *( k++ ) = E_Trash;
        }
        
        // Write new signature.
        *pData = ( GEU8 )( CurrentLog.enuFunction );
        for ( GEU8 * j = ( pData + CurrentLog.u32Size - 1 ); j != pData; --j )
            *j = E_Tail;
    }
    for ( GEU8 * i = DataMap, * ie = ( DataMap + _DataMap.GetCount() ); i != ie; ++i )
    {
        if ( *i != E_Trash )
            continue;
        *( i++ ) = ETraced_Write_Buffer;
        while ( i != ie )
        {
            if ( *i != E_Trash )
                break;
            *( i++ ) = E_Tail;
        }
    }

    a_Dest.WriteLine( "struct " + a_strStructName );
    a_Dest.WriteLine( "{" );

    GEChar Buffer[ 200 ];
    GEChar Spaces[ 200 ];
    memset( Spaces, ' ', 200 );
    for ( GEU8 * i = DataMap, * ie = ( DataMap + _DataMap.GetCount() ); i != ie; ++i )
    {
        if ( *i == E_Tail )
            continue;
        GEInt Position = i - DataMap;
        GEU32 SpacesCount = ( MaxTypeStringSize - strlen( s_arrTraced[ *i ] ) );
        Spaces[ SpacesCount ] = 0;
        sprintf_s( Buffer, 200, "    %s%s _0x%.6x_%.6i;", s_arrTraced[ *i ], Spaces, Position, Position );
        Spaces[ SpacesCount ] = ' ';
        a_Dest.WriteLine( Buffer );
    }

    a_Dest.WriteLine( "};" );
}

GEU32 mCTrackingStream::Write( GELPCVoid a_pData, GEU32 a_u32Size )
{
    if ( m_StartPosition == -1 )
        m_StartPosition = ( GEInt )( GetPosition() );
    GEU32 Result = bCMemoryStream::Write( a_pData, a_u32Size );
    s_pCurrent = this;
    s_Tracer.Trace();
    return Result;
}

GEU32 mCTrackingStream::Write( bCString const & a_strText )
{
    GEU16 Length = ( GEU16 )( a_strText.GetLength() );
    GEChar * Buffer = new GEChar [ ( GEU32 )( Length ) + 2 ];
    *reinterpret_cast< GEU16 * >( Buffer ) = Length;
    memcpy_s( ( Buffer + 2 ), Length, a_strText.GetText(), Length );
    GEU32 Result = Write( Buffer, ( ( GEU32 )( Length ) + 2 ) );
    delete [] Buffer;
    return Result;
}

void mCTrackingStream::HandleCall( ETraced a_enuFunc )
{
    Log & NewLog = s_pCurrent->m_arrLogs.AddNew();
    NewLog.enuFunction = a_enuFunc;
    NewLog.u32Position = ( GEU32 )( s_pCurrent->m_StartPosition );
    NewLog.u32Size = ( ( GEU32 )( s_pCurrent->GetPosition() ) - ( GEU32 )( s_pCurrent->m_StartPosition ) );
    s_pCurrent->m_StartPosition = -1;
}

#pragma warning( push )
#pragma warning( disable : 4700 )

void mCTrackingStream::TracerInit( mCFunctionTracer * a_pTracer )
{
    bCString         strDummy;
    GEI8              i8Dummy;
    GEU8              u8Dummy;
    GEI16            i16Dummy;
    GEU16            u16Dummy;
    GEI32            i32Dummy;
    GEU32            u32Dummy;
    GEInt            intDummy;
    GEUInt          uintDummy;
    GEI64            i64Dummy;
    GEU64            u64Dummy;
    GEBool             bDummy;
    GEFloat            fDummy;
    GEDouble           dDummy;
    GEChar             cDummy;
    bCUnicodeString ustrDummy;
    bCGuid          guidDummy;
    bCDateTime      timeDummy;
    bCVariant    variantDummy;

    bCAxisAngle         angleDummy;
    bCBitField           bitfDummy;
    bCBox                 boxDummy;
    bCByteAlphaColor      bacDummy;
    bCByteColor            bcDummy;
    bCCapsule         capsuleDummy;
    bCEulerAngles         easDummy;
    bCFloatColor           fcDummy;
    bCFloatAlphaColor     facDummy;
    bCInfCylinder        infcDummy;
    bCInfDoubleCylinder infdcDummy;
    bCLine               lineDummy;
    bCMatrix              matDummy;
    bCMatrix2            mat2Dummy;
    bCMatrix3            mat3Dummy;
    bCOrientedBox        oboxDummy;
    bCPlane             planeDummy;
    bCPoint                ptDummy;
    bCPropertyID          pidDummy;
    bCQuaternion         quatDummy;
    bCRange1               r1Dummy;
    bCRange2               r2Dummy;
    bCRange3               r3Dummy;
    bCRange4               r4Dummy;
    bCRay                 rayDummy;
    bCRect               rectDummy;
    bCSphere              sphDummy;
    bCSphericalRotation  srotDummy;
    bCStretch         stretchDummy;
    bCTrackBitField       tbfDummy;
    bCTriangle            triDummy;
    bCUnitedRay          urayDummy;
    bCVector              vecDummy;
    bCVector2            vec2Dummy;
    bCVector4            vec4Dummy;

    mCTrackingStream DummyStream;

    a_pTracer->Trace();

    a_pTracer->AnnounceFunction( 2 );
    DummyStream.Write( a_pTracer, 1 );
    a_pTracer->RegisterAs( ETraced_Write_Buffer );

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( strDummy );
        a_pTracer->RegisterAs( ETraced_Write_bCString );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << strDummy;
        a_pTracer->RegisterAs( ETraced_Write_bCString );

        a_pTracer->AnnounceFunction( 2 );
        strDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_bCString );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( i8Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEI8 );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << i8Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEI8 );

        a_pTracer->AnnounceFunction( 2 );
        i8Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEI8 );
    }
    
    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( u8Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEU8 );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << u8Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEU8 );

        a_pTracer->AnnounceFunction( 2 );
        u8Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEU8 );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( i16Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEI16 );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << i16Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEI16 );

        a_pTracer->AnnounceFunction( 2 );
        i16Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEI16 );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( u16Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEU16 );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << u16Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEU16 );

        a_pTracer->AnnounceFunction( 2 );
        u16Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEU16 );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( i32Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEI32 );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << i32Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEI32 );

        a_pTracer->AnnounceFunction( 2 );
        i32Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEI32 );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( u32Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEU32 );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << u32Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEU32 );

        a_pTracer->AnnounceFunction( 2 );
        u32Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEU32 );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( intDummy );
        a_pTracer->RegisterAs( ETraced_Write_GEInt );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << intDummy;
        a_pTracer->RegisterAs( ETraced_Write_GEInt );

        a_pTracer->AnnounceFunction( 2 );
        intDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEInt );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( uintDummy );
        a_pTracer->RegisterAs( ETraced_Write_GEUInt );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << uintDummy;
        a_pTracer->RegisterAs( ETraced_Write_GEUInt );

        a_pTracer->AnnounceFunction( 2 );
        uintDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEUInt );
    }

    {
        a_pTracer->AnnounceFunction( 2 );
        DummyStream.Write( i64Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEI64 );

        a_pTracer->AnnounceFunction( 2 );
        DummyStream << i64Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEI64 );

        a_pTracer->AnnounceFunction( 3 );
        i64Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEI64 );
    }

    {
        a_pTracer->AnnounceFunction( 2 );
        DummyStream.Write( u64Dummy );
        a_pTracer->RegisterAs( ETraced_Write_GEU64 );

        a_pTracer->AnnounceFunction( 2 );
        DummyStream << u64Dummy;
        a_pTracer->RegisterAs( ETraced_Write_GEU64 );

        a_pTracer->AnnounceFunction( 3 );
        u64Dummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEU64 );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( bDummy );
        a_pTracer->RegisterAs( ETraced_Write_GEBool );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << bDummy;
        a_pTracer->RegisterAs( ETraced_Write_GEBool );

        a_pTracer->AnnounceFunction( 2 );
        bDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEBool );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( fDummy );
        a_pTracer->RegisterAs( ETraced_Write_GEFloat );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << fDummy;
        a_pTracer->RegisterAs( ETraced_Write_GEFloat );

        a_pTracer->AnnounceFunction( 2 );
        fDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEFloat );
    }

    {
        a_pTracer->AnnounceFunction( 2 );
        DummyStream.Write( dDummy );
        a_pTracer->RegisterAs( ETraced_Write_GEDouble );

        a_pTracer->AnnounceFunction( 2 );
        DummyStream << dDummy;
        a_pTracer->RegisterAs( ETraced_Write_GEDouble );

        a_pTracer->AnnounceFunction( 3 );
        dDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEDouble );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( cDummy );
        a_pTracer->RegisterAs( ETraced_Write_GEChar );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << cDummy;
        a_pTracer->RegisterAs( ETraced_Write_GEChar );

        a_pTracer->AnnounceFunction( 2 );
        cDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_GEChar );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( ustrDummy );
        a_pTracer->RegisterAs( ETraced_Write_bCUnicodeString );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << ustrDummy;
        a_pTracer->RegisterAs( ETraced_Write_bCUnicodeString );

        a_pTracer->AnnounceFunction( 2 );
        ustrDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_bCUnicodeString );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( guidDummy );
        a_pTracer->RegisterAs( ETraced_Write_bCGuid );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << guidDummy;
        a_pTracer->RegisterAs( ETraced_Write_bCGuid );

        a_pTracer->AnnounceFunction( 2 );
        guidDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_bCGuid );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( timeDummy );
        a_pTracer->RegisterAs( ETraced_Write_bCDateTime );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << timeDummy;
        a_pTracer->RegisterAs( ETraced_Write_bCDateTime );

        a_pTracer->AnnounceFunction( 2 );
        timeDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_bCDateTime );
    }

    {
        a_pTracer->AnnounceFunction( 1 );
        DummyStream.Write( variantDummy );
        a_pTracer->RegisterAs( ETraced_Write_bCVariant );

        a_pTracer->AnnounceFunction( 1 );
        DummyStream << variantDummy;
        a_pTracer->RegisterAs( ETraced_Write_bCVariant );

        a_pTracer->AnnounceFunction( 2 );
        variantDummy >> DummyStream;
        a_pTracer->RegisterAs( ETraced_Write_bCVariant );
    }

    a_pTracer->AnnounceFunction( 1 );
    DummyStream.WriteLine( strDummy );
    a_pTracer->RegisterAs( ETraced_Write_Line );

    // - - - - - - - - - - - -

    a_pTracer->AnnounceFunction( 1 );
    angleDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCAxisAngle );

    a_pTracer->AnnounceFunction( 1 );
    bitfDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCBitField );

    a_pTracer->AnnounceFunction( 1 );
    boxDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCBox );

    a_pTracer->AnnounceFunction( 1 );
    bacDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCByteAlphaColor );

    a_pTracer->AnnounceFunction( 1 );
    bcDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCByteColor );

    a_pTracer->AnnounceFunction( 1 );
    capsuleDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCCapsule );

    a_pTracer->AnnounceFunction( 1 );
    easDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCEulerAngles );

    a_pTracer->AnnounceFunction( 1 );
    fcDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCFloatColor );

    a_pTracer->AnnounceFunction( 1 );
    facDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCFloatAlphaColor );

    a_pTracer->AnnounceFunction( 1 );
    infcDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCInfCylinder );

    a_pTracer->AnnounceFunction( 1 );
    infdcDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCInfDoubleCylinder );

    a_pTracer->AnnounceFunction( 1 );
    lineDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCLine );

    a_pTracer->AnnounceFunction( 1 );
    matDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCMatrix );

    a_pTracer->AnnounceFunction( 1 );
    mat2Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCMatrix2 );

    a_pTracer->AnnounceFunction( 1 );
    mat3Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCMatrix3 );

    a_pTracer->AnnounceFunction( 1 );
    oboxDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCOrientedBox );

    a_pTracer->AnnounceFunction( 1 );
    planeDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCPlane );

    a_pTracer->AnnounceFunction( 1 );
    ptDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCPoint );

    a_pTracer->AnnounceFunction( 1 );
    pidDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCPropertyID );

    a_pTracer->AnnounceFunction( 1 );
    quatDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCQuaternion );

    a_pTracer->AnnounceFunction( 1 );
    r1Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCRange1 );

    a_pTracer->AnnounceFunction( 1 );
    r2Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCRange2 );

    a_pTracer->AnnounceFunction( 1 );
    r3Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCRange3 );

    a_pTracer->AnnounceFunction( 1 );
    r4Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCRange4 );

    a_pTracer->AnnounceFunction( 1 );
    rayDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCRay );

    a_pTracer->AnnounceFunction( 1 );
    rectDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCRect );

    a_pTracer->AnnounceFunction( 1 );
    sphDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCSphere );

    a_pTracer->AnnounceFunction( 1 );
    srotDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCSphericalRotation );

    a_pTracer->AnnounceFunction( 1 );
    stretchDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCStretch );

    a_pTracer->AnnounceFunction( 1 );
    tbfDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCTrackBitField );

    a_pTracer->AnnounceFunction( 1 );
    triDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCTriangle );

    a_pTracer->AnnounceFunction( 1 );
    urayDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCUnitedRay );

    a_pTracer->AnnounceFunction( 1 );
    vecDummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCVector );

    a_pTracer->AnnounceFunction( 1 );
    vec2Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCVector2 );

    a_pTracer->AnnounceFunction( 1 );
    vec4Dummy >> DummyStream;
    a_pTracer->RegisterAs( ETraced_Write_bCVector4 );
}

#pragma warning( pop )

#pragma auto_inline( on )
