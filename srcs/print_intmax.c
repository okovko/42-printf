/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:56:02 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 06:56:02 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_print.h"

int			print_intmax(void *arg, t_fmt_exp *exp)
{
	return (print_sllong(arg, exp));
}
