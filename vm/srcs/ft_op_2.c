/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:15:08 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/29 20:13:09 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_store_indirect(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

int	ft_fork(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

int	ft_long_load(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

int	ft_long_load_indirect(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

int	ft_long_fork(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}

int	ft_aff(t_info *info, t_proc *proc)
{
	(void)proc;
	(void)info->players_nb;
	return (0);
}
