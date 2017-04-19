/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2017/03/28 16:39:02 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE    		1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define ADD_COOLDOWN 10
# define AFF_COOLDOWN 2
# define AND_COOLDOWN 6
# define FORK_COOLDOWN 800
# define LD_COOLDOWN 5
# define LDI_COOLDOWN 25
# define LFORK_COOLDOWN 1000
# define LIVE_COOLDOWN 10
# define LLD_COOLDOWN 10
# define LLDI_COOLDOWN 50
# define OR_COOLDOWN 6
# define ST_COOLDOWN 5
# define STI_COOLDOWN 25
# define SUB_COOLDOWN 10
# define XOR_COOLDOWN 6
# define ZJMP_COOLDOWN 20

# define FIRST_OCT (oct_codage & 0b11)
# define SECOND_OCT (oct_codage >> 2 & 0b11)
# define THIRD_OCT (oct_codage >> 4 & 0b11)

#endif
