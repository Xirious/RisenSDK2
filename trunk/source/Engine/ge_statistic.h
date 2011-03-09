#ifndef GE_STATISTIC_H_INCLUDED
#define GE_STATISTIC_H_INCLUDED

class eCStatisticView;  // forward

class GE_DLLIMPORT eCStatistic
{
public: virtual eCStatisticView * CreateView( eCGuiWindow2 * ) = 0;
public: virtual                  ~eCStatistic( void );
protected:
    bCString      m_strTitle;
    eCStatistic * m_pParent;
    eCStatistic * m_pFirstChild;
    eCStatistic * m_pPrevSibling;
    eCStatistic * m_pNextSibling;
protected:
    void AddChild( eCStatistic * );
    void DeleteChildren( void );
    void Invalidate( void );
    void RemoveChild( eCStatistic * );
    void RemoveFromParent( void );
public:
    void             Create( void );
    void             Destroy( void );
    eCStatistic *    GetFirstChild( void ) const;
    eCStatistic *    GetNextSibling( void ) const;
    eCStatistic *    GetParent( void ) const;
    eCStatistic *    GetPrevSibling( void ) const;
    bCString const & GetTitle( void ) const;
    void             SetTitle( bCString const & );
public:
    eCStatistic & operator = ( eCStatistic const & );
public:
    eCStatistic( eCStatistic const & );
    eCStatistic( bCString const & );
};
GE_ASSERT_SIZEOF( eCStatistic, 0x0018 )

#endif
