/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_slong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:08:59 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 06:08:59 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_slong(void *arg, t_fmt_exp *exp)
{
	return (print_sint(arg, exp));
}
