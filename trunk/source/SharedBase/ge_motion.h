#ifndef GE_MOTION_H_INCLUDED
#define GE_MOTION_H_INCLUDED

//FIXME: bCMotion isn’t exported from SharedBase.
class bCMotion
{
public:
    bCVector     m_vecTranslation;
    bCQuaternion m_qatRotation;
};
GE_ASSERT_SIZEOF( bCMotion, 0x001C )

#endif
