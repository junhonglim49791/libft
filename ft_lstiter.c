/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:08:44 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 17:02:51 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*
void	print_nodes(t_list *node)
{
	int i;

	i = 0;
	while(node)
	{
		printf("Node %d's address: %p\n", i, node);
		printf("Node %d's data: %d\n", i, *(int *)node -> content);
		node = node -> next;
		i++;
	}
}

void	add_one(void *num)
{
	*(int *)num += 1;
}

void	setzero(void *num)
{
	*(int *)num = 0;
}

int	main(void)
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	int	a;
	int	b;
	int	c;

	a = 10;
	b = 20;
	c = 30;

	// IMPORTANT TO DO initialization (head = NULL) because it might cause
	// undefine behaviour when its assigned with garbage values
	//"Conditional jump or move depends on uninitialised value(s)"
	// valgrind --leak-check=full --track-origins=yes ./a.out 
	head = NULL;
	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	node3 = ft_lstnew(&c);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	print_nodes(head);
	
	ft_lstiter(head, add_one);
	printf("---------------------------------------------");
	printf("After applying add_one to each node's content");
	printf("---------------------------------------------\n");
	print_nodes(head);
	ft_lstclear(&head, setzero);
}
*/