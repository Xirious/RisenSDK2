#ifndef GE_PROPERTYCONVERTER_H_INCLUDED
#define GE_PROPERTYCONVERTER_H_INCLUDED

class GE_DLLIMPORT bCPropertyConverter
{
public:  virtual GEU32 AddReference( void );
public:  virtual GEU32 ReleaseReference( void );
private: virtual void  __FIXME_0008( void ) = 0;
private: virtual void  __FIXME_000C( void ) = 0;
private: virtual void  __FIXME_0010( void ) = 0;
private: virtual void  __FIXME_0014( void ) = 0;
private: virtual void  __FIXME_0018( void ) = 0;
private: virtual void  __FIXME_001C( void ) = 0;
private: virtual void  __FIXME_0020( void ) = 0;
private: virtual void  __FIXME_0024( void ) = 0;
private: virtual void  __FIXME_0028( void ) = 0;
private: virtual void  __FIXME_002C( void ) = 0;
private: virtual void  __FIXME_0030( void ) = 0;
private: virtual void  __FIXME_0034( void ) = 0;
private: virtual void  __FIXME_0038( void ) = 0;
private: virtual void  __FIXME_003C( void ) = 0;
private: virtual void  __FIXME_0040( void ) = 0;
private: virtual void  __FIXME_0044( void ) = 0;
private: virtual void  __FIXME_0048( void ) = 0;
private: virtual void  __FIXME_004C( void ) = 0;
private: virtual void  __FIXME_0050( void ) = 0;
private: virtual void  __FIXME_0054( void ) = 0;
private: virtual void  __FIXME_0058( void ) = 0;
private: virtual void  __FIXME_005C( void ) = 0;
public:  virtual      ~bCPropertyConverter( void );
private:
    GEU32 m_u32ReferenceCount;
public:
    bCPropertyConverter & operator = ( bCPropertyConverter const & );
public:
    bCPropertyConverter( bCPropertyConverter const & );
    bCPropertyConverter( void );
};

#endif
