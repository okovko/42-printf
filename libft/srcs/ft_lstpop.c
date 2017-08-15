/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:35:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/29 13:35:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **alst)
{
	if (!alst)
		return (NULL);
	while ((*alst)->next && (*alst)->next->next)
		*alst = (*alst)->next;
	(*alst)->next = NULL;
	return (*alst);
}
