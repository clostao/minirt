/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_solver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 22:34:20 by carlos            #+#    #+#             */
/*   Updated: 2020/05/14 23:35:01 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_structures.h"

t_solution second_grade_equation_solver(t_trinomial trin)
{
    t_solution res;
    double exist;

    exist = pow(trin.x, 2) - 4 * trin.x2 * trin.c;
    if (exist < 0)
    {
        res.x1 = -1;
        res.x2 = -1;
        return (res);
    }
    exist = sqrt(exist);
    res.x1 = (-1 * trin.x + exist) / (2 * trin.x2);
    res.x2 = (-1 * trin.x - exist) / (2 * trin.x2);
    return (res);
}