/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collide.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 08:28:10 by carlos            #+#    #+#             */
/*   Updated: 2020/06/30 19:26:48 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/program_management.h"
#include "../headers/math_structures.h"
#include "../headers/coordenates.h"

t_trinomial get_trinomial_cylinder(t_cylinder cylinder, t_ray ray)
{
    t_binomial x;
    t_binomial y;
    t_binomial z;
    t_trinomial trin;

    x = get_binomial(ray.point.x, ray.vector.x);
    y = get_binomial(ray.point.y, ray.vector.y);
    z = get_binomial(ray.point.z, ray.vector.z);
    trin = get_trinomial_from_binomials(x, y, z, ray);
    return (trin);
}


t_trinomial get_trinomial_from_binomials(t_binomial x, t_binomial y, t_binomial z, t_ray ray)
{
    t_binomial bin1;
    t_binomial bin2;
    t_binomial bin3;
    t_trinomial trin;

    bin1 = get_binomial_from_cylinder_coords(y, ray.point.z, z, ray.point.y);
    bin2 = get_binomial_from_cylinder_coords(z, ray.point.x, x, ray.point.z);
    bin3 = get_binomial_from_cylinder_coords(x, ray.point.y, y, ray.point.x);
    trin = get_trinomial_from_binomial_squared_sum(bin1, bin2, bin3);
    return (trin);
}

t_binomial get_binomial_from_cylinder_coords(t_binomial x, double x_multiplier, t_binomial y, double y_multiplier)
{
    x = multiply_binomial(x, x_multiplier);
    y = multiply_binomial(y, y_multiplier);
    return (binomial_multiplied_sum(x, y, -1));
}

double get_cylinder_collision_angle(t_cylinder cylinder, t_ray ray)
{
    double normal_angle;

    normal_angle = angle_between_vectors(cylinder.normal_vector, ray.vector);
    return (90 - normal_angle);
}

double check_solution(double x, t_cylinder cylinder, t_ray ray)
{
    t_vector3 vector_difference;
    double max;

    max = pow(cylinder.height / 2.0, 2) + pow(cylinder.radius, 2);
    max = sqrt(max);
    if (x > 0)
    {
        vector_difference = vector_between_two_points(cylinder.center, get_point_lambda_ray(ray, x));
        if (vector_module(vector_difference) > max)
            return (-1);
    }
    return (x);
}

t_collision cylinder_collision(t_cylinder cylinder, t_ray ray)
{
    t_trinomial trinomial;
    t_solution solution;
    t_collision collision;

    trinomial = get_trinomial_cylinder(cylinder, ray);
    solution = second_grade_equation_solver(trinomial);
    solution.x1 = check_solution(solution.x1, cylinder, ray);
    solution.x2 = check_solution(solution.x2, cylinder, ray);
    collision.lambda = get_lowest_positive_solution(solution);
    collision.color = cylinder.color;
    collision.angle = get_cylinder_angle(cylinder, ray);
    return (collision);
}