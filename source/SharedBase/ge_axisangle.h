#ifndef GE_AXISANGLE_H_INCLUDED
#define GE_AXISANGLE_H_INCLUDED

class GE_DLLIMPORT bCAxisAngle
{
private:
    bCVector m_vecAxis;
    GEFloat  m_fAngle;
public:
    GEFloat &        AccessAngle( void );
    bCVector &       AccessAxis( void );
    void             Clear( void );
    GEFloat          GetAngle( void ) const;
    void             GetAngle( GEFloat & ) const;
    bCVector const & GetAxis( void ) const;
    void             GetAxis( bCVector & ) const;
    bCEulerAngles    GetEulerAngles( void ) const;
    bCQuaternion     GetQuaternion( void ) const;
    GEBool           IsEqual( bCAxisAngle const & ) const;
    void             SetAngle( GEFloat );
    void             SetAxis( bCVector const & );
    void             SetAxisAngle( bCAxisAngle const & );
    void             SetAxisAngle( bCEulerAngles const & );
    void             SetAxisAngle( bCQuaternion const & );
    void             SetAxisAngle( bCVector const &, GEFloat );
public:
    bCAxisAngle & operator =  ( bCEulerAngles const & );
    bCAxisAngle & operator =  ( bCQuaternion const & );
    GEBool        operator == ( bCAxisAngle const & ) const;
    GEBool        operator != ( bCAxisAngle const & ) const;
    bCIStream &   operator << ( bCIStream & );
    bCOStream &   operator >> ( bCOStream & ) const;
    bCAxisAngle & operator =  ( bCAxisAngle const & );
public:
    explicit bCAxisAngle( bCEulerAngles const & );
    explicit bCAxisAngle( bCQuaternion const & );
             bCAxisAngle( bCVector const &, GEFloat );
             bCAxisAngle( bCAxisAngle const & );
             bCAxisAngle( void );
            ~bCAxisAngle( void );
};

#endif
