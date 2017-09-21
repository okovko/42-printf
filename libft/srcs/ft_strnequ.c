/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:12:01 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:09:17 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, int sz)
{
	if (NULL == s1 || NULL == s2)
		return (0);
	if (sz == 0)
		return (1);
	return (ft_strncmp(s1, s2, sz) ? 0 : 1);
}
