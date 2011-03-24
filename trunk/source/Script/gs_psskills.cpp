#include "../Script.h"

template<> PSSkills &       Entity::PropertySet( void )       { return *reinterpret_cast< PSSkills *       >( this ); }
template<> PSSkills const & Entity::PropertySet( void ) const { return *reinterpret_cast< PSSkills const * >( this ); }
