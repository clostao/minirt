/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:03:59 by carlos            #+#    #+#             */
/*   Updated: 2020/07/14 17:11:08 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_color apply_lightness_to_color(t_color color, double lightness)
{
    t_color res;

    res.red = (int)(color.red * lightness);
    res.blue = (int)(color.blue * lightness);
    res.green = (int)(color.green * lightness);
    return (res);
}

t_color black_color()
{
    t_color res;

    res.red = 0;
    res.green = 0;
    res.blue = 0;
    res.lightness = 0;
    return (res);
}

t_ray get_collision_ray_from_light(t_light light, t_vector3 collision_point)
{
    t_ray   result;

    result.vector = vector_between_two_points(light.point, collision_point);
    result.point = collision_point;
    return (result);
}

t_color add_color(t_color acccolor, t_color light_color, t_collision collision)
{
    t_color result;

    result.red = acccolor.red + light_color.red * light_color.lightness * sin(collision.angle);
    result.green = acccolor.green + light_color.red * light_color.lightness * sin(collision.angle);
    result.blue = acccolor.blue + light_color.red * light_color.lightness * sin(collision.angle);
    return (result);
}