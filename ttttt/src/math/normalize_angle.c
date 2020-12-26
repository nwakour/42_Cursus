/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:16 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/25 18:11:18 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}
