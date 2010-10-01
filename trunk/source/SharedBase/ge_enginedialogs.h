#ifndef GE_ENGINEDIALOGS_H_INCLUDED
#define GE_ENGINEDIALOGS_H_INCLUDED

class GE_DLLIMPORT bCEngineDialogs
{
public:
    enum bEGE3DialogsLogMessageType
    {
        bEGE3DialogsLogMessageType_Error = 1,
        bEGE3DialogsLogMessageType_ErrorHistory,
        bEGE3DialogsLogMessageType_ErrorMemory,
        bEGE3DialogsLogMessageType_ErrorCallstack,
        bEGE3DialogsLogMessageType_FileNotUnique,
        bEGE3DialogsLogMessageType_ForceDWORD = GE_FORCE_DWORD
    };
public:
    class GE_DLLIMPORT bCDialogHandle
    {
    private:
        GELPVoid             m_pModule;
        GEU16                m_u16ReferenceCount;
                             GE_PADDING( 2 )
        GEBool (GE_STDCALL * m_funcCreateErrorDialog)( GEBool );                                  // dialogs._CreateErrorDialog@4
        GEBool (GE_STDCALL * m_funcDestroyErrorDialog)( void );                                   // dialogs._DestroyErrorDialog@0
        GEBool (GE_STDCALL * m_funcShowModalErrorDialog)( void );                                 // dialogs._ShowModalErrorDialog@0
        GEBool (GE_STDCALL * m_funcAddText)( bEGE3DialogsLogMessageType, GELPCChar );             // dialogs._AddText@8
        void   (GE_STDCALL * m_funcGetErrorDialogState)( GEBool *, GEBool * );                    // dialogs._GetErrorDialogState@8
        GEBool (GE_STDCALL * m_funcCreateMemoryDialog)( void );                                   // dialogs._CreateMemoryDialog@0
        GEBool (GE_STDCALL * m_funcDestroyMemoryDialog)( void );                                  // dialogs._DestroyMemoryDialog@0
        GEBool (GE_STDCALL * m_funcShowModalMemoryDialog)( void );                                // dialogs._ShowModalMemoryDialog@0
        void   (GE_STDCALL * m_funcAddItemToMemoryOverview)( bSAllocationItem const *, GEBool );  // dialogs._AddItemToMemoryOverview@8
        GEBool (GE_STDCALL * m_funcCreateFileNotUniqueDialog)( void );                            // dialogs._CreateFileNotUniqueDialog@0
        GEBool (GE_STDCALL * m_funcDestroyFileNotUniqueDialog)( void );                           // dialogs._DestroyFileNotUniqueDialog@0
        GEBool (GE_STDCALL * m_funcShowModalFileNotUniqueDialog)( void );                         // dialogs._ShowModalFileNotUniqueDialog@0
    public:
        void   AddItemToMemoryOverview( bSAllocationItem const *, GEBool );
        GEU16  AddReference( void );
        GEBool AddText( bEGE3DialogsLogMessageType, GELPCChar );
        GEBool CreateErrorDialog( GEBool );
        GEBool CreateFileNotUniqueDialog( void );
        GEBool CreateMemoryDialog( void );
        GEBool DestroyErrorDialog( void );
        GEBool DestroyFileNotUniqueDialog( void );
        GEBool DestroyMemoryDialog( void );
        void   GetErrorDialogState( GEBool &, GEBool & );
        GEU16  GetReferenceCount( void ) const;
        GEU16  ReleaseReference( void );
        GEBool ShowModalErrorDialog( void );
        GEBool ShowModalFileNotUniqueDialog( void );
        GEBool ShowModalMemoryDialog( void );
    public:
        bCDialogHandle & operator = ( bCDialogHandle const & );
    protected:
        void Invalidate( void );
    protected:
        bCDialogHandle( void );
       ~bCDialogHandle( void );
    };
private:
    GEBool m_bDialogLibLoaded;
public:
    bCDialogHandle & GetDialogHandle( void ) const;
    GEBool           IsLoaded( void ) const;
    GEBool           LoadGE3DialogLib( GEBool );
    void             UnloadGE3DialogLib( void );
public:
    bCEngineDialogs & operator = ( bCEngineDialogs const & );
public:
    bCEngineDialogs( void );
   ~bCEngineDialogs( void );
};

#endif
