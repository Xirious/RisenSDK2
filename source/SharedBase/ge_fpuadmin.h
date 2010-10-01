#ifndef GE_FPUADMIN_H_INCLUDED
#define GE_FPUADMIN_H_INCLUDED

class GE_DLLIMPORT bCFPUAdmin
{
private:
    GEU32 m_u32SavedControlWord;
    GEU32 m_u32DefaultControlWord;
private:
    void ComputeDefaultControlWord( void );
protected:
    void Destroy( void );
    void Invalidate( void );
public:
    static bCFPUAdmin & GE_STDCALL GetInstance( void );
public:
    void  Create( void );
    void  EnableDenormalFloatExceptions( GEBool );
    void  EnableInvalidFloatExceptions( GEBool );
    void  EnableOverflowExceptions( GEBool );
    void  EnableUnderflowExceptions( GEBool );
    void  EnableZeroDevideExceptions( GEBool );
    GEU32 GetCurrentControlWord( void );
    void  PrintStatus( void );
    void  RestoreDefaultControlWord( void );
    void  RestoreSavedControlWord( void );
    void  SaveCurrentControlWord( void );
    void  SetControlWord( GEU32 );
    void  SetHighPrecision( void );
    void  SetLowPrecision( void );
    void  SetMidPrecision( void );
protected:
    bCFPUAdmin const & operator = ( bCFPUAdmin const & );
protected:
    bCFPUAdmin( bCFPUAdmin const & );
    bCFPUAdmin( void );
public:
   ~bCFPUAdmin( void );
};

#endif
