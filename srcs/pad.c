/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 20:14:32 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/20 00:11:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pad(t_fmt_exp *exp, int sz, char *ss)
{
	t_bool	left;
	t_bool	fsign;
	t_bool	ssign;
	char	pad;

	left = 0;
	pad = ' ';
	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	if (exp->flags & E_FMT_FLAG_BIT_LEFT_PAD_ZEROES)
	{
		pad = '0';
		left = 1;
	}
	if (fsign = (exp->flags & E_FMT_FLAG_BIT_FORCE_SIGN))
		sz++;
	if (ssign = (exp->flags & E_FMT_FLAG_BIT_SPACE_SIGN))
		
}
