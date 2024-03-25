/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:34:06 by etornay-          #+#    #+#             */
/*   Updated: 2023/07/25 15:52:55 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (str = NULL, NULL);
	}
	result = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (result == NULL)
		return (free(str), str = NULL, NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		result[j++] = str[i++];
	result[j] = '\0';
	return (free(str), str = NULL, result);
}

static char	*get_line(char *str)
{
	char	*act;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	act = ft_calloc(i + 1 + (str[i] == '\n'), sizeof(char));
	if (act == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		act[i] = str[i];
		i++;
	}
	if (str[i] != '\0' && str[i] == '\n')
	{
		act[i] = '\n';
		i++;
	}
	act[i] = '\0';
	return (act);
}

static char	*read_fd(int fd, char *str)
{
	char	*save;
	int		count;

	count = 1;
	save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (save == NULL)
		return (free(save), free(str), str = NULL, NULL);
	while (!ft_strchr(save, '\n') && count != 0)
	{
		count = read(fd, save, BUFFER_SIZE);
		if (count < 0)
			return (free(save), NULL);
		save[count] = '\0';
		str = ft_strjoin(str, save);
		if (str == NULL)
			return (free(save), free(str), str = NULL, NULL);
	}
	return (free(save), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	str = read_fd(fd, str);
	if (str == NULL)
		return (free(str), str = NULL, NULL);
	line = get_line(str);
	if (line == NULL)
		return (free(str), str = NULL, NULL);
	str = clean(str);
	if (str == NULL)
		return (free(str), str = NULL, line);
	return (line);
}
/* 
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fichero;
	char	*line;

	fichero = open("text.txt", O_RDONLY);
	line = get_next_line(fichero);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fichero);
	}
	printf("\n");
	close(fichero);
	free(line);
	return (0);
} */