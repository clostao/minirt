/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microtools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:36:08 by carlos            #+#    #+#             */
/*   Updated: 2020/05/21 11:52:17 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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

void *ft_memup(void *p_struct, size_t size)
{
    void *pointer;

    pointer = malloc(size);
    memcpy(pointer, p_struct, size);
    return (pointer);
}