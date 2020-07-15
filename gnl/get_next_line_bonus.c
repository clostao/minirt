/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:30:04 by clostao-          #+#    #+#             */
/*   Updated: 2020/07/15 19:53:03 by clostao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		next_line(int fd, char **str)
{
	int			charpos;
	static char	*tab[4096];
	int			readlen;
	char		*readstr;

	(*str) = ft_strdup(tab[fd], 1);
	readlen = BUFFER_SIZE;
	readstr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (((charpos = breakline_is_in_str(*str)) == -1)
	&& (readlen = read(fd, readstr, BUFFER_SIZE)) != 0)
	{
		readstr[readlen] = 0;
		if (readlen == -1 || !(*str = ft_strjoin((*str), readstr)))
			return (-1);
	}
	free(readstr);
	tab[fd] = ft_strdup((*str) + charpos + 1, 0);
	if (readlen == 0)
	{
		free(tab[fd]);
		tab[fd] = 0;
		return (0);
	}
	(*str) = ft_substr(*str, 0, charpos);
	return (1);
}

int		get_next_line(int fd, char **str)
{
	int size = read(fd, *str, 0);
	if (fd < 0 || !str || read(fd, *str, 0) || BUFFER_SIZE <= 0)
		return (-1);
	return (next_line(fd, str));
}
