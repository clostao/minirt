/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_collide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:28:46 by clostao-          #+#    #+#             */
/*   Updated: 2020/06/30 19:42:32 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/program_management.h"
#include "../headers/math_structures.h"
#include "../headers/coordenates.h"

t_collision circle_collision(t_ray ray, t_circle circle)
{
    t_plane plane;
    t_collision collision;

    plane.point = circle.center;
    plane.normal_vector = circle.normal_vector;
    plane.color = circle.color;
    collision = plane_collision(plane, ray);

}

double  check_is_in_circle(t_circle circle, t_ray ray, double solution)
{
    t_vector3 calculated_point;
    t_vector3 difference_vector;

    if  (solution < 0)
        return (solution);
    calculated_point = get_point_lambda_ray(ray, solution);
    difference_vector = vector_between_two_points(calculated_point, circle.center);
    if (vector_module(difference_vector) > circle.radius)
        return (-1);
    return (solution);
}