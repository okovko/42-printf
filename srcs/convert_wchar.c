/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:09:07 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 17:09:07 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_wchar(char *u8, wchar_t wc)
{
	if (wc <= 0x7F)
		u8[0] = wc;
	else if (wc <= 0x7FF)
	{
		u8[0] = 0xC0 | (wc >> 6);
		u8[1] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		u8[0] = 0xE0 | (wc >> 12);
		u8[1] = 0x80 | ((wc >> 6) & 0x3F) + 0x80;
		u8[2] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		u8[0] = 0xF0 | (wc >> 18);
		u8[1] = 0x80 | ((wc >> 12) & 0x3F);
		u8[2] = 0x80 | ((wc >> 6) & 0x3F);
		u8[3] = 0x80 | (wc & 0x3F);
	}
	return (wchar_sz(wc));
}
