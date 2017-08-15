/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:45:10 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:04:53 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfpop(t_list **alst)
{
	t_list	*pop;

	if (!alst)
		return (NULL);
	pop = *alst;
	pop->next = NULL;
	*alst = (*alst)->next;
	return (pop);
}
