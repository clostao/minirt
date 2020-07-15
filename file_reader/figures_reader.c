/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:10:48 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/15 18:58:13 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

void insert_square(char *line, t_scene *scene)
{
    t_square *square;

    line+=2;
    square = malloc(sizeof(t_square));
    square->center = read_vector(line);
    remove_vector(&line);
    square->normal_vector = read_vector(line);
    remove_vector(&line);
    square->side_size = read_float(line);
    remove_float(&line);
    square->color = read_color(line);
    remove_color(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in square config");
    add_to_figure_list(scene, square, "sq");
}

void insert_sphere(char *line, t_scene *scene)
{
    t_sphere *sphere;

    line+=2;
    sphere = malloc(sizeof(t_sphere));
    sphere->center = read_vector(line);
    remove_vector(&line);
    sphere->radius = read_float(line);
    remove_float(&line);
    sphere->color = read_color(line);
    remove_color(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in square config");
    add_to_figure_list(scene, sphere, "sp");
}

void insert_plane(char *line, t_scene *scene)
{
    t_plane *plane;

    line+=2;
    plane = malloc(sizeof(t_plane));
    plane->point = read_vector(line);
    remove_vector(&line);
    plane->normal_vector = read_vector(line);
    remove_vector(&line);
    plane->color = read_color(line);
    remove_color(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in plane configuration");
    add_to_figure_list(scene, plane, "pl");
}

void insert_triangle(char *line, t_scene *scene)
{
    t_triangle *triangle;

    line+=2;
    triangle = malloc(sizeof(t_triangle));
    triangle->p1 = read_vector(line);
    remove_vector(&line);
    triangle->p2 = read_vector(line);
    remove_vector(&line);
    triangle->p3 = read_vector(line);
    remove_vector(&line);
    triangle->color = read_color(line);
    remove_color(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in triangle configuration");
    add_to_figure_list(scene, triangle, "tr");
}

void insert_cylinder(char *line, t_scene *scene)
{
    t_cylinder *cylinder;

    line+=2;
    cylinder = malloc(sizeof(t_cylinder));
    cylinder->center = read_vector(line);
    remove_vector(&line);
    cylinder->normal_vector = read_vector(line);
    remove_vector(&line);
    cylinder->color = read_color(line);
    remove_color(&line);
    cylinder->radius = read_float(line) / 2;
    remove_float(&line);
    cylinder->height = read_float(line);
    remove_float(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in cylinder configuration");
    add_circles_from_cylinder(scene, *cylinder);
    add_to_figure_list(scene, cylinder, "cy");
}