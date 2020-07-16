/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:51:30 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/16 19:35:23 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

void *memup(void *pointer, size_t memlen)
{
    unsigned char *read_bytes;
    unsigned char *result;

    read_bytes = (unsigned char *)pointer;
    result = malloc(memlen);
    while (memlen-- > 0)
    {
        *result = *read_bytes;
        result++;
        read_bytes++;
    }
    return (result);
}

void add_to_camera_list(t_scene *scene, t_camera camera)
{
    t_camera_list *list;
    if (scene->cameras == 0)
    {
        scene->cameras = malloc(sizeof(t_camera_list));
        scene->cameras->prev = 0;
        scene->cameras->next = 0;
        scene->cameras->camera = camera;
        scene->camera = camera;
    }
    else
    {
        list = scene->cameras;
        while (list->next)
            list = list->next;
        list->next = malloc(sizeof(t_camera_list));
        list->next->prev = list;
        list->next->next = 0;
        list->next->camera = camera;
    }
}


void add_to_light_list(t_scene *scene, t_light light)
{
    t_object_list *list;
    if (scene->lights == 0)
    {
        scene->lights = calloc(1, sizeof(t_object_list));
        scene->lights->object = memup(&light, sizeof(t_light));
    }
    else
    {
        list = scene->lights;
        while  (list->next)
            list  = list->next;
        list->next = calloc(1, sizeof(t_object_list));
        list->next->object = memup(&light, sizeof(t_light));
    }
}

void add_to_figure_list(t_scene *scene, void *figure, char *type)
{
    t_object_list *list;
    if (scene->figures == 0)
    {
        scene->figures = calloc(1, sizeof(t_object_list));
        scene->figures->object = figure;
        scene->figures->type = strdup(type);
    }
    else
    {
        list = scene->figures;
        while (list->next)
            list = list->next;
        list->next = calloc(1, sizeof(t_object_list));
        list->next->object = figure;
        list->next->type = strdup(type);
    }
}