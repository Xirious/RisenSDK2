#pragma warning( push )
#pragma warning( disable : 4640 )  // construction of local static object is not thread-safe

template< typename T >
T * g_GetModule( void )
{
    if( GETrue == eCApplication::IsInitialised() )
    {
        static T * s_pModule = dynamic_cast< T * >( eCModuleAdmin::GetInstance().FindModule( bTClassName< T >::GetName() ) );
		return s_pModule;
	}
    return 0;
}

#pragma warning( pop )
