/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:08:35 by clostao-          #+#    #+#             */
/*   Updated: 2020/06/30 17:12:06 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_TOOLS_H
 #define COLLISION_TOOLS_H
 #include "math_structures.h"
 #include "main_structures.h"
 #include "program_management.h"
 
 t_collision calculate_closest_collision(t_ray ray, t_scene scene);

#endif