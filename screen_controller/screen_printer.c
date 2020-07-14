/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:44:33 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/14 17:13:36 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

void    print_on_screen(unsigned int i, unsigned int j, t_scene scene, t_color color)
{
    int     x;
    int     y;
    

    mlx_pixel_put(scene.minilib.session, scene.minilib.window, 
    j, i, color.lightness * pow(256, 3) + color.red * pow(256, 2) + color.green * 256 + color.blue);
}