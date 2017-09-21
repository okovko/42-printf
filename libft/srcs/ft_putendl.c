/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:40:33 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putendl(char const *ss)
{
	char	nl;

	if (NULL == ss)
		return ;
	nl = '\n';
	write(1, ss, ft_strlen(ss));
	write(1, &nl, 1);
}
