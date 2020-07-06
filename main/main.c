/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:49:14 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/06 17:51:32 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_structures.h"
#include "color_tools.h"

int main(int argc, char *argv[])
{
    t_scene scene;
    
    scene = read_scene_from_file(argc, argv);
    generate_scene(scene);
}

void generate_scene(t_scene scene)
{
    int         i;
    int         j;
    t_ray   camera_ray;
    t_color     color;
    t_base      base;

    camera_ray.point = scene.camera.point;
    i = 0;
    base =
    while (i < scene.screen.x)
    {
        j = 0;
        while (j < scene.screen.y)
        {
            camera_ray.vector = ray_from_pixel(scene, i, j);
            color = calculate_color_from_vector(camera_ray, scene);
            print_on_screen(color, i, j, scene);
            j++;
        }
        i++;   
    }
}