/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:33:42 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/16 17:55:25 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Write a function that returns a line read from a file descriptor
fd: The file descriptor to read from
Return: Read line - correct behavior
NULL - there is nothing else to read, or an error occurred
*/
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*line;
	char		*line_end;
	int			n;

	buffer = malloc(sizeof(*line) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		read(fd, buffer, BUFFER_SIZE);
		line_end = ft_strchr(buffer, '\n');
		if (!line_end)
		{
			if (!storage)
			{
				storage = ft_strdup(buffer);
			}
			else
			{
				storage = ft_strjoin(storage, buffer);
			}
		}
		else
		{
			if (!storage)
			{
				storage = strdup(ft_substr(buffer, 0, (line_end - buffer)));
			}
			else
			{
				storage = ft_strjoin(storage, ft_substr(buffer, 0, (line_end
								- buffer)));
			}
			line = ft_strdup(storage);
			storage = ft_strdup(ft_substr(line_end, 1, (buffer + BUFFER_SIZE
							- line_end)));
			return (line);
		}
	}
}
