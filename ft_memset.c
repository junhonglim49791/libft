/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:37:05 by junlim            #+#    #+#             */
/*   Updated: 2026/08/04 16:21:14 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
DESCRIPTION
       The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
RETURN VALUE
       The memset() function returns a pointer to the memory area s.
c is expected to be 
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		*(str + i++) = c;
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[32] = "This is to learn about memset()"; // +1 for null
	char extra = 'X';  // add this line
	ft_memset(str + 15, '*', 5);
	printf("ft_memset: %s\n",str);
	memset(str + 15 , '*', 5);
	printf("memset: %s\n",str);
	return (0);
}
/*
in this case if 40 bytes all 0x02:
		0x02 0x02 0x02 0x02 0x02 .... 
n byte:  1    2    3    4    5
then the first array element, which is int that has 4 bytes,
would be interpreted as 0x02020202 which is 33686018

void printArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
}

int main()
{
    int n = 10;
    int arr[n];

    // Fill whole array with 100.
    memset(arr, 2, n*sizeof(arr[0]));
    printf("Array after memset()\n");
    printArray(arr, n);

    return 0;
}
*/