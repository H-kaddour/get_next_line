/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:57:07 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/05 15:57:25 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = (char *) s1;
	str2 = (char *) s2;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = malloc(sizeof(char ) * len + 1);
	if (ptr == NULL)
		return (NULL);
	while (*str1)
	{
		*ptr++ = *str1++;
	}
	while (*str2)
	{
		*ptr++ = *str2++;
	}
	*ptr = '\0';
	return ((char *) ptr - len);
}

size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
