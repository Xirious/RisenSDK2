#ifndef GE_INFOCONDITIONNPCSTATUS_H_INCLUDED
#define GE_INFOCONDITIONNPCSTATUS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInfoConditionNPCStatus'

class GE_DLLIMPORT gCInfoConditionNPCStatus :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionNPCStatus, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoConditionNPCStatus( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( eCEntityStringProxy, m_SecondaryNPC,           SecondaryNPC )
    GE_DECLARE_ENUMPROP( gEInfoNPCStatus,     m_enumSecondaryNPCStatus, SecondaryNPCStatus )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionNPCStatus, 0x0018 )

#pragma warning( pop )

#endif
