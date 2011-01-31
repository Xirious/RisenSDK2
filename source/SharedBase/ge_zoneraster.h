#ifndef GE_ZONERASTER_H_INCLUDED
#define GE_ZONERASTER_H_INCLUDED

#pragma warning( push )
#pragma warning( disable: 4251 )  // class 'bTValArray<>' needs to have dll-interface to be used by clients of class 'bCZoneRaster'

//FIXME: bCZoneRaster seems to be depreciated.
// The only useful/implemented information source is the assignment operator.
// The bCRect/bCPoint members are pure guesswork based on size (and what would make some sense).
class GE_DLLIMPORT bCZoneRaster
{
public:
    struct bCZoneRect
    {
        bCRect  m_Rect;
        bCPoint m_Points[ 2 ];
    };
private:
    bCRect                   m_Rect;
    bTValArray< bCRect >     m_Rects[ 2 ];
    bTValArray< bCZoneRect > m_ZoneRects;
public:
    bCZoneRaster & operator = ( bCZoneRaster const & );
public:
    bCZoneRaster( bTValArray< bCVector > const & );
    bCZoneRaster( bCZoneRaster const & );
   ~bCZoneRaster( void );
};

#pragma warning( pop )

#endif
