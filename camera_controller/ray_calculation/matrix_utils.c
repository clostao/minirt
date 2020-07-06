/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:55:49 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/06 17:20:46 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "headers/math_structures.h"
#include "headers/coordenates.h"

t_vector3   matrix_product_vector(double matrix[3][3], t_vector3 v)
{
	t_vector3   res;

	res.x = (matrix[0][0] * v.x) + (matrix[0][1] * v.y) + (matrix[0][2] * v.z);
	res.y = (matrix[1][0] * v.x) + (matrix[1][1] * v.y) + (matrix[1][2] * v.z);
	res.z = (matrix[2][0] * v.x) + (matrix[2][1] * v.y) + (matrix[2][2] * v.z);
	return (res);
}

void    matrices_product(double a[3][3], double b[3][3], double result[3][3])
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            k = 0;
            result[i][j] = 0;
            while (k < 3)
            {
                result[i][j] += a[i][k] * b[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
}    