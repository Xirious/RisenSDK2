#ifndef GE_ZONERASTER_H_INCLUDED
#define GE_ZONERASTER_H_INCLUDED

class bCVector;  // forward

#pragma warning( push )
#pragma warning( disable: 4251 )  // class 'bTValArray<>' needs to have dll-interface to be used by clients of class 'bCZoneRaster'

//FIXME: bCZoneRaster seems to be depreciated.
// The only useful/implemented information source is the assignment operator.
// The bCRect/bCPoint members are pure guesswork based on size (and what would make some sense).
class GE_DLLIMPORT bCZoneRaster
{
public:
    struct bCFIXME
    {
        bCRect  m_Rect;
        bCPoint m_FIXME_10;
        bCPoint m_FIXME_1C;
    };
private:
    bCRect                m_Rect;
    bTValArray< bCRect >  m_arrFIXME_10;
    bTValArray< bCRect >  m_arrFIXME_1C;
    bTValArray< bCFIXME > m_arrFIXME_28;
public:
    bCZoneRaster & operator = ( bCZoneRaster const & );
public:
    bCZoneRaster( bTValArray< bCVector > const & );
    bCZoneRaster( bCZoneRaster const & );
   ~bCZoneRaster( void );
};

#pragma warning( pop )

#endif
