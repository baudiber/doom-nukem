/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:59 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:59 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_fd(int n, int fd)
{
	if (n <= -10)
		rec_fd(n / 10, fd);
	ft_putchar_fd(-(n % 10) + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		rec_fd(n, fd);
	}
	else
		rec_fd(-n, fd);
}
