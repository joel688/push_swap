# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joakoeni <joakoeni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 12:36:43 by joakoeni          #+#    #+#              #
#    Updated: 2023/03/15 11:37:59 by joakoeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	push_swap

CC	 	= @gcc

FLAG 	= -Wall -Werror -Wextra

SRC = do_nothing_one_less_arg.c ft_atoi.c is_error.c best_move.c sort_less_three.c find_target_b.c sort_hundred.c sort_five_bis.c find_target_b_no_error.c find_target.c cost.c do_pile_a.c sort_lst_five.c go_top.c sort_less_fifty.c ft_strlen.c sa.c ra.c sort_lst_three.c rra.c pb.c sb.c rb.c pa.c rrb.c ss.c rr.c rrr.c find_mediane.c push_swap.c lst_len.c sort.c best_to_move.c freelst.c

OBJS = $(SRC:.c=.o)

# - Colors ------------------------------------------------------------

# Colors

GREY 	 := "\033[1;30m"
RED 	 :=	"\033[1;31m"
GREEN 	 := "\033[1;32m"
YELLOW 	 := "\033[1;33m"
BLUE	 :=	"\033[1;36m"
PURPLE	 :=	"\033[1;35m"
WHITE	 :=	"\033[1;37m"
END		 :=	"\033[0;0m"

# - Files -------------------------------------------------------------

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"$(NAME) has been successfully compiled!"$(END)

# - Clean -------------------------------------------------------------

clean :
	@rm -rf $(OBJS) $(BONUS)
	@echo $(RED)"CLEAN SUCCES !"$(END)

fclean : clean
	@rm -rf $(NAME) checker

re : fclean all

.PHONY:		all bonus clean fclean re
