#ifndef GE_COMBATOBJECT_H_INCLUDED
#define GE_COMBATOBJECT_H_INCLUDED

class GE_DLLIMPORT gCCombatObject :
    public bCObjectRefBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEBool                     Deserialize( bCXMLParserNode * );
public: virtual GEBool                     Serialize( bCXMLParserNode * );
public: virtual                           ~gCCombatObject( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strName;
    bCString m_strTemplate;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessName( void );
    bCString &       AccessTemplate( void );
    bCString const & GetName( void ) const;
    bCString const & GetTemplate( void ) const;
    void             SetName( bCString const & );
    void             SetTemplate( bCString const & );
public:
    gCCombatObject & operator = ( gCCombatObject const & );
public:
    gCCombatObject( gCCombatObject const & );
    gCCombatObject( void );
};
GE_ASSERT_SIZEOF( gCCombatObject, 0x0010 )

#endif
