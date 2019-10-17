#include <math.h>
#include "vector3.h"

#define PI 3.141592653589793238463

Vector3::Vector3(float x, float y, float z) :x(x), y(y), z(z) {}

float Vector3::DistanceFrom(Vector3& coords)
{
	return sqrtf(powf(coords.x - x, 2) + powf(coords.y - y, 2) + powf(coords.z - z, 2));
}

float Vector3::GetYawAngle(Vector3& target)
{
	return atan2f(target.y - y, target.x - x) * (180 / PI) + 90;
}

float Vector3::GetPitchAngle(Vector3& target)
{
	return asin((target.z - z) / DistanceFrom(target)) * (180 / PI);
}
