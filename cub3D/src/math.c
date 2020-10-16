#include "cub3d.h"

float normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return angle;
}
float rad_to_angle(float rad)
{
	float angle;

	angle = rad * 180 / PI;
	return angle;
}

float dist_points(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
