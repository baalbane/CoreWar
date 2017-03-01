/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:18:21 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/01 16:47:14 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "define.h"
# include <limits.h>
# include <ncurses.h>

# include <stdio.h>

typedef struct			s_game
{
	struct s_process	*start_process;
	int					nb_players;
	int					ncurses;
	int					dump;
	int					cycle_to_die;
	int					check;
	int					nbr_live;
	int					winner;
}						t_game;

typedef struct			s_process
{
	int					live;
	int					carry;
	int					cooldown;
	int					reg[REG_NUMBER];
	int					PC;
	struct s_champion	*champion;
	struct s_process	*next;
}						t_process;

typedef struct			s_champion
{
	char				*name;
	char				*comment;
	unsigned char		*code;
	int					size; //size of char *code;
	int					live;
	int					last_live;
	int					number;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_header
{
	unsigned int		magic;
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		size;
	char				comment[COMMENT_LENGTH + 4];
	unsigned char		code[CHAMP_MAX_SIZE];
}						t_header;

void					arena_aff(unsigned char *arena);
void 					arena_init(unsigned char *arena, t_champion *champion, t_game *game);
void					game_loop(unsigned char *arena, t_champion *champion, t_game *game);
void					get_args(unsigned char *arena, t_process *process, int *tab, int dir_size);
void					rewrite_arena(unsigned char *arena, int PC, int value);

int						check_reg(unsigned char var, int *tab);
int						get_ind(unsigned char *arena, int PC);
int						get_value(unsigned char *arena, t_process *process, int size);
int						parsing(char *filme, t_champion **champion);
int						move_PC(int PC, int size);

void					live(unsigned char *arena, t_process *process, t_champion *champion, t_game *game);
void					ld(unsigned char *arena, t_process *process);
void					st(unsigned char *arena, t_process *process);
void					add(unsigned char *arena, t_process *process);
void					sub(unsigned char *arena, t_process *process);
void					and(unsigned char *arena, t_process *process);
void					or(unsigned char *arena, t_process *process);
void					xor(unsigned char *arena, t_process *process);
void					zjmp(unsigned char *arena, t_process *process);
void					ldi(unsigned char *arena, t_process *process);
void					sti(unsigned char *arena, t_process *process);
void					ft_fork(unsigned char *arena, t_process *process, t_game *game);

#endif
