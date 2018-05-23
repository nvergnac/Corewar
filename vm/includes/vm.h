/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:17 by pclement          #+#    #+#             */
/*   Updated: 2018/05/23 17:17:30 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

typedef struct		s_op
{
	char			*mnemonic;
	int				param_nb;
	int				param_size[3];
	int				opcode;
	int				cycle_nb;
	char			*full_name;
	short			codage_octal;
	short			dir_size;
}					t_op;

typedef struct		s_proc
{
	int				reg[16];
	char			carry;
	int				pc;
	int				alive;
	t_op			loaded_op;
	short			op_size;
	struct s_proc	*next;
	struct s_proc	*prev;
}					t_proc;

typedef struct		s_player
{
	int				fd;
	void			*header;
	unsigned int	magic;
	char			*name;
	char			*comment;
	unsigned int	size;
	unsigned char	*program;
	int				live;
	int				turn;
	int				number;
}					t_player;

typedef struct		s_info
{
	unsigned char	board[MEM_SIZE];
	t_proc			*first_processus;
	int				cycles_to_die;
	int				cycles;
	int				check;
	int				lives_threshold;
	int				total_lives;
	int				dump;
	int				players_nb;
	t_player		players_info[MAX_PLAYERS];
	char			argv[15];
	int				player_one;
	int				last_player_alive;
	int				countdown_to_die;
}					t_info;

int					ft_atoi_cor(const char *str);
void				ft_error(int error_code);
t_info				*ft_init_info(void);
void				ft_check_argc(int argc, char **argv, t_info *info);
void				ft_define_players(int argc, char **argv, t_info *info);
t_proc				*ft_init_proc(int pc);
void				ft_create_proc(t_info *info);
int					get_player(t_player *player);
int					set_vm(t_info *info);
void				ft_run_vm(t_info *info);
unsigned int		ft_ptr_to_uint(unsigned char *ptr, int size);
void				ft_uint_to_ptr(unsigned char *ptr, int size, int value);
void				free_player(t_player *player);
int					ft_live(t_info *info, t_proc *proc);
int					ft_load(t_info *info, t_proc *proc);
int					ft_store(t_info *info, t_proc *proc);
int					ft_add(t_info *info, t_proc *proc);
int					ft_sub(t_info *info, t_proc *proc);
int					ft_and(t_info *info, t_proc *proc);
int					ft_or(t_info *info, t_proc *proc);
int					ft_xor(t_info *info, t_proc *proc);
int					ft_zjump(t_info *info, t_proc *proc);
int					ft_load_indirect(t_info *info, t_proc *proc);
int					ft_store_indirect(t_info *info, t_proc *proc);
int					ft_fork(t_info *info, t_proc *proc);
int					ft_long_load(t_info *info, t_proc *proc);
int					ft_long_load_indirect(t_info *info, t_proc *proc);
int					ft_long_fork(t_info *info, t_proc *proc);
int					ft_aff(t_info *info, t_proc *proc);

#endif
