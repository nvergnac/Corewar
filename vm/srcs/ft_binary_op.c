/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:14:06 by pclement          #+#    #+#             */
/*   Updated: 2018/06/05 16:33:05 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_and(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putstr("____________________________________________Je commence AND\n");
	param0 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	param1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info,
			(proc->pc + P_SIZE[0] + P_SIZE[1]), P_SIZE[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 & param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;

	ft_putstr("\nparam1 : ");
	ft_putnbr(param0);
	ft_putstr("\nparam2 : ");
	ft_putnbr(param1);
	ft_putstr("\nval : ");
	ft_putnbr(val);
	ft_putstr("\nreg value :");
	ft_putnbr(proc->reg[reg_idx - 1]);
	ft_putstr("\n");
	ft_putstr("______________________I'm ANDED\n");

	return (0);
}

int	ft_or(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putstr("____________________________________________Je commence OR\n");
	param0 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	param1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info,
			(proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 | param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	return (0);
}

int	ft_xor(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putstr("____________________________________________Je commence XOR\n");
	param0 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	param1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info,
			(proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 ^ param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	return (0);
}
