/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:18:21 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/09 16:00:33 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "define.h"
# include <ncurses.h>

# include <stdio.h>

typedef struct			s_game
{
	WINDOW				*left_panel;
	WINDOW				*right_panel;
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
	struct s_process	*next;
}						t_process;

typedef struct			s_champion
{
	char				*name;
	char				*comment;
	unsigned char		*code;
	int					size; //size of char *code;
	int					live;
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
void 					arena_init(unsigned char *arena, t_champion *champion,
	t_game *game);
void					game_loop(unsigned char *arena, t_champion *champion,
 	t_game *game);
int						parsing(char *filme, t_champion **champion);

void					live(unsigned char *arena, t_process *process,
	 t_game *game);

void					live2(unsigned char *arena, t_process *process,
	 t_game *game);
#endif
