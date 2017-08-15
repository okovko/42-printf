/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceilsqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 03:40:29 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/20 03:40:29 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ceilsqrt(int n)
{
	const size_t	max_i = 20;
	double			fractional_part;
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
	fractional_part = (root - (int)root);
	return (fractional_part > 1E-5 ? (int)(root + 1) : (int)root);
}
