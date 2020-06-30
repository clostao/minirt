/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 00:01:21 by carlos            #+#    #+#             */
/*   Updated: 2020/05/21 13:45:54 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/program_management.h"
#include "../headers/math_structures.h"
#include "../headers/coordenates.h"

t_collision plane_collision(t_plane plane, t_ray ray)
{
    t_binomial bin;
    double lowest_lambda;
    t_collision res;

    bin = get_binomial_from_plane(plane, ray);
    res.lambda = get_solution_from_binomial(bin);
    res.color = plane.color;
    res.angle = get_plane_collision_angle(plane, ray);
    return (res);
}


double get_plane_collision_angle(t_plane plane, t_ray ray)
{
    double normal_angle;

    normal_angle = angle_between_vectors(plane.normal_vector, ray.vector);
    return (90 - normal_angle);
}

t_binomial get_binomial_from_plane(t_plane plane, t_ray ray)
{
    double      d;
    t_binomial  x;
    t_binomial  y;
    t_binomial  z;
    
    d = (plane.normal_vector.x * plane.point.x + plane.normal_vector.y *
    plane.point.y + plane.normal_vector.z * plane.point.z) * (-1);
    x = get_binomial(plane.normal_vector.x * plane.point.x,
    plane.normal_vector.x * ray.vector.x);
    y = get_binomial(plane.normal_vector.y * plane.point.y,
    plane.normal_vector.y * ray.vector.y);
    z = get_binomial(plane.normal_vector.z * plane.point.z,
    plane.normal_vector.z * ray.vector.z);
    return (binomial_sum(3, x, y, z));
}

double get_solution_from_binomial(t_binomial bin)
{
    if (bin.x == 0)
        return (-1);
    return (bin.c / bin.x);
}