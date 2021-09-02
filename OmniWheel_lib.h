#ifndef OMNI_WHEEL_LIB_h
#define OMNI_WHEEL_LIB_h

#include "Arduino.h"

namespace Omni
{
    constexpr float encoder_cpr = 1200;

    /// \brief constrainAngle : normalizes the angle between -pi and +pi
    /// \param angle : angle that needs to be constrained
    /// \return angle in radians, float type
    float constrainAngle(float angle);

    /// \brief countToRad : function that converts the encoder count to angle in radians and restricts from -pi to +pi
    /// \param count : encoder count
    /// \return angle in radians, float type
    float countToRad(long count);
}
#endif
