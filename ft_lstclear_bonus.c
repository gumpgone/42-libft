/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:42:46 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/23 17:31:34 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*now;
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	now = *lst;
	while (now)
	{
		temp = now->next;
		del(now->content);
		free(now);
		now = temp;
	}
	*lst = NULL;
}
