#ifndef GE_STATISTICVIEW_H_INCLUDED
#define GE_STATISTICVIEW_H_INCLUDED

class GE_DLLIMPORT eCStatisticView
{
public: virtual void SetStatistic( eCStatistic * );  // [0000].0000
public: virtual void Create( eCGuiWindow2 * ) = 0;   // [0000].0004
public: virtual void Update( void )           = 0;   // [0000].0008
public: virtual     ~eCStatisticView( void );        // [0000].000C
protected:
    eCStatistic * m_pStatistic;
protected:
    void Destroy( void );
    void Invalidate( void );
public:
    eCStatistic * GetStatistic( void ) const;
public:
    eCStatisticView & operator = ( eCStatisticView const & );
public:
    eCStatisticView( eCStatisticView const & );
    eCStatisticView( void );
};
GE_ASSERT_SIZEOF( eCStatisticView, 0x0008 )

#endif
