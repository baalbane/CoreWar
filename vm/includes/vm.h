/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:26:45 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:40:51 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "define.h"

# include <stdio.h>

typedef struct			s_game
{
	unsigned int		nb_players;
	unsigned int		dump;
	int					ncurse;
	unsigned int		cycle_to_die;
	int					nbr_check;
	int					nbr_live;
	struct s_champion	*winner;
	struct s_champion	*champion;
	struct s_process	*process_list;
	struct s_curse		*curse;
}						t_game;

typedef struct			s_champion
{
	char				*name;
	char				*comment;
	unsigned char		*code;
	int					size_code;
	int					number;
	int					position;
	int					live;
	int					color;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_process
{
	unsigned int		live;
	unsigned int		carry;
	int					cooldown;
	int					reg[REG_NUMBER];
	int					pc;
	struct s_process	*next;
}						t_process;

typedef struct			s_header
{
	unsigned int		magic;
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		size;
	char				comment[COMMENT_LENGTH + 4];
	unsigned char		code[CHAMP_MAX_SIZE];
}						t_header;

void					dump_arena(unsigned char *arena);
void					kill_process(t_game *game);
void					move_process(t_process *process, int size);
void					set_champion_position(t_game *game);
void					write_arena(unsigned char *arena, int pc,
	unsigned int value, int size);
unsigned char			reverse_oct_codage(unsigned char n);
short					big_to_little_endian_short(short nb);
int						big_to_little_endian_int(int nb);
int						cooldown(t_process *process, int function_cooldown);
int						exe_process(unsigned char *arena, t_process *process,
	t_game *game);
int						get_champion(char *av, int champion_number,
	t_game *game);
int						init_arena(unsigned char *arena, t_game *game);
int						parsing(int ac, char **av, t_game *game);
int						init_process(t_champion *champion, t_game *game);
int						new_process(t_champion *champion, t_process *process,
	t_game *game);
int						game_loop(unsigned char *arena, t_game *game);
int						get_params(unsigned char *arena, int pc, int dir_size,
	int *tab_param);
int						jump_params(int oct_codage, int dir_size);
int						if_valid_reg(int r);
int						get_value(unsigned char *arena, int pc, int size);
short					get_short_value(unsigned char *arena, int pc);
unsigned char			*ft_unstrndup(unsigned char *line, unsigned int size);
int						if_valid_number(t_champion *champion,
	int champion_number);

int						cw_live(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_ld(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_st(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_add(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_sub(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_and(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_or(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_xor(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_zjmp(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_ldi(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_sti(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_fork(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_lld(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_lldi(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_lfork(unsigned char *arena, t_process *process,
	t_game *game);
int						cw_aff(unsigned char *arena, t_process *process,
	t_game *game);

#endif
