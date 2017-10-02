/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_schar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 19:46:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 07:20:24 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int		print_schar(t_fmt_exp *exp, va_list ap)
{
	return (print_sint(exp, ap));
}
