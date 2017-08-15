/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:59:55 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/20 03:42:47 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

double	ft_fsqrt(double n)
{
	const size_t	max_i = 20;
	double			root;
	double			square;
	size_t			i;

	RETIF(0, n <= 0);
	root = n > 1 ? n / 2 : 1;
	square = root * root;
	i = 0;
	while ((i < max_i && square < n - 1E-5) || square > n + 1E-5)
	{
		square = root * root;
		root -= (square - n) / 2 / root;
		i++;
	}
	return (root);
}
