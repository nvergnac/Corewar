/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:49:52 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/29 16:50:31 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_uint_to_ptr(t_info *info, unsigned int ptr, int size, unsigned int value)
{
	int				i;
	int				k;

	i = 0;
	k = size - 1;
	while (i < size)
	{
		info->board[ptr] = value / ft_power(256, k);
		ft_putstr("ptr[i] :\t");
		ft_putnbr(info->board[ptr]);
		ft_putstr("\n");
		ptr = (ptr + 1) % 4096;
		i++;
		k--;
	}
}

unsigned int	ft_ptr_to_uint(unsigned char *ptr, int size)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		result = result * 256 + ptr[i];
		i++;
	}
	return (result);
}
