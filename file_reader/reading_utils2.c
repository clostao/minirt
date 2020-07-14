/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:17:13 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/14 20:23:28 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void remove_color(char **line)
{
    while (**line == ' ' && is_digit(**line))
        (*line)++;
    line++;
    while (**line == ' ' && is_digit(**line))
        (*line)++;
    line++;
    while (**line == ' ' && is_digit(**line))
        (*line)++;
}

void remove_float(char **line)
{
    while (**line == ' ' || is_digit(**line))
        (*line)++;
    if (**line == '.')
        (*line)++;
    while (**line == ' ' || is_digit(**line))
        (*line)++;
}

void remove_integer(char **line)
{
    while (**line  == ' ')
        (*line)++;
    if (**line == '-')
        (*line)++;
    while (is_digit(**line))
        (*line)++;
    if (**line != ' ' && **line != 0)
        throw ("Error reading integer");
}

void remove_vector(char **line)
{
    remove_float(line);
    (*line)++;
    remove_float(line);
    (*line)++;
    remove_float(line);
}