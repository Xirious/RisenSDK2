#ifndef GE_EFFECTCOMMANDTRIGGERENTITY_H_INCLUDED
#define GE_EFFECTCOMMANDTRIGGERENTITY_H_INCLUDED

class GE_DLLIMPORT gCEffectCommandTriggerEntity :
    public gCEffectCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCEffectCommandTriggerEntity( void );
public: virtual bCString                   GetCommandString( void ) const;
public: virtual void                       OnStart( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt m_iEntityIndex;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEInt &       AccessEntityIndex( void );
    GEInt const & GetEntityIndex( void ) const;
    void          SetEntityIndex( GEInt const & );
public:
    gCEffectCommandTriggerEntity & operator = ( gCEffectCommandTriggerEntity const & );
public:
    gCEffectCommandTriggerEntity( gCEffectCommandTriggerEntity const & );
    gCEffectCommandTriggerEntity( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandTriggerEntity, 0x0010 )

#endif
