#include <math.h>
#include "vector3.h"

Vector3::Vector3(float x, float y, float z) :x(x), y(y), z(z) {}

float Vector3::DistanceFrom(Vector3& coords)
{
	return sqrtf(powf(coords.x - x, 2) + powf(coords.y - y, 2) + powf(coords.z - z, 2));
}
