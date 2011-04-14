#ifndef GE_CONSOLE2_H_INCLUDED
#define GE_CONSOLE2_H_INCLUDED

class GE_DLLIMPORT eCConsole2
{
public: virtual ~eCConsole2( void );
protected:
    eCGuiFrame2 *          m_pConsoleFrame;
    eCConsoleEdit2 *       m_pConsoleEdit;
    eCConsoleListCtrl2 *   m_pConsoleList;
    eCPropertyEditFrame2 * m_pPropertyEditor;
protected:
    void Initialize( void );
public:
    GEBool Create( void );
    GEBool IsValid( void ) const;
    GEBool IsVisible( void ) const;
    GEBool Load( bCString const & );
    GEBool OnHandleMessage( GEUInt, GEUInt, GEI32 );
    GEBool SetUserFrame( bCString const & );
    void   Destroy( void );
    void   Hide( void );
    void   Show( void );
    void   ShowPropertyEditor( eCEntityProxy const &, GEBool );
    void   Update( void );
public:
    eCConsole2 & operator = ( eCConsole2 const & );
public:
    eCConsole2( eCConsole2 const & );
    eCConsole2( void );
};
GE_ASSERT_SIZEOF( eCConsole2, 0x0014 )

#endif
