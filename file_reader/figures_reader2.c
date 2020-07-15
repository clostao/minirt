/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_reader2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:10:18 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/15 18:57:24 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_vector3   get_center_from_cylinder(t_cylinder cylinder, int up)
{
    int         direction;
    double      module;
    t_vector3   result; 
    
    direction = (up) ? 1 : -1;
    module = vector_module(cylinder.normal_vector);
    result.x = cylinder.center.x + cylinder.normal_vector.x * cylinder.height * direction;
    result.y = cylinder.center.y + cylinder.normal_vector.y * cylinder.height * direction;
    result.z = cylinder.center.z + cylinder.normal_vector.z * cylinder.height * direction;
    return (result);
}

void        add_circles_from_cylinder(t_scene *scene, t_cylinder cylinder)
{
    t_circle *up_circle;
    t_circle *down_circle;

    up_circle = malloc(sizeof(t_circle));
    down_circle = malloc(sizeof(t_circle));
    up_circle->center = get_center_from_cylinder(cylinder, 1);
    down_circle->center = get_center_from_cylinder(cylinder, 0);
    up_circle->color = cylinder.color;
    down_circle->color = cylinder.color;
    up_circle->normal_vector = cylinder.normal_vector;
    down_circle->normal_vector = cylinder.normal_vector;
    up_circle->radius = cylinder.radius;
    down_circle->radius = cylinder.radius;
    add_to_figure_list(scene, up_circle, "ci");
    add_to_figure_list(scene, down_circle, "ci");
}

void insert_circle(char *line, t_scene *scene)
{
    t_circle *circle;

    line += 2;
    circle = malloc(sizeof(t_circle));
    circle->center = read_vector(line);
    remove_vector(&line);
    circle->normal_vector = read_vector(line);
    remove_vector(&line);
    circle->radius = read_float(line);
    remove_float(&line);
    circle->color = read_color(line);
    remove_color(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in circle configuration");
    add_to_figure_list(scene, circle, "ci");
}