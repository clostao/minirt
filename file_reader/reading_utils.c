/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:57:08 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/16 18:56:38 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

int number_length(int number)
{
    int length;

    length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return (length);
}

double read_float(char *line)
{
    double  result;
    int     integer_part;
    int     decimal_part;

    integer_part = atoi(line);
    result = integer_part;
    while (*line == ' ')
        line++;
    if (*line == '-')
        line++;
    while (is_digit(*line))
        line++;
    if (*line != '.')
        return (result);
    line++;
    if (!is_digit(*line))
        throw ("Error during reading float number");
    decimal_part = atoi(line);
    result = result + decimal_part / pow(10, number_length(decimal_part));
    return (result);
}

t_color read_color(char *line)
{
    t_color color;

    color.red = atoi(line);
    remove_integer(&line);
    if (*line != ',')
        throw ("Error during reading color");
    line++;
    color.green = atoi(line);
    while (*line == ' ')
        line++;
    while (is_digit(*line))
        line++;
    if (*line != ',')
        throw ("Error during reading color");
    line++;
    color.blue = atoi(line);
    return (color);
}

t_vector3 read_vector(char *line)
{
    t_vector3 result;

    result.x = read_float(line);
    remove_float(&line);
    if (*line != ',')
        throw ("Error during reading a vector");
    line++;
    result.y = read_float(line);
    remove_float(&line);
    if (*line != ',')
        throw ("Error during reading a vector");
    line++;
    result.z = read_float(line);
    remove_float(&line);
    return (result);
}