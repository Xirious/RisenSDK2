#ifndef GE_VALIDATEMEMORY_H_INCLUDED
#define GE_VALIDATEMEMORY_H_INCLUDED

class GE_DLLIMPORT bCValidateMemory
{
private:
    GEBool m_bBreakOnError;
    GEBool m_bTraceOnError;
    GEBool m_bWarningMessageOnError;
    GEBool m_bFatalErrorOnError;
public:
    static bCValidateMemory & GE_STDCALL GetInstance( void );
public:
    GEBool GetBreakOnError( void ) const;
    GEBool GetFatalErrorOnError( void ) const;
    GEBool GetTraceOnError( void ) const;
    GEBool GetWarningMessageOnError( void ) const;
    void   SetBreakOnError( GEBool );
    void   SetFatalErrorOnError( GEBool );
    void   SetTraceOnError( GEBool );
    void   SetWarningMessageOnError( GEBool );
    void   Validate( void );
public:
    bCValidateMemory & operator = ( bCValidateMemory const & );
protected:
    void Invalidate( void );
protected:
    bCValidateMemory( GEBool, GEBool, GEBool, GEBool );
    bCValidateMemory( void );
   ~bCValidateMemory( void );
};

#endif
