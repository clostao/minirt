/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:49:14 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/08 18:34:07 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"
#include "color_tools.h"
#include <strings.h>

int main(int argc, char *argv[])
{
    t_scene scene;
    
    //scene = *(t_scene *)read_scene_from_file(argc, argv);
    bzero(&scene, sizeof(scene));
    scene.camera.fov = 90;
    scene.camera.normal = set_vector3(0, 0, 1);
    scene.camera.point= set_vector3(0, 0, 1);
    scene.minilib.session = mlx_init();
    scene.minilib.actual_camera = 0;
    scene.minilib.images = malloc(sizeof(void *));
    *scene.minilib.images = mlx_new_image(scene.minilib.session, 900, 500);
    scene.minilib.window = mlx_new_window(scene.minilib.session, 900, 500, "Todo va de puta madre");
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
    mlx_loop(scene.minilib.session);
}