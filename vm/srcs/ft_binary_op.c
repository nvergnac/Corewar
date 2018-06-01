/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:14:06 by pclement          #+#    #+#             */
/*   Updated: 2018/05/29 20:14:16 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_and(t_info *info, t_proc *proc)
{
	unsigned int	param1;
	unsigned int	param2;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putstr("Je commence AND\n");
	param1 = ft_ptr_to_uint(info, (proc->pc - proc->op_size + 2) % MEM_SIZE, proc->loaded_op.param_size[0]);
	param2 = ft_ptr_to_uint(info, (proc->pc - proc->op_size + 2 + proc->loaded_op.param_size[0]) % MEM_SIZE, proc->loaded_op.param_size[1]);
	
	reg_idx = ft_ptr_to_uint(info, (2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0] + proc->loaded_op.param_size[1]) % MEM_SIZE, proc->loaded_op.param_size[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	if ((val = param1 & param2) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	ft_putstr("I'm ANDED\n");
	return (0);
}

int	ft_or(t_info *info, t_proc *proc)
{
	unsigned int	param1;
	unsigned int	param2;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putstr("Je commence OR\n");
	param1 = ft_ptr_to_uint(info, (proc->pc - proc->op_size + 2) % MEM_SIZE, proc->loaded_op.param_size[0]);
	param2 = ft_ptr_to_uint(info, (proc->pc - proc->op_size + 2 + proc->loaded_op.param_size[0]) % MEM_SIZE, proc->loaded_op.param_size[1]);
	
	reg_idx = ft_ptr_to_uint(info, (2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0] + proc->loaded_op.param_size[1]) % MEM_SIZE, proc->loaded_op.param_size[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	if ((val = param1 | param2) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	ft_putstr("I'm ORED\n");
	return (0);
}

int	ft_xor(t_info *info, t_proc *proc)
{
	unsigned int	param1;
	unsigned int	param2;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putstr("Je commence XOR\n");
	param1 = ft_ptr_to_uint(info, (proc->pc - proc->op_size + 2) % MEM_SIZE, proc->loaded_op.param_size[0]);
	param2 = ft_ptr_to_uint(info, (proc->pc - proc->op_size + 2 + proc->loaded_op.param_size[0]) % MEM_SIZE, proc->loaded_op.param_size[1]);
	
	reg_idx = ft_ptr_to_uint(info, (2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0] + proc->loaded_op.param_size[1]) % MEM_SIZE, proc->loaded_op.param_size[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	if ((val = param1 ^ param2) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	ft_putstr("I'm XORED\n");
	return (0);
}