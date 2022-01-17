/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:53:57 by hkaddour          #+#    #+#             */
/*   Updated: 2022/01/06 12:46:32 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, char *tmp, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *str);
char	*ft_before(char *str);
char	*ft_after(char *str);
int		ft_newline(char *str);

#endif
