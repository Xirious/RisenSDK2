#ifndef GE_PORTAL_H_INCLUDED
#define GE_PORTAL_H_INCLUDED

class eCPortalCell_PS;  // forward

class GE_DLLIMPORT eCPortal
{
protected:
    eCPortalBSP::eSPortalRect m_PortalRect;    // 0000
    bCBox                     m_boxPortalBox;  // 003C
    eCPortalCell_PS *         m_pCell;         // 0054
    eCEntityProxy             m_CellProxy;     // 0058
    GEFloat                   m_fArea;         // 0060
public:
    void                              Clear( void );
    eCPortalCell_PS *                 GetCell( void ) const;
    eCEntityProxy const &             GetCellProxy( void ) const;
    bCBox const &                     GetPortalBox( void ) const;
    eCPortalBSP::eSPortalRect &       GetPortalRect( void );
    eCPortalBSP::eSPortalRect const & GetPortalRect( void ) const;
    GEFloat                           GetArea( void ) const;
    void                              Read( bCIStream & );
    void                              SetArea( GEFloat );
    void                              SetCell( eCPortalCell_PS * );
    void                              Write( bCOStream & );
public:
    eCPortal &  operator =  ( eCPortal const & );
    bCIStream & operator << ( bCIStream & );
    bCOStream & operator >> ( bCOStream & );
public:
    eCPortal( void );
    eCPortal( eCPortal const & );
public:
    ~eCPortal( void );
};
GE_ASSERT_SIZEOF( eCPortal, 0x0064 )

#endif