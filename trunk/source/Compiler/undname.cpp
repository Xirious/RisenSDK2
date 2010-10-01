#include "undname.h"
#include <cstdlib>

extern "C" _CRTIMP char * __cdecl __unDName(
    char * outputString,
    char const * name,
    int maxStringLength,
    void * (__cdecl * pOpNew)( size_t ),
    void (__cdecl * pOpDelete)( void * ),
    unsigned short disableFlags
    );
extern "C" _CRTIMP char * __cdecl __unDNameEx(
    char * outputString,
    char const * name,
    int maxStringLength,
    void * (__cdecl * pAlloc)( size_t ),
    void (__cdecl * pFree)( void * ),
    char * (__cdecl * pGetParameter)( long ),
    unsigned long disableFlags
    );

char * __cdecl GetParameter( long )
{
    return NULL;
}

std::string UndecorateName( std::string const & name, UndecorateFlags flags )
{
    class Undecorate {
    private:
        char * buffer;
    public:
        Undecorate( std::string const & name, UndecorateFlags flags ) : buffer( NULL )
        {
            if( buffer = __unDNameEx( NULL, name.c_str(), 0, malloc, free, GetParameter, flags ), buffer )
            {
                size_t len = strlen( buffer );
                while( len && ' ' == buffer[ --len ] )
                    buffer[ len ] = '\0';
            }
        }
        operator std::string( void )
        {
            return std::string( buffer );
        }
        ~Undecorate( void )
        {
            free( buffer );
        }
    };
    return Undecorate( name, flags );
}

