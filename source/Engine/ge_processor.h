#ifndef GE_PROCESSOR_H_INCLUDED
#define GE_PROCESSOR_H_INCLUDED

class GE_DLLIMPORT eCProcessor
{
private:
    eCProcessible * m_ppLists[ 0x100 ];      // 0000
    GEU32           m_pu32Lengths[ 0x100 ];  // 0400
    GEU32           m_u32AppStateFlags;      // 0800
    // sizeof(eCProcessor)                      0804
private:
    void Process( void );
public:
    static eCProcessor & GE_STDCALL GetInstance( void );
public:
    eCProcessible * FindHead( GEInt ) const;
    void            Process( GEU32 );
    void            Register( eCProcessible * );
    void            Unregister( eCProcessible * );
private:
    eCProcessor( void );
   ~eCProcessor( void );
};

#endif
