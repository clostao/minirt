/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:23:01 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/06 17:59:33 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_STRUCTURES_H
 #define MAIN_STRUCTURES_H
 #include "program_management.h"
 #include "math_structures.h"
 typedef struct s_scene {
   t_object_list   *lights;
   t_object_list   *figures;
   t_light         ambient_light;
   t_camera        camera;
   t_screen        screen;    
 }              t_scene;
 typedef struct s_camera {
    t_vector3   point;
    t_vector3   normal;
    short       fov;
 }              t_camera;
 typedef struct s_screen {
    int x;
    int y;
 }              t_screen;
 t_vector3 ray_from_pixel(t_scene scene, int x, int y);
 #endif