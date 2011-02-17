#ifndef GE_ARRAYSORTBASE_H_INCLUDED
#define GE_ARRAYSORTBASE_H_INCLUDED

typedef GEInt (GE_CCALL * GEFCompare)( GELPCVoid, GELPCVoid );

GE_DLLIMPORT void GE_CCALL g_ArrayInsertionSort( GELPVoid, GEUInt, GEUInt, GEFCompare, GEBool );
GE_DLLIMPORT GEInt GE_CCALL g_ArraySortDefaultCompare( GELPCVoid, GELPCVoid );

#endif
