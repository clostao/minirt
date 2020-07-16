/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:44:33 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/16 20:40:42 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

void    print_on_screen(unsigned int i, unsigned int j, t_scene scene, t_color color)
{
    char            *image;
    int             bpp;
    int             size_line;
    int             endian;
    unsigned int    color_num;
    
    bpp = 4;
    size_line = scene.screen.x * 4;
    endian = 0;
    image = mlx_get_data_addr(*(scene.minilib.images), &bpp, &size_line, &endian);
    color_num = color.lightness * pow(256, 3) + color.red * pow(256, 2) + color.green * 256 + color.blue;
    *image = color_num / pow(2, 24);
    *(image + 1) = (color_num % (unsigned int)pow(2, 24)) / pow(2, 16);
    *(image + 2) = (color_num % (unsigned int)pow(2, 16)) / pow(2, 8);
    *(image + 3) = (color_num % (unsigned int)pow(2, 8));
    (*scene.minilib.images)++;
}