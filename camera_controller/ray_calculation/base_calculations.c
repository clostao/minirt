/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:29:40 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/06 17:30:47 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/headers.h"

t_base calculate_camera_base(t_vector3 z_vector)
{
    t_base result;

    result.k = z_vector;
    ft_get_base_from_normal_vector(result.k, &result.i, &result.j);
    return (result);
}

void    ft_get_base_from_normal_vector(t_vector3 v1, t_vector3 *v2, t_vector3 *v3)
{
	t_vector3 aux;

	if (v1.x)
	{
		aux.x = (- pow(v1.y, 2) - pow(v1.z, 2)) / v1.x;
		aux.y = v1.y;
		aux.z = (aux.x) ? v1.z : 1;
	}
	else if(v1.y)
	{
		aux.y = (- pow(v1.x, 2) - pow(v1.z, 2)) / v1.y;
		aux.x = (aux.y)? v1.x : 1;
		aux.z = v1.z;
	}else
	{
		aux.z = (-pow(v1.x, 2) - pow(v1.x, 2)) / v1.z;
		aux.x = (aux.z) ? v1.x : 1;
		aux.y = v1.y;
	}
	(*v2) = aux;
	(*v3) = cross_vector_product(v1, *v2);
}