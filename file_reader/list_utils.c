/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:51:30 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/14 20:19:42 by clostao-         ###   ########.fr       */
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
    if (scene->camera.camera.fov < 0)
        scene->camera.camera = camera;
    else
    {
        list = scene->camera.next;
        while (list->next)
            list = list->next;
        list = memup(&camera, sizeof(t_camera));
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