#ifndef GS_TEMPLATE_H_INCLUDED
#define GS_TEMPLATE_H_INCLUDED

class GE_DLLIMPORT Template
{
protected:
    eCTemplateEntityProxy m_Proxy;
public:
    Template( void );
    Template( Template const & );
    Template( Entity const & );
    Template( GELPCChar );
    Template( bCPropertyID const & );
    Template( eCTemplateEntityProxy const & );
   ~Template( void );
public:
    Template & operator =                     ( Template const & );
    Template & operator =                     ( Entity const & );
    Template & operator =                     ( GELPCChar );
    Template & operator =                     ( bCPropertyID const & );
    Template & operator =                     ( eCTemplateEntityProxy const & );
    GEBool     operator ==                    ( bCPropertyID const & ) const;
    GEBool     operator !=                    ( bCPropertyID const & ) const;
               operator bCPropertyID const &  ( void ) const;
               operator eCEntity *            ( void ) const;
               operator eCTemplateEntityProxy ( void ) const;
public:
    GEBool IsValid( void ) const;
private:
    void Create( GELPCChar );
};
GE_ASSERT_SIZEOF( Template, 0x0004 )

#endif
