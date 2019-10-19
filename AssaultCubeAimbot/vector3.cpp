#include <math.h>
#include "vector3.h"

#define PI 3.141592653589793238463

Vector3::Vector3(float x, float y, float z) :x(x), y(y), z(z) {}
Vector3::Vector3(coords_t coords) : x(coords.x), y(coords.y), z(coords.z) {}

float Vector3::DistanceFrom(Vector3 target)
{
	return sqrtf(powf(target.x - x, 2) + powf(target.y - y, 2) + powf(target.z - z, 2));
}

float Vector3::GetYawAngle(Vector3& target)
{
	return atan2f(target.y - y, target.x - x) * (180 / PI) + 90;
}

float Vector3::GetPitchAngle(Vector3& target)
{
	return asin((target.z - z) / DistanceFrom(target)) * (180 / PI);
}
