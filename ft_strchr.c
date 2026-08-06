/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:11:44 by junlim            #+#    #+#             */
/*   Updated: 2026/08/06 19:07:41 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main(void)
{
	char *s = "Find a char in a string";
	char to_find = 'a';

	printf("%s\n", ft_strchr(s, to_find));
	printf("%s\n", strchr(s, to_find));
}
*/
