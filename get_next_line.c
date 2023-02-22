/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:33:42 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/22 16:13:48 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Reads string from file descriptor and writes it to the buffer. The buffer is
then repeadtedly copied to the storage, till the newline char appears
in the buffer.
fd: File descriptor to read from.
buffer: Buffer of certain size to write to.
storage: Growing place to store contents of buffer.
Return: Content of the storage.*/
static char	*ft_get_line(int fd, char *buffer, char *storage)
{
	int		chars_read;
	char	*p_storage;

	while (1)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read == -1)
			return (NULL);
		else if (chars_read == 0)
			break ;
		buffer[chars_read] = '\0';
		if (!storage)
			storage = ft_strdup("");
		p_storage = storage;
		storage = ft_strjoin(p_storage, buffer);
		free(p_storage);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

/*
Takes line including newlines and returns the part after the first newline.
Changes its parameter to be the part before first newline.
line: String including newlines.
Retrun: String from parameter after the first newline.*/
static char	*ft_get_rest(char *line)
{
	size_t	count;
	char	*rest_of_line;

	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (line[count] == '\0')
		return (NULL);
	rest_of_line = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*rest_of_line == '\0')
	{
		free(rest_of_line);
		rest_of_line = NULL;
	}
	line[count + 1] = '\0';
	return (rest_of_line);
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
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_get_line(fd, buffer, storage);
	free(buffer);
	if (!line)
		return (NULL);
	storage = ft_get_rest(line);
	return (line);
}
