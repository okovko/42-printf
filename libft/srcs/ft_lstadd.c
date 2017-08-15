/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:03 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 02:38:08 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd(t_list **alst, t_list *new)
{
	NULLCHECK(alst);
	new->next = *alst;
	*alst = new;
	return (*alst);
}
