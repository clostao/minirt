/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:42:45 by carlos            #+#    #+#             */
/*   Updated: 2020/05/21 12:32:32 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/program_management.h"

t_vector3 get_point_lambda_ray(t_ray ray, double lambda)
{
    t_vector3 point;

    point.x = ray.vector.x * lambda + ray.point.x;
    point.y = ray.vector.y * lambda + ray.point.y;
    point.z = ray.vector.z * lambda + ray.point.z;
    return (point);
}