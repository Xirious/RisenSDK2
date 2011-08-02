#ifndef GM_TRACKINGSTREAM_H_INCLUDED
#define GM_TRACKINGSTREAM_H_INCLUDED

#include "gm_functiontracer.h"

class mCTrackingStream :
    public bCMemoryStream
{
protected:
    enum ETraced
    {
        ETraced_Write_Buffer,
        ETraced_Write_bCString,
        ETraced_Write_GEI8,
        ETraced_Write_GEU8,
        ETraced_Write_GEI16,
        ETraced_Write_GEU16,
        ETraced_Write_GEI32,
        ETraced_Write_GEU32,
        ETraced_Write_GEInt,
        ETraced_Write_GEUInt,
        ETraced_Write_GEI64,
        ETraced_Write_GEU64,
        ETraced_Write_GEBool,
        ETraced_Write_GEFloat,
        ETraced_Write_GEDouble,
        ETraced_Write_GEChar,
        ETraced_Write_bCUnicodeString,
        ETraced_Write_bCGuid,
        ETraced_Write_bCDateTime,
        ETraced_Write_bCVariant,
        ETraced_Write_Line,
        ETraced_Write_bCAxisAngle,
        ETraced_Write_bCBitField,
        ETraced_Write_bCBox,
        ETraced_Write_bCByteAlphaColor,
        ETraced_Write_bCByteColor,
        ETraced_Write_bCCapsule,
        ETraced_Write_bCEulerAngles,
        ETraced_Write_bCFloatColor,
        ETraced_Write_bCFloatAlphaColor,
        ETraced_Write_bCInfCylinder,
        ETraced_Write_bCInfDoubleCylinder,
        ETraced_Write_bCLine,
        ETraced_Write_bCMatrix,
        ETraced_Write_bCMatrix2,
        ETraced_Write_bCMatrix3,
        ETraced_Write_bCOrientedBox,
        ETraced_Write_bCPlane,
        ETraced_Write_bCPoint,
        ETraced_Write_bCPropertyID,
        ETraced_Write_bCQuaternion,
        ETraced_Write_bCRange1,
        ETraced_Write_bCRange2,
        ETraced_Write_bCRange3,
        ETraced_Write_bCRange4,
        ETraced_Write_bCRay,
        ETraced_Write_bCRect,
        ETraced_Write_bCSphere,
        ETraced_Write_bCSphericalRotation,
        ETraced_Write_bCStretch,
        ETraced_Write_bCTrackBitField,
        ETraced_Write_bCTriangle,
        ETraced_Write_bCUnitedRay,
        ETraced_Write_bCVector,
        ETraced_Write_bCVector2,
        ETraced_Write_bCVector4,
        ETraced_Count,
        ETraced_ForceDWORD = GE_FORCE_DWORD
    };
protected:
    struct Log
    {
        ETraced enuFunction;
        GEU32   u32Position;
        GEU32   u32Size;
    };
public: using bCOStream::Write;
public: virtual GEU32    Write( GELPCVoid a_pData, GEU32 a_u32Size );
public: virtual GEU32    Write( bCString const & a_strText );
protected:
    static mCFunctionTracer   s_Tracer;
    static mCTrackingStream * s_pCurrent;
    static GELPCChar const    s_arrTraced[ ETraced_Count ];
protected:
    bTObjArray< Log > m_arrLogs;
    GEInt             m_StartPosition;
protected:
    static void TracerInit( mCFunctionTracer * a_pTracer );
    static void HandleCall( ETraced a_enuFunc );
public:
    void GenerateDataDocumentation( bCString a_strStructName, bCMemoryStream & a_Dest );
public:
    mCTrackingStream();
   ~mCTrackingStream();
};

#endif