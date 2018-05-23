/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:43:36 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/23 17:58:08 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_live(t_info *info, t_proc *proc)
{
	int i;
	int	live_int;

	i = 0;
	live_int = ft_ptr_to_uint(info->board + proc->pc - proc->op_size + 1,
			proc->loaded_op.param_size[0]);
	while (i < info->players_nb)
	{
		if (info->players_info[i].number == live_int)
		{
			info->total_lives++;
			info->players_info[i].live++;
			proc->alive = 1;
		}
		i++;
	}
	ft_putstr("I'm Alive\n");
	return (0);
}

int	ft_load(t_info *info, t_proc *proc)
{
	int val;
	int reg_idx;

	ft_putstr("Je commence LOAD\n");
	proc->carry = (proc->carry + 1) % 2;
	val = ft_ptr_to_uint(info->board + proc->pc - proc->op_size + 2,
			proc->loaded_op.param_size[0]);
	reg_idx = ft_ptr_to_uint(info->board + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0] + 2, proc->loaded_op.param_size[1]);
	ft_putstr("val :\t");
	ft_putnbr(val);
	ft_putstr("\n");
	ft_putstr("reg_idx :\t");
	ft_putnbr(reg_idx);
	ft_putstr("\n");
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	proc->reg[reg_idx - 1] = val;
	ft_putstr("\n");
	ft_putstr("I'm Loaded\n");
	return (0);
}

int	ft_store(t_info *info, t_proc *proc)
{
	int val;
	int reg_src_idx;
	int reg_dest_idx;
	
	ft_putstr("Je commence STORE\n");
	val = 0;
	reg_dest_idx = 0;
	reg_src_idx = info->board[2 + proc->pc - proc->op_size];
	if (reg_src_idx <= 0 || reg_src_idx > 16)
		return (0);
	if (info->board[1 + proc->pc - proc->op_size] == 80)
	{
		reg_dest_idx = info->board[2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0]];
		if (reg_dest_idx <= 0 || reg_dest_idx > 16)
			return (0);
		proc->reg[reg_dest_idx - 1] = proc->reg[reg_src_idx - 1];
	}
	if (info->board[1 + proc->pc - proc->op_size] == 112)
	{
		val = ft_ptr_to_uint(info->board + 2 + proc->pc - proc->op_size +
				proc->loaded_op.param_size[0], proc->loaded_op.param_size[1]);
		ft_uint_to_ptr(info->board + proc->pc - proc->op_size + val,
				REG_SIZE, proc->reg[reg_src_idx - 1]);
	}
	ft_putstr("val :\t");
	ft_putnbr(val);
	ft_putstr("\n");
	ft_putstr("reg_dest_idx :\t");
	ft_putnbr(reg_dest_idx);
	ft_putstr("\treg_src_idx :\t");
	ft_putnbr(reg_src_idx);
	ft_putstr("\n");
	ft_putstr("I'm Storeded\n");
	return (0);
}

int	ft_add(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

int	ft_sub(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

