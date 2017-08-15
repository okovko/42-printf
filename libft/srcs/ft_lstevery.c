/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 21:50:01 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/26 22:42:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_bool	ft_lstevery(t_list *lst, int (*f)(t_list *elem))
{
	while (lst)
	{
		if (!f(lst))
			return (false);
		lst = lst->next;
	}
	return (true);
}
