# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2017/02/15 19:18:26 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=		minishell

SRCS_NAME			=		exec_cmd.c\
									get_path.c\
									minishell.c\
									ft_strjoindelimiter.c\
									ft_strtabdup.c\
									ft_strtabfree.c\
									ft_strtabprint.c\
									parse_prompt.c
SRCS_PATH			=		srcs/
SRCS				=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ_NAME			=		$(SRCS_NAME:.c=.o)
OBJ_PATH			=		obj/
OBJ					=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))

FLAGS				=		-Wall -Werror -Wextra
INC					=		-I./includes/ -I./libft/includes/
LIB					=		-L./libft/ -lft

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(INC) $(LIB) -o $(NAME) $(OBJ)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $(INC) -o $@ $<

debug:
	@echo $(SRCS)

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
