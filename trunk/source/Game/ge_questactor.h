#ifndef GE_QUESTACTOR_H_INCLUDED
#define GE_QUESTACTOR_H_INCLUDED

enum gEQuestActor
{
    gEQuestActor_Client,
    gEQuestActor_Target,
    gEQuestActor_Count,
    gEQuestActor_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA GELPCChar const g_strQuestActor[ gEQuestActor_Count ];

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCQuestActor'

class GE_DLLIMPORT gCQuestActor :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCQuestActor( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCEntityStringProxy                 m_Actor;
    bTPropertyContainer< gEQuestActor > m_enumActorType;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCEntityStringProxy &                       AccessActor( void );
    bTPropertyContainer< gEQuestActor > &       AccessActorType( void );
    eCEntityStringProxy const &                 GetActor( void ) const;
    bTPropertyContainer< gEQuestActor > const & GetActorType( void ) const;
    void                                        SetActor( eCEntityStringProxy const & );
    void                                        SetActorType( bTPropertyContainer< gEQuestActor > const & );
public:
    GEBool         operator == ( gCQuestActor const & ) const;
    gCQuestActor & operator =  ( gCQuestActor const & );
public:
    gCQuestActor( bCString const &, gEQuestActor );
    gCQuestActor( gCQuestActor const & );
    gCQuestActor( void );
};
GE_ASSERT_SIZEOF( gCQuestActor, 0x0014 )

#pragma warning( pop )

#endif
