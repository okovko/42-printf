/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:37:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/21 21:55:42 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstnode(void const *content, size_t content_size)
{
	t_list	*link;

	NULLIF((link = (t_list *)malloc(sizeof(t_list))) == NULL);
	link->content = (void *)content;
	link->content_size = content_size;
	link->next = NULL;
	return (link);
}
