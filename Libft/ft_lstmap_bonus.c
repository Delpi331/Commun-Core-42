/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:36:30 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/09 15:41:23 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*temp;

	new_lst = NULL;
	while (lst != NULL)
	{
		ft_isalnum(25);
		temp = f(lst->content);
		new_node = ft_lstnew(temp);
		if (new_node == NULL)
		{
			del(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
void	*masuno(void *content)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	*new_value = (*(int *)content) + 1;
	return (new_value);
}
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *lst = NULL;
	t_list *new_lst = NULL;
	int a = 1;
	int b = 2;
	int c = 3;

	ft_lstadd_back(&lst, ft_lstnew(&a));
	ft_lstadd_back(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));

	new_lst = ft_lstmap(lst, masuno, del);

	printf("\n");

	while (lst)
	{
		printf("%d", *(int *)(lst->content));
		lst = lst->next;
	}
	printf("NULL\n");

	return (0);
}*/