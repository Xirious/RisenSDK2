#include "../SharedBase.h"

void bCPropertyContainer::Invalidate( void )
{
}

bEResult bCPropertyContainer::Read( bCIStream & )
{
    return bEResult_Ok;
};

bEResult bCPropertyContainer::Write( bCOStream & ) const
{
    return bEResult_Ok;
}

bCPropertyContainer::bCPropertyContainer( void )
{
    this->Invalidate();
}

bCPropertyContainer::~bCPropertyContainer( void )
{
}

