#ifndef GE_PROPERTYCONVERTERPTR_H_INCLUDED
#define GE_PROPERTYCONVERTERPTR_H_INCLUDED

class GE_DLLIMPORT bCPropertyConverterPtr
{
private:
    bCPropertyConverter * m_pInstance;  // 0000
    // sizeof(bCPropertyConverterPtr)      0004
protected:
    void CopyFrom( bCPropertyConverterPtr const & );
    void Create( void );
    void Destroy( void );
    void Invalidate( void );
public:
    bCPropertyConverter * GetInstance( void ) const;
    GEBool                IsValid( void ) const;
    void                  SetInstance( bCPropertyConverter * );
public:
                                   operator bCPropertyConverter *       ( void );
                                   operator bCPropertyConverter const * ( void ) const;
    bCPropertyConverterPtr const & operator =                           ( bCPropertyConverter const * );
	bCPropertyConverter *          operator ->                          ( void );
    bCPropertyConverter const *    operator ->                          ( void ) const;
    bCPropertyConverterPtr const & operator =                           ( bCPropertyConverterPtr const & );
public:
    bCPropertyConverterPtr( bCPropertyConverterPtr const & );
    bCPropertyConverterPtr( void );
   ~bCPropertyConverterPtr( void );
};

#endif
