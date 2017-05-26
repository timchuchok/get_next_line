/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 11:13:51 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/03 19:45:45 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		check_str(char **str, char **line)
{
	char *tmp;

	tmp = ft_strchr(*str, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*str);
		*str = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *str = NULL;
	int			in;
	char		*buff;

	if (!line)
		return (-1);
	if (str)
		if (check_str(&str, line))
			return (1);
	buff = ft_strnew(BUFF_SIZE);
	while ((in = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[in] = '\0';
		str = ft_strjoin(str, buff);
		if (check_str(&str, line))
			return (1);
	}
	if (in == -1)
		return (-1);
	if (in == 0 && *str == '\0')
		return (0);
	*line = ft_strdup(str);
	*str = '\0';
	return (1);
}
