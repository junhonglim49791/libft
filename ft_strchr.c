/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:11:44 by junlim            #+#    #+#             */
/*   Updated: 2026/08/06 18:49:33 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Can't return s as its const char*, need to cast it
2. The strchr() function returns a pointer to the first
	occurrence of the character c in the string s. So need to cast int c to char.
	Also, its more consistent to compare the same type char to ensure they are
	in the same range
	// char is signed on most systems (range -128 to 127).
	// A byte like 0x80 (128) is stored as char = -128.
	// Without the cast: *s (-128) == c (128) -> false, never matches.
	// With the cast:    *s (-128) == (char)c (-128) -> true, matches.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char) c == 0)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>


if NULL is a possible return value, then need to catch it before
using prinf, if not NULL will be dereferenced which causes seg fault

int main(void)
{
	char *s = "Find a char in a string";
	char to_find = 'a';

	printf("%s\n", ft_strchr(s, to_find));
	printf("%s\n", strchr(s, to_find));
}
*/