#ifndef M_EDITORINTERFACE_H_INCLUDED
#define M_EDITORINTERFACE_H_INCLUDED

#include "m_placementadmin.h"
#include "../input/m_inputadmin.h"

class mCEditorInterface
{
public:
    void   Enable( void );
    void   Disable( void );
    GEBool IsEnabled( void ) const;
    void   OnProcess( void );
private:
    mCEditorInterface( mCEditorInterface const & );
    mCEditorInterface( void );
   ~mCEditorInterface( void );
private:
    mCEditorInterface & operator = ( mCEditorInterface const & );
private:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    public:
        CProcessor( mCEditorInterface * a_pEditorInterface );
    protected:
        mCEditorInterface * m_pEditorInterface;
    };
private:
    static void GE_STDCALL OnKeyEvent( eEScanCode a_enuScanCode, GEBool a_bState );
private:
    GEBool AlignAnalogInput( bCVector & a_vecInput ) const;
    void   HandleAnalogInput( void );
    void   PickTransformAxes( void );
private:
    static mCEditorInterface s_Instance;
private:
    CProcessor                  m_Processor;
    mCPlacementAdmin &          m_PlacementAdmin;
    mCInputAdmin::CKeyHandle *  m_arrKeyHandles[ 14 ];
    mCInputAdmin::CAnalogHandle m_AnalogHandle;
    GEBool                      m_bEnabled;
    GEBool                      m_bCtrl;
    GEBool                      m_bAlt;
                                GE_PADDING( 1 )
};

#endif