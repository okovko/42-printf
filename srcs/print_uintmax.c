/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uintmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:58:54 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 06:58:54 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_print.h"

int			print_uintmax(void *arg, t_fmt_exp *exp)
{
	return (print_ullong(arg, exp));
}
