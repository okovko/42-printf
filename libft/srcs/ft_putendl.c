/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/21 19:05:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putendl(char const *s)
{
	char	newline;

	if (s)
	{
		newline = '\n';
		write(1, s, ft_strlen(s));
		write(1, &newline, 1);
	}
}
