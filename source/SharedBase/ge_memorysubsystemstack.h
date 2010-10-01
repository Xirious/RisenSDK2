#ifndef GE_MEMORYSUBSYSTEMSTACK_H_INCLUDED
#define GE_MEMORYSUBSYSTEMSTACK_H_INCLUDED

enum bEMemorySubSystem
{
    bEMemorySubSystem_None,
    bEMemorySubSystem_Global,
    bEMemorySubSystem_PropertySystem,
    bEMemorySubSystem_FileSystem,
    bEMemorySubSystem_Material,
    bEMemorySubSystem_Animation,
    bEMemorySubSystem_Mesh,
    bEMemorySubSystem_Audio,
    bEMemorySubSystem_Physics,
    bEMemorySubSystem_Rendering,
    bEMemorySubSystem_Scene,
    bEMemorySubSystem_ResourceCache,
    bEMemorySubSystem_Localization,
    bEMemorySubSystem_Navigation,
    bEMemorySubSystem_GUI,
    bEMemorySubSystem_All,
    bEMemorySubSystem_Count,
    bEMemorySubSystem_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCMemorySubSystemStack
{
private:
    bEMemorySubSystem m_arrStack[ 256 ];
    GEU8              m_u8Index;
                      GE_PADDING( 3 )
public:
    static GELPChar GE_STDCALL GetMemorySubSystemName( bEMemorySubSystem );
public:
    bEMemorySubSystem GetActualMemorySubSystem( void );
    GEBool            IsSubSystemActual( bEMemorySubSystem );
    void              PopMemorySubSystem( void );
    void              PushMemorySubSystem( bEMemorySubSystem );
public:
    bCMemorySubSystemStack & operator = ( bCMemorySubSystemStack const & );
public:
    bCMemorySubSystemStack( void );
   ~bCMemorySubSystemStack( void );
};

#endif
