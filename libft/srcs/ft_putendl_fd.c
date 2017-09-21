/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:20 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:38:31 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putendl_fd(const char *ss, int fd)
{
	char	nl;

	if (NULL == ss)
		return ;
	nl = '\n';
	write(fd, ss, ft_strlen(ss));
	write(fd, &nl, 1);
}
