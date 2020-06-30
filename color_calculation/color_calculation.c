/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:03:43 by carlos            #+#    #+#             */
/*   Updated: 2020/06/30 18:30:42 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/figures.h"
#include "../headers/coordenates.h"
#include "../headers/program_management.h"
#include "../headers/math_structures.h"
#include "../headers/main_structures.h"
#include "../headers/color_tools.h"
#include "../headers/collision_tools.h"


t_color calculate_color_from_vector(t_ray ray, t_scene scene)
{
    t_collision collision;
    t_color     color;
    t_color     light_color;
    t_vector3   collision_point;

    collision = calculate_closest_collision(ray, scene);
    if (collision.lambda < 0)
        return (black_color());   
    collision_point = get_point_lambda_ray(ray, collision.lambda);     
    light_color = calculate_light_color_from_collision(collision_point, scene);
    light_color = add_colors(light_color, scene.ambient_light.color);
    color = apply_light_to_color(collision, light_color);
    return (color);
}

t_color calculate_light_color_from_collision(t_vector3 collision_point, t_scene scene)
{
    t_color light_color;
    t_light light;
    t_object_list *lights;
    t_ray light_ray;
    t_collision collision;

    light_color = black_color();
    lights = scene.lights;
    while (lights)
    {
        light = *((t_light *)((lights->object)));
        light_ray = get_collision_ray_from_light(light, collision_point);
        collision = calculate_closest_collision(light_ray, scene);
        if (collision.lambda > 1)
            light_color = add_color(light_color, light.color);
    }
    return (check_color_limits(light_color));
}

t_color check_color_limits(t_color light_color)
{
    t_color result;

    result.red = (light_color.red > 255) ? 255 : light_color.red;
    result.green = (light_color.green > 255) ? 255 : light_color.green;
    result.blue = (light_color.blue > 255) ? 255 : light_color.blue;
    return (result);
}