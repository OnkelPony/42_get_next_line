/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:33:42 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/21 14:26:14 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_got;

	bytes_got = 108;
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n') && bytes_got != 0)
	{
		bytes_got = read(fd, buffer, BUFFER_SIZE);
		if (bytes_got == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_got] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

static char	*ft_get_line(char *storage)
{
	char	*line;
	char	*newline_char;

	newline_char = ft_strchr(storage, '\n');
	if (!newline_char)
	{
		line = strdup(storage);
	}
	else
	{
		line = ft_substr(storage, 0, (newline_char - storage));
	}
	return (line);
}

static char	*ft_get_rest(char *storage)
{
	char	*newline_char;

	newline_char = ft_strchr(storage, '\n');
	if (!newline_char)
	{
		return (strdup(storage));
	}
	else
	{
		return (strdup(newline_char + 1));
	}
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

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	if (!storage)
	{
		printf("THIS MUST BE CALLED ONLY ONCE!\n");
		storage = malloc(sizeof(*storage) * (BUFFER_SIZE + 1));
		if (!storage)
			return (NULL);
		if (read(fd, storage, BUFFER_SIZE) == -1)
			return (NULL);
	}
	// printf("storage = %s\n", storage);
	storage = ft_fill_storage(fd, storage);
	if (!storage)
	{
		return (NULL);
	}
	// printf("After ft_fill_storage: storage = %s\n", storage);
	line = ft_get_line(storage);
	storage = ft_get_rest(storage);
	return (line);
}
