/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:04:25 by carlos            #+#    #+#             */
/*   Updated: 2020/07/01 20:18:13 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/math_structures.h"
#include "../headers/color_tools.h"
#include "../headers/coordenates.h"

t_vector3 ray_from_pixel(t_scene scene, int x, int y)
{
    int fov;
    t_vector3 res;

    fov = scene.camera.fov;
}
