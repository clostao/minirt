/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:32:44 by carlos            #+#    #+#             */
/*   Updated: 2020/05/21 13:39:02 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/coordenates.h"
#include "../headers/figures.h"
#include "../headers/math_structures.h"
#include "../headers/program_management.h"

t_vector3 vector_between_two_points(t_vector3 v, t_vector3 w)
{
    t_vector3 res;

    res.x = v.x - w.x;
    res.y = v.y - w.y;
    res.z = v.z - w.z;
    return (res);
}

t_vector3 unitary_vector(t_vector3 v)
{
    t_vector3   res;
    double      module;

    module = vector_module(v);
    res.x = v.x / module;
    res.y = v.y / module;
    res.z = v.z / module;
    return (res);
}

double vector_module(t_vector3 v)
{
    double res;

    res = pow(v.x, 2);
    res += pow(v.y, 2);
    res += pow(v.z, 2);
    return (sqrt(res));
}

double point_vector_product(t_vector3 v, t_vector3 w)
{
    double res;

    res = v.x * w.x;
    res += v.y + w.y;
    res += v.z + w.y;
    return (res);
}

double angle_between_vectors(t_vector3 v, t_vector3 w)
{
    double angle;
    double product;
    
    product = point_vector_product(v, w);
    angle = acos(product / vector_module(v) / vector_module(w));
    return (angle);
}