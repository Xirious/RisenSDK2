#ifndef GE_EFFECTCOMMANDMODIFYENTITY_H_INCLUDED
#define GE_EFFECTCOMMANDMODIFYENTITY_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCEffectCommandModifyEntity'

class GE_DLLIMPORT gCEffectCommandModifyEntity :
    public gCEffectCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandModifyEntity( void );
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt                                    m_iEntityIndex;
    bTPropertyContainer< eEPropertySetType > m_enumPropertySet;
    bCString                                 m_strProperty;
    bCString                                 m_strValue;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEInt &                                          AccessEntityIndex( void );
    bCString &                                       AccessProperty( void );
    bTPropertyContainer< eEPropertySetType > &       AccessPropertySet( void );
    bCString &                                       AccessValue( void );
    GEInt const &                                    GetEntityIndex( void ) const;
    bCString const &                                 GetProperty( void ) const;
    bTPropertyContainer< eEPropertySetType > const & GetPropertySet( void ) const;
    bCString const &                                 GetValue( void ) const;
    void                                             SetEntityIndex( GEInt const & );
    void                                             SetProperty( bCString const & );
    void                                             SetPropertySet( bTPropertyContainer< eEPropertySetType > const & );
    void                                             SetValue( bCString const & );
public:
    gCEffectCommandModifyEntity & operator = ( gCEffectCommandModifyEntity const & );
public:
    gCEffectCommandModifyEntity( gCEffectCommandModifyEntity const & );
    gCEffectCommandModifyEntity( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandModifyEntity, 0x0020 )

#pragma warning( pop )

#endif
