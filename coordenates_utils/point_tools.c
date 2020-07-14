/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:42:45 by carlos            #+#    #+#             */
/*   Updated: 2020/07/14 17:08:34 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_vector3 get_point_lambda_ray(t_ray ray, double lambda)
{
    t_vector3 point;

    point.x = ray.vector.x * lambda + ray.point.x;
    point.y = ray.vector.y * lambda + ray.point.y;
    point.z = ray.vector.z * lambda + ray.point.z;
    return (point);
}

t_vector3 vector_between_two_points(t_vector3 v, t_vector3 w)
{
    t_vector3 res;

    res.x = v.x - w.x;
    res.y = v.y - w.y;
    res.z = v.z - w.z;
    return (res);
}