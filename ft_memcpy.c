/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:35:53 by junlim            #+#    #+#             */
/*   Updated: 2026/08/04 23:39:22 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//does not handle memory areas that overlap
/*

Overlap Trace Summary -- ABCDEFGHI\0 (indices 0-9)

index:  0   1   2   3   4   5   6   7   8   9
value:  A   B   C   D   E   F   G   H   I   \0


===========================================================
Case 1: ft_memcpy(buf + 2, buf, 5)  -- dest AFTER src (dest=2, src=0)
===========================================================

--- Forward (k=0->4): buf[2+k] = buf[k] ---

step | read                        | write        | buffer state (idx 0-8)
-----+-----------------------------+--------------+---------------------------
start|                             |              | A B C D E F G H I
k=0  | buf[0]=A                    | buf[2]='A'   | A B A D E F G H I
k=1  | buf[1]=B                    | buf[3]='B'   | A B A B E F G H I
k=2  | buf[2]=A  (overwritten k=0) | buf[4]='A'   | A B A B A F G H I
k=3  | buf[3]=B  (overwritten k=1) | buf[5]='B'   | A B A B A B G H I
k=4  | buf[4]=A  (overwritten k=2) | buf[6]='A'   | A B A B A B A H I

Result: ABABABAHI  -- WRONG


--- Reverse (k=4->0): buf[2+k] = buf[k]  [your implementation] ---

step | read      | write        | buffer state (idx 0-8)
-----+-----------+--------------+---------------------------
start|           |              | A B C D E F G H I
k=4  | buf[4]=E  | buf[6]='E'   | A B C D E F E H I
k=3  | buf[3]=D  | buf[5]='D'   | A B C D E D E H I
k=2  | buf[2]=C  | buf[4]='C'   | A B C D C D E H I
k=1  | buf[1]=B  | buf[3]='B'   | A B C B C D E H I
k=0  | buf[0]=A  | buf[2]='A'   | A B A B C D E H I

Result: ABABCDEHI  -- CORRECT


===========================================================
Case 2: ft_memcpy(buf, buf + 2, 5)  -- dest BEFORE src (dest=0, src=2)
===========================================================

--- Forward (k=0->4): buf[k] = buf[2+k] ---

step | read      | write        | buffer state (idx 0-8)
-----+-----------+--------------+---------------------------
start|           |              | A B C D E F G H I
k=0  | buf[2]=C  | buf[0]='C'   | C B C D E F G H I
k=1  | buf[3]=D  | buf[1]='D'   | C D C D E F G H I
k=2  | buf[4]=E  | buf[2]='E'   | C D E D E F G H I
k=3  | buf[5]=F  | buf[3]='F'   | C D E F E F G H I
k=4  | buf[6]=G  | buf[4]='G'   | C D E F G F G H I

Result: CDEFGFGHI  -- CORRECT


--- Reverse (k=4->0): buf[k] = buf[2+k]  [your implementation, same scenario] ---

step | read                        | write        | buffer state (idx 0-8)
-----+-----------------------------+--------------+---------------------------
start|                             |              | A B C D E F G H I
k=4  | buf[6]=G                    | buf[4]='G'   | A B C D G F G H I
k=3  | buf[5]=F                    | buf[3]='F'   | A B C F G F G H I
k=2  | buf[4]=G  (overwritten k=4) | buf[2]='G'   | A B G F G F G H I
k=1  | buf[3]=F  (overwritten k=3) | buf[1]='F'   | A F G F G F G H I
k=0  | buf[2]=G  (overwritten k=2) | buf[0]='G'   | G F G F G F G H I

Result: GFGFGFGHI  -- WRONG


===========================================================
The rule
===========================================================

dest vs src            | Forward copy | Reverse copy
------------------------+--------------+---------------
dest AFTER src          |  WRONG       |  CORRECT
dest BEFORE src         |  CORRECT     |  WRONG

No single fixed direction handles both cases -- this is exactly why
memcpy overlap is undefined behavior in the standard, and why memmove
(which checks direction at runtime) exists as the safe alternative.
*/
/*
	if (!dest || !src)
		return (dest);
	
	this is not added because its not necessary from the manual's
	standpoint
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s_dst;
	const char	*s_src;

	s_dst = dest;
	s_src = src;
	while (n-- > 0)
		s_dst[n] = s_src[n];
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest1[20] = "This is destination"; // +1 for null
	char dest2[24] = "This is destination too"; // +1 for null
	char src_ft_memcpy[10] = "ft_memcpy"; // +1 for null
	char src_memcpy[7] = "memcpy"; // +1 for null

	printf("dest1: %s\n",dest1);
	ft_memcpy(dest1 + 8, src_ft_memcpy, 9);
	printf("dest1: %s\n",dest1);
	
	printf("dest2: %s\n",dest2);
	memcpy(dest2 + 8, src_memcpy, 6);
	printf("dest2: %s\n",dest2);
	return (0);
}
*/
