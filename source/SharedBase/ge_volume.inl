template< typename T >
bCVector bTVolume< T >::GetCenter( void ) const
{
    bCVector vecCenter;
    this->GetCenter( vecCenter );
    return vecCenter;
};

template< typename T >
bCVolume * bTVolume< T >::Clone( void ) const
{
    bTVolume< T > * pVolume = GE_NEW( bTVolume< T > );
    if( pVolume )
        pVolume->m_Volume = this->m_Volume;
    return pVolume;
}

template< typename T >
void bTVolume< T >::Transform( bCMatrix const & a_matTransform )
{
    this->Transform( a_matTransform );
}

template< typename T >
void bTVolume< T >::Translate( bCVector const & a_vecOffset )
{
    this->Translate( a_vecOffset );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCPlane const & a_Plane ) const
{
    return this->m_Volume.Intersects( a_Plane );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCUnitedRay const & a_UnitedRay, GEFloat & a_fDistance ) const
{
    return this->m_Volume.Intersects( a_UnitedRay, a_fDistance );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCUnitedRay const & a_UnitedRay ) const
{
    return this->m_Volume.Intersects( a_UnitedRay, this->m_Volume.m_fDummy );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCTriangle const & a_Triangle ) const
{
    return this->m_Volume.Intersects( a_Triangle );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCBox const & a_Box ) const
{
    return this->m_Volume.Intersects( a_Box );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCFrustum const & a_Frustum ) const
{
    return this->m_Volume.Intersects( a_Frustum );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCSphere const & a_Sphere ) const
{
    return this->m_Volume.Intersects( a_Sphere );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCVector const & a_Point ) const
{
    return this->m_Volume.Intersects( a_Point );
}

template< typename T >
GEBool bTVolume< T >::Intersects( bCVolume const & a_Volume ) const
{
    return a_Volume.Intersects( this->m_Volume );
}

template< typename T >
bTVolume< T >::~bTVolume( void )
{
}

template< typename T >
bTVolume< T > & bTVolume< T >::operator = ( bTVolume< T > const & a_Source )
{
    this->m_Volume = a_Source.m_Volume;
    return *this;
}

template< typename T >
bTVolume< T >::bTVolume( T const & a_Volume )
{
    this->m_Volume = a_Volume;
}

template< typename T >
bTVolume< T >::bTVolume( bTVolume< T > const & a_Source )
{
    this->m_Volume = a_Source.m_Volume;
}

template< typename T >
bTVolume< T >::bTVolume( void )
{
}
