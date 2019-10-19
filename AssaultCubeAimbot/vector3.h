#pragma once
struct coords_t
{
	float x;
	float y;
	float z;
};

struct camera_t
{
	float yaw_angle;
	float pitch_angle;
};

class Vector3
{
public:
	Vector3(float x, float y, float z);
	Vector3(coords_t);
	float DistanceFrom(Vector3);
	float GetYawAngle(Vector3&);
	float GetPitchAngle(Vector3&);
	float x;
	float y;
	float z;
};
