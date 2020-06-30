/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:07:08 by carlos            #+#    #+#             */
/*   Updated: 2020/06/30 18:49:23 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_TOOLS_H
 #define COLOR_TOOLS_H
 #include "coordenates.h"
 #include "figures.h"
 #include "math_structures.h"
 #include "program_management.h"
 t_color apply_lightness_to_color(t_color color, double lightness);
 double  point_incident_lightness(t_object_list *figures, t_ray light_directed_ray);
 t_ray get_collision_ray_from_light(t_light light, t_vector3 collision_point);
 t_color black_color();
 t_color calculate_color_from_vector(t_ray ray, t_scene scene);
 t_color add_color(t_color acccolor, t_color light_color);
#endif