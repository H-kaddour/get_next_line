/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:25:08 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/05 16:07:09 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int 	i;
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
	{
		ptr[i] = str[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

int ft_newline(char *str)
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

char	*ft_read(int fd, char *buf, char *str)
{
	char	*tmp;
	int	i;

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
			break;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		//free(buf);
		return (NULL);
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str[fd] = ft_read(fd, buf, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_before(str[fd]);
	str[fd] = ft_after(str[fd]);
	return (line);
}
/*
int	main()
{
	int		fd;

	fd = open("line.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}*/
