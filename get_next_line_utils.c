/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:34:12 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/21 18:26:25 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Function returns a pointer to the first occurrence
of the character c in the string s.
c: Character to search.
s: String to search in.
Return: Pointer to the matched character or NULL if the character is not found.
The terminating null byte is considered part of the string,
so that if c is specified as '\0', these functions return a pointer
to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	while (*s != u_c)
	{
		if (!*s++)
		{
			return (NULL);
		}
	}
	return ((char *)s);
}

/*
Function returns a pointer to a new string which is a duplicate
of the string s. Memory for the new string is obtained with malloc(3),
and can be freed with	free(3).
s: The string from which to create the duplicate.
Return: The duplicate of the string.
NULL if the allocation fails.
*/
char	*ft_strdup(const char *src)
{
	char		*dst;
	char		*d;
	const char	*s;
	size_t		i;

	s = src;
	i = 0;
	while (src[i])
	{
		i++;
	}
	dst = malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
	{
		return (NULL);
	}
	d = dst;
	while (*s)
	{
		*d++ = *s++;
	}
	*d = '\0';
	return (dst);
}

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
s1: The prefix string.
s2: The suffix string.
Return: The new string.
NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*p_result;

	result = malloc(sizeof(*result) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	p_result = result;
	while (*s1)
	{
		*p_result++ = *s1++;
	}
	while (*s2)
	{
		*p_result++ = *s2++;
	}
	*p_result = '\0';
	// free((char *)s1);
	return (result);
}

/*
Function calculates the length of the string pointed to by str,
excluding the terminating null byte ('\0').
str: String whose length is measured.
Return: Number of bytes in the string.
*/
size_t	ft_strlen(const char *str)
{
	const char	*p_str;

	p_str = str;
	while (*p_str)
	{
		p_str++;
	}
	return (p_str - str);
}

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
Return: The substring.
NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*p_substr;
	size_t	i;

	s += start;
	p_substr = malloc(sizeof(*p_substr) * (len + 1));
	if (p_substr == NULL)
	{
		return (NULL);
	}
	substr = p_substr;
	i = 0;
	while (*s && ++i <= len)
	{
		*p_substr++ = *s++;
	}
	*p_substr = '\0';
	return (substr);
}
