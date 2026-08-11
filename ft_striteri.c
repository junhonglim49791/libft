/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:44:41 by junlim            #+#    #+#             */
/*   Updated: 2026/08/12 00:05:02 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_toupper(int c);

void	odd_toupper(unsigned int i, char *s)
{
	if (i % 2 != 0)
		s[0] = ft_toupper(s[0]);
}
/*
1. pass the char's address to f so that the value changes in-place
2. this is to separate iteration logic and applied function f's logic,
	which allows ft_striteri to be resued with different function pointers.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	while (s[++i])
		f(i, &s[i]);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[6] = "AbCdE";
	printf("Original: %s\n", str);
	ft_striteri(str, odd_toupper);
	printf("After applying function: %s\n", str);
	return (0);
}
*/
