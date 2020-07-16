/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:15:51 by carlos            #+#    #+#             */
/*   Updated: 2020/07/16 19:46:37 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_collision  get_collide_from_object(t_object_list *object, t_ray ray)
{
    t_collision aux;
    if (!strcmp(object->type,"cy"))
        return (cylinder_collision(*((t_cylinder *)object->object), ray));
    if (!strcmp(object->type,"sp"))
        return (sphere_collision(*((t_sphere *)object->object), ray));
    if (!strcmp(object->type,"pl"))
        return (plane_collision(*((t_plane *)object->object), ray));
    return (aux);
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
        if (aux.lambda > 0 || aux.lambda < res.lambda)
            res = aux;
        figures = figures->next;
    }
    return (res);
}