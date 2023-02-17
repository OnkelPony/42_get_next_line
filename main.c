/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:37:20 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/17 13:40:02 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	char	*buf;

	fd1 = open("foo.txt", O_RDONLY);
	buf = get_next_line(fd1);
	printf("called get_next_line(%d), buf = %s\n", fd1, buf);
	buf = get_next_line(fd1);
	printf("called get_next_line(%d), buf = %s\n", fd1, buf);
	buf = get_next_line(fd1);
	printf("called get_next_line(%d), buf = %s\n", fd1, buf);
}
