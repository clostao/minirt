/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microtools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:36:08 by carlos            #+#    #+#             */
/*   Updated: 2020/07/08 19:46:51 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

double get_lowest_positive_value(int argc, ...)
{
    va_list list;
    double min;
    double aux;

    va_start(list, argc);
    min = -1.0;
    while (argc-- > 0)
    {
        aux = va_arg(list, double);
        if (aux > 0.0 && (min == -1.0 || aux < min))
            min = aux;
    }
    return (min);
}

double get_lowest_positive_solution(t_solution solution)
{
    if (solution.x1 < solution.x2 && solution.x1 > 0)
        return (solution.x1);
    return ((solution.x2 > 0) ? solution.x2 : -1);
}

void *ft_memup(void *p_struct, size_t size)
{
    void *pointer;

    pointer = malloc(size);
    memcpy(pointer, p_struct, size);
    return (pointer);
}