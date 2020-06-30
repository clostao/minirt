/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polinomial_tools2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 09:19:54 by carlos            #+#    #+#             */
/*   Updated: 2020/05/16 09:40:23 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_structures.h"

t_binomial binomial_multiplied_sum(t_binomial x, t_binomial y, int y_multiplier)
{
    t_binomial bin;

    bin.x = x.x + y.x * y_multiplier;
    bin.c = x.c + y.c * y_multiplier;
    return (bin);
}

t_binomial multiply_binomial(t_binomial x, double multiplier)
{
    x.x = x.x * multiplier;
    x.c = x.c * multiplier;
    return (x);
}

t_trinomial get_trinomial_from_binomial_squared_sum(t_binomial bin1, t_binomial bin2, t_binomial bin3)
{
    t_trinomial trin1;
    t_trinomial trin2;
    t_trinomial trin3;
    t_trinomial res;

    trin1 = binomial_square(bin1);
    trin2 = binomial_square(bin2);
    trin3 = binomial_square(bin3);
    res = trinomial_sum(3, trin1, trin2, trin3);
    return (res);
}