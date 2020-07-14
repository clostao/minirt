/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:04:25 by carlos            #+#    #+#             */
/*   Updated: 2020/07/14 17:12:29 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_vector3 get_pixel_from_screen(t_base base, short x, short y, t_scene scene)
{
    t_vector3 result;

    result = scene.camera.orientation;
    result.x += tan(scene.camera.fov / 2) * 2 * x / scene.screen.x;
    result.y += tan(scene.camera.fov / 2) * 2 * y / scene.screen.y;
    return (result);
}

t_vector3 ray_from_pixel(t_scene scene, int x, int y)
{
    int fov;
    t_vector3 res;
    static t_base *base = 0;


    if (base == 0)
    {
        base = malloc(sizeof(t_base));
        *base = calculate_camera_base(scene.camera.orientation);
    }
    fov = scene.camera.fov;
    return (get_pixel_from_screen(*base, scene.screen.x / 2 - x, scene.screen.y / 2 - y, scene));
}

