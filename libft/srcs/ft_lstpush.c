/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 21:29:10 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/14 11:29:35 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **alst, t_list *new)
{
	NULLCHECK(alst);
	while (*alst)
		*alst = (**alst).next;
	*alst = new;
	return (*alst);
}
