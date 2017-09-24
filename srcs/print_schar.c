/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_schar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 19:46:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 06:54:13 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int		print_schar(void *arg, t_fmt_exp *exp)
{
	return (print_sint(arg, exp));
}
