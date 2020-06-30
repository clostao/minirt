/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:49:14 by clostao-          #+#    #+#             */
/*   Updated: 2020/06/30 16:36:18 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_structures.h"

int main(void)
{
    t_scene scene = read_scene_from_file();
    generate_scene(scene);
}

void generate_scene(t_scene scene)
{
    int         i;
    int         j;
    t_vector3   camera_vector;
    t_color     color;

    i = 0;
    while (i < scene.screen.x)
    {
        j = 0;
        while (j < scene.screen.y)
        {
            camera_vector = get_vector_from_camera_coord(scene.camera, x, y);
            color = calculate_color_from_vector(scene, camera_vector);
            print_on_screen(color, x, y, scene);
            j++;
        }
        i++;   
    }
}