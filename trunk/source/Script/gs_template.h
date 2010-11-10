#ifndef GS_TEMPLATE_H_INCLUDED
#define GS_TEMPLATE_H_INCLUDED

//HACK: class eCTemplateEntityProxy.
class eCTemplateEntityProxy{};

class Entity;  // forward

class GE_DLLIMPORT Template
{
private:
    eCTemplateEntityProxy m_Proxy;  // 0000
private:
    void Create( GELPCChar );
public:
    GEBool IsValid( void ) const;
public:
               operator bCPropertyID const &  ( void ) const;
               operator eCEntity *            ( void ) const;
               operator eCTemplateEntityProxy ( void ) const;
    GEBool     operator ==                    ( bCPropertyID const & ) const;
    GEBool     operator !=                    ( bCPropertyID const & ) const;
    Template & operator =                     ( GELPCChar );
    Template & operator =                     ( bCPropertyID const & );
    Template & operator =                     ( eCTemplateEntityProxy const & );
    Template & operator =                     ( Entity const & );
    Template & operator =                     ( Template const & );
public:
    Template( GELPCChar );
    Template( bCPropertyID const & );
    Template( eCTemplateEntityProxy const & );
    Template( Entity const & );
    Template( Template const & );
    Template( void );
   ~Template( void );
};

#endif
