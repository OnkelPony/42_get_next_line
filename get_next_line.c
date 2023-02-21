/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:33:42 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/21 18:42:44 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(int fd, char *buffer, char *storage)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!storage)
			storage = ft_strdup("");
		char_temp = storage;
		storage = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

static char	*ft_extract(char *line)
{
	size_t	count;
	char	*storage;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	storage = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*storage == '\0')
	{
		free(storage);
		storage = NULL;
	}
	line[count + 1] = '\0';
	return (storage);
}

/*
Write a function that returns a line read from a file descriptor
fd: The file descriptor to read from
Return: Read line - correct behavior
NULL - there is nothing else to read, or an error occurred
*/
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_get_line(fd, buffer, storage);
	free(buffer);
	// buffer = NULL;
	if (!line)
		return (NULL);
	storage = ft_extract(line);
	return (line);
}
