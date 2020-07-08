/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collide_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:31:31 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/08 19:35:19 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

double get_cylinder_angle(t_cylinder cylinder, t_ray ray)
{
    return (angle_between_vectors(cylinder.normal_vector, ray.vector));
}