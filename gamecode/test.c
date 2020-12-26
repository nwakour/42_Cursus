/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:10:36 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/12 14:55:10 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"src/cub3d.h"

float	dist_to_point(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
void tri_angle(float x_a, float y_a, float x_b, float y_b, float x_c, float y_c)
{
	float x;
	float y;
	float z;
	float tmp;
	float a_angle;
	float b_angle;
	float c_angle;
	a_angle = 0;
	b_angle = 0;
	c_angle = 0;
	y = dist_to_point(x_a, y_a, x_b, y_b);
	x = dist_to_point(x_b, y_b, x_c, y_c);
	z = dist_to_point(x_c, y_c, x_a, y_a);
	
	tmp = x;
	if (y > tmp)
		tmp = y;
	if (z > tmp)
		tmp = z;
	if (tmp == x)
	{
		c_angle = acos((pow(y,2) - pow(x,2) - pow(z,2))/(-2*x*z));
		a_angle = asin((x * sin(c_angle)) / y);
		b_angle = M_PI - c_angle - a_angle;
		
	}
	else if (tmp == y)
	{
		a_angle = acos((pow(x,2) - pow(z,2) - pow(y,2))/(-2*z*y));
		b_angle = asin((z * sin(a_angle)) / x);
		c_angle = M_PI - b_angle - a_angle;
	}
	else if (tmp == z)
	{
		b_angle = acos((pow(z,2) - pow(x,2) - pow(y,2))/(-2*x*y));
		a_angle = asin((x * sin(b_angle)) / z);
		c_angle = M_PI - b_angle - a_angle;
	}
}
void correct(float init_x, float init_y,float speed, float fuel, float angle, float new_x, float new_y)
{
	//theoratical position
	float distance;
	distance = speed * fuel;
	float x;
	float y;
	float hypo;
	float adj;
	x = init_x + cos(angle) * distance;
	y = init_y + sin(angle) * distance;
	printf("x = %f y = %f", x , y);

	// correct position
	hypo = dist_to_point(init_x , init_y, x, y);
	adj = dist_to_point(init_x , init_y, new_x, new_y);
	float new_angle;
	new_angle = acos(hypo/adj); // drift angle
	float new_dist;
	new_dist = dist_to_point(x, y, new_x, new_y); // drift dist;
	float wind_speed;
	wind_speed = new_dist / fuel; // wind speed
	float new_speed;
	speed = adj / fuel; // correct speed
}

int	main()
{	
	correct(1, 1, 1, 3,((M_PI / 2)/ 2), 4 , 5);
	return (0);
}