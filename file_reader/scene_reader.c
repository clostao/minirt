/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:45:45 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/15 20:39:19 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

void insert_resolution(char *line, t_scene *scene)
{
    line++;
    scene->screen.x = atoi(line);
    remove_integer(&line);
    scene->screen.y = atoi(line);
    remove_integer(&line);
    if (*line != 0 || scene->screen.x == 0 || scene->screen.y == 0)
        throw ("Error in screen resolution config.");
}

void insert_ambient_light(char *line, t_scene *scene)
{
    line++;
    scene->ambient_light.lightness = read_float(line);
    remove_float(&line);
    scene->ambient_light.color = read_color(line);
    remove_color(&line);
    while (*line == ' ')
        line++;
    if (*line != 0)
        throw ("Error in ambient light config.");
}

void insert_light(char *line, t_scene *scene)
{
    t_light light;

    light.point = read_vector(line);
    remove_vector(&line);
    light.lightness = read_float(line);
    remove_float(&line);
    light.color = read_color(line);
    remove_color(&line);
    while (*line++)
        line++;
    if (*line != 0)
        throw ("Error in light config");
    add_to_light_list(scene, light);
}

void insert_camera(char *line, t_scene *scene)
{
    t_camera camera;

    line++;
    camera.center = read_vector(line);
    remove_vector(&line);
    camera.fov = atoi(line);
    remove_integer(&line);
    camera.orientation = read_vector(line);
    remove_vector(&line);
    add_to_camera_list(scene, camera);
}