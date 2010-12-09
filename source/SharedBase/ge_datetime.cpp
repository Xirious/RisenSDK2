#include "../SharedBase.h"

GEU64 tagUI_FILETIME::GetDateTime( void ) const
{
    return m_u64DateTime * 20000000 / 20000000;
}

