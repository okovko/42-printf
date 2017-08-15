/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvchrhed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:48:25 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/24 06:34:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

#include "libft.h"

char	*ft_strvchrhed(char *head, char *from, char q)
{
	while (from > head)
	{
		if (*from == q)
			return ((char *)from);
		from--;
	}
	return ((char *)from);
}
