/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 07:41:00 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/05 07:41:00 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

#include "libft.h"

char	*ft_strvchr(char *head, char *from, char q)
{
	while (from >= head)
	{
		if (*from == q)
			return ((char *)from);
		from--;
	}
	return (NULL);
}
