#pragma once
class Vector3
{
public:
	Vector3(float x, float y, float z);
	float DistanceFrom(Vector3);
	float GetYawAngle(Vector3&);
	float GetPitchAngle(Vector3&);
	float x;
	float y;
	float z;
};