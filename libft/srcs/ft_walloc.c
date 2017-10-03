/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:53:08 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 17:13:33 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_walloc(int sz)
{
	void	*mm;

	if (sz < 0)
		exit(EXIT_FAILURE);
	if (NULL == (mm = malloc(sz)))
		exit(EXIT_FAILURE);
	return (mm);
}
