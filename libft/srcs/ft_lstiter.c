/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:10 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:07:22 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*head;

	NULLCHECK(lst, f);
	head = lst;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
	return (head);
}
