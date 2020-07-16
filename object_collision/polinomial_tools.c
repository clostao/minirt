/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polinomial_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:10:23 by carlos            #+#    #+#             */
/*   Updated: 2020/07/16 19:43:42 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_trinomial binomial_square(t_binomial bin)
{
    t_trinomial res;

    res.c = pow(bin.c, 2);
    res.x = -1 * bin.c * bin.x;
    res.x2 = pow(bin.x, 2);
    return (res);
}

t_binomial get_binomial(double c, double x)
{
    t_binomial res;

    res.c = c;
    res.x = x;
    return (res);
}

t_trinomial trinomial_sum(int argc, ...)
{
    va_list args;
    t_trinomial trin;
    t_trinomial aux;

    va_start(args, argc);
    trin = va_arg(args, t_trinomial);
    while (argc-- > 1)
    {
        aux = va_arg(args, t_trinomial);
        trin.c += aux.c;
        trin.x += aux.x;
        trin.x2 += aux.x2;
    }
    return (trin);
}

t_binomial binomial_sum(int argc, ...)
{
    va_list args;
    t_binomial bin;
    t_binomial aux;

    va_start(args, argc);
    bin = va_arg(args, t_binomial);
    while (argc-- > 1)
    {
        aux = va_arg(args, t_binomial);
        bin.c += aux.c;
        bin.x += aux.x;
    }
    return (bin);
}