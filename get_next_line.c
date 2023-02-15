/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:33:42 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/15 17:43:18 by jimartin         ###   ########.fr       */
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
	int			n;

		buffer = malloc(sizeof(*line) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	while (1)
	{
		read(fd, buffer, BUFFER_SIZE);
		line[BUFFER_SIZE] = '\0';
		return (line);
	}
}
