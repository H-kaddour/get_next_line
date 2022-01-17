/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:52:17 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/06 12:44:07 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_before(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_after(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (i - j));
	if (!ptr)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

int	ft_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read(int fd, char *buf, char *tmp, char *str)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = str;
		if (!tmp)
		{
			tmp = malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_newline(str) == 1)
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (!str)
		return (NULL);
	line = ft_before(str);
	str = ft_after(str);
	return (line);
}
