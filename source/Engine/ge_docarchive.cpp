#include "../Engine.h"

eSDocArchiveConfig::eSDocArchiveConfig( GELPCChar a_pcBinaryPath, GELPCChar a_pcBinaryName, GELPCChar a_pcBinaryExt, GELPCChar a_pcRawPath ) :
    m_strBinaryPath( a_pcBinaryPath ), m_strBinaryName( a_pcBinaryName ), m_strBinaryExt( a_pcBinaryExt ), m_strRawPath( a_pcRawPath )
{
}

eSDocArchiveConfig::~eSDocArchiveConfig( void )
{
}

