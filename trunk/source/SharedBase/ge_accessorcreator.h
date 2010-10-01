#ifndef GE_ACCESSORCREATOR_H_INCLUDED
#define GE_ACCESSORCREATOR_H_INCLUDED

class GE_DLLIMPORT bCAccessorCreator
{
private:
    bCObjectBase * m_pInstance;
public:
    bCAccessorCreator    Clone( void ) const;
    void                 CopyFrom( bCAccessorCreator const & );
    void                 CopyTo( bCAccessorCreator & ) const;
    bCObjectBase *       GetPropertyObject( void );
    bCObjectBase const * GetPropertyObject( void ) const;
    GEBool               HasBaseClass( void ) const;
    void                 Invalidate( void );
    GEBool               IsValid( void ) const;
    bCAccessorCreator    QueryBaseClass( void );
    void                 SetInstance( bCObjectBase * );
public:
                              operator bCObjectBase *       ( void );
                              operator bCObjectBase const * ( void ) const;
    bCObjectBase *            operator ->                   ( void );
    bCObjectBase const *      operator ->                   ( void ) const;
    bCAccessorCreator const & operator =                    ( bCAccessorCreator const & );
protected:
    bCAccessorCreator( void );
public:
    bCAccessorCreator( bCString const & );
    bCAccessorCreator( bCObjectBase * );
    bCAccessorCreator( bCAccessorCreator const & );
    bCAccessorCreator( bCPropertyID const &, bCString const * );
   ~bCAccessorCreator( void );
};

#endif
