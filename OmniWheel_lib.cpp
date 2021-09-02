#include "OmniWheel_lib.h"

namespace Omni
{
    float constrainAngle(float angle)
    {
    angle = fmod(angle + PI, 2*PI);

    if (angle < 0)
    {
        angle += 2*PI;
    }

    return angle - PI;
    }

    float countToRad(long count)
    {
    // convert count to radians
    float angle = ((float)count / encoder_cpr) * (2 * PI);

    // constrain the angle between -pi and +pi
    angle = constrainAngle(angle);

    return angle;
    }

    float deg2rad(float degrees)
    {
        return (degrees * PI) / 180;
    }

    float rad2deg(float radians)
    {
        return (radians * 180) / PI;
    }
}