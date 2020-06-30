/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:04:25 by carlos            #+#    #+#             */
/*   Updated: 2020/05/23 20:11:45 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/math_structures.h"
#include "../headers/color_tools.h"
#include "../headers/coordenates.h"

t_vector3 ray_from_pixel(int x, int y, t_camera camera)
{
    int fov;
    t_vector3 res;

    fov = camera.fov;
}