; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    test.s                                             :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2017/02/09 17:16:44 by ttridon           #+#    #+#              ;
;    Updated: 2017/03/01 16:43:48 by ttridon          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

.name "test"
.comment "cobaye"

l1:		ld %42, r2
		ld %42, r3
		fork %40
		xor 2, 6, r4
		st r4, 36
		sub r2, r3, r4
		zjmp %32000

l2:
