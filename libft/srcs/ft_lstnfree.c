/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 23:10:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:05:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstnfree(t_list **alst, size_t n)
{
	t_list	*tmp;

	NULLCHECK(alst);
	while (*alst)
	{
		if (n > 1)
			ft_lstnfree((t_list **)&((*alst)->content), n - 1);
		else if (n == 1)
			free((*alst)->content);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = NULL;
	return (NULL);
}
