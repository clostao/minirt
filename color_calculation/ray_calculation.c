/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:15:51 by carlos            #+#    #+#             */
/*   Updated: 2020/06/30 17:08:05 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/figures.h"
#include "../headers/coordenates.h"
#include "../headers/program_management.h"
#include "../headers/math_structures.h"

t_collision  get_collide_from_object(t_object_list *object, t_ray ray)
{
    if (!strcmp(object->type,"cylinder"))
        return (cylinder_collision(*((t_cylinder *)object->object), ray));
    if (!strcmp(object->type,"sphere"))
        return (sphere_collision(*((t_sphere *)object->object), ray));
    if (!strcmp(object->type,"plane"))
        return (plane_collision(*((t_plane *)object->object), ray));
}

t_collision calculate_closest_collision(t_ray ray, t_scene scene)
{
    t_collision res;
    t_collision aux;
    t_object_list *figures = scene.figures;

    res.angle = 0;
    res.lambda = -1;
    while (figures)
    {
        aux = get_collide_from_object(figures, ray);
        if (aux.lambda > 0 || aux.lambda < res.lambda)
            res = aux;
    }
    return (res);
}