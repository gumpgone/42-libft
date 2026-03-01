/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:43:04 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/23 14:20:12 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_and_del(t_list *head, void (*del)(void *))
{
	t_list	*temp;

	while (head)
	{	
		temp = head->next;
		del(head->content);
		free(head);
		head = temp;
	}
}

static void	first_elem(t_list **prev, t_list **new_lst)
{
	if (*prev)
	{
		(*prev)->next = *new_lst;
		*prev = *new_lst;
	}
	else
		*prev = *new_lst;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*content;
	t_list	*head;
	t_list	*prev;

	if (!lst || !f || !del)
		return (0);
	head = NULL;
	prev = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_lst = ft_lstnew(content);
		if (!new_lst)
		{
			del(content);
			free_and_del(head, del);
			return (NULL);
		}
		first_elem(&prev, &new_lst);
		if (head == NULL)
			head = new_lst;
		lst = lst->next;
	}
	return (head);
}
