/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:06:30 by carlos            #+#    #+#             */
/*   Updated: 2020/07/06 17:39:14 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STRUCTURES_H
 #define MATH_STRUCTURES_H
 #include <math.h>
 #include <stdarg.h>
 #include <stdlib.h>
 #include "figures.h"
 t_trinomial      binomial_square(t_binomial bin);
 t_binomial       get_binomial(double c, double x);
 t_binomial       binomial_sum(int argc, ...);
 t_solution       second_grade_equation_solver(t_trinomial trin);
 t_trinomial      trinomial_sum(int argc, ...);
 t_binomial       binomial_multiplied_sum(t_binomial x, t_binomial y, int y_multiplier);
 t_binomial       get_binomial_from_cylinder_coords(t_binomial x, double x_multiplier, t_binomial y, double y_multiplier);
 t_binomial       multiply_binomial(t_binomial x, double multiplier);
 t_trinomial      get_trinomial_from_binomial_squared_sum(t_binomial bin1, t_binomial bin2, t_binomial bin3);
 double           get_lowest_positive_value(int argc, ...);
 t_vector3        cross_vector_product(t_vector3 v, t_vector3 w);
 t_base           calculate_camera_base(t_vector3 z_vector);
 typedef struct   s_base
 {
   t_vector3 i;
   t_vector3 j;
   t_vector3 k;
 }                t_base;
 
 typedef struct s_solution
 {
    double x1;
    double x2;
 }              t_solution;
 typedef struct s_trinomial
 {
    double c;
    double x;
    double x2;
 }              t_trinomial;
 typedef struct s_binomial
 {
    double c;
    double x;
 }              t_binomial;
#endif