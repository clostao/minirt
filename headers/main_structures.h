/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:23:01 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/08 19:00:28 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_STRUCTURES_H 
 #define MAIN_STRUCTURES_H
 #include "headers.h"
 typedef struct s_screen {
   int x;
   int y;
 }              t_screen;
 typedef struct   s_minilib
 {
   short int   actual_camera;
   void        **images;
   void        *session;
   void        *window;
 }                t_minilib;
 typedef struct s_scene {
   t_object_list   *lights;
   t_object_list   *figures;
   t_light         ambient_light;
   t_camera        camera;
   t_screen        screen;
   t_minilib       minilib; 
 }              t_scene;
#endif