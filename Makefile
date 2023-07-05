# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sung-hle <sung-hle@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 11:09:15 by tbornema          #+#    #+#              #
#    Updated: 2023/07/05 20:46:48 by sung-hle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	%%.c \
		%c.c \
		%d%i.c \
		%f.c \
		%f2.c \
		%p.c \
		%s.c \
		%u.c \
		%x%X.c \
		ft_hexutils.c \
		ft_int_to_ascii.c \
		ft_numlen.c \
		ft_printf.c \
		ft_strrev.c \
		ft_uiint_len.c \
		ft_uint_to_ascii.c \
		ft_ulltoa.c \
		handle.c \
		putils.c \
		specifier_skip.c \
		specifier.c \
		unknown.c \
		utils.c 
OBJS	= ${SRCS:.c=.o}

NAME		= libftprintf.a
CC			= cc 
#-Wall -Wextra -Werror

# %.o: %.c ft_printf.h 
# 			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	$(OBJS) *.c
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all


.PHONY:		all clean fclean re bonus 

# SRC_DIR = src/
# OBJ_DIR = obj/
# INC_DIR = includes/

# SRCS = $(wildcard $(SRC_DIR)*.c)
# OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
# DEPS = $(wildcard $(INC_DIR)*.h)

# NAME = libftprintf.a
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# VALGRIND = valgrind --leak-check=full --track-origins=yes

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "Compiling: $<"
# 	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# $(NAME): $(OBJS)
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
# 	@echo "Compilation complete."

# all: $(NAME)

# run: $(NAME)
# 	@$(VALGRIND) ./$(NAME)

# clean:
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
