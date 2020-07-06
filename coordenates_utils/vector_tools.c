/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:32:44 by carlos            #+#    #+#             */
/*   Updated: 2020/07/06 17:21:41 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/coordenates.h"
#include "../headers/figures.h"
#include "../headers/math_structures.h"
#include "../headers/program_management.h"

t_vector3 set_vector3(double x, double y, double z)
{
    t_vector3 result;

    result.x = x;
    result.y = y;
    result.z = z;
    return (result);
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

t_vector3 cross_vector_product(t_vector3 v, t_vector3 w)
{
    t_vector3 result;

    result.x = v.y * w.z - w.y * v.z;
    result.y = w.x * v.z - v.x * w.z;
    result.z = v.x * w.y - w.x * v.y;
    return (result);
}