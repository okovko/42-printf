/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:55:11 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 06:55:11 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int		print_uchar(void *arg, t_fmt_exp *exp)
{
	return (print_uint(arg, exp));
}
