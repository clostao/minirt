/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 22:31:59 by carlos            #+#    #+#             */
/*   Updated: 2020/05/21 11:50:01 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/program_management.h"
#include "../headers/math_structures.h"
#include "../headers/coordenates.h"

t_collision sphere_collision(t_sphere sphere, t_ray ray)
{
    t_trinomial trin;
    t_solution solution;
    double lowest_lambda;
    t_collision res;

    trin = get_trinomial_from_sphere(sphere, ray);
    solution = second_grade_equation_solver(trin);
    lowest_lambda = get_lowest_positive_value(2, solution.x1, solution.x2);
    res.lambda = lowest_lambda;
    res.color = sphere.color;
    return (res);
}

t_trinomial get_trinomial_from_sphere(t_sphere sphere, t_ray ray)
{
    t_trinomial x;
    t_trinomial y;
    t_trinomial z;

    x = binomial_square(get_binomial(ray.point.x - sphere.center.x, ray.vector.x));
    y = binomial_square(get_binomial(ray.point.y - sphere.center.y, ray.vector.y));
    y = binomial_square(get_binomial(ray.point.z - sphere.center.z, ray.vector.z));
    return (trinomial_sum(3, x, y, z));
}