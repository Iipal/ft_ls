# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 10:24:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/09/04 09:47:37 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ls
NPWD := $(CURDIR)/$(NAME)

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes \
	-I $(CURDIR)/libft/includes \
	-I $(CURDIR)/libftprintf/includes

SRCS := $(abspath $(wildcard srcs/*.c srcs/*/*.c srcs/*/*/*.c))
OBJ := $(SRCS:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LMAKE := make -C libft
LIBFTPRINTF := $(CURDIR)/libftprintf/libftprintf.a
LFPMAKE := make -C libftprintf

DEL := rm -rf

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS := [$(GREEN)✓$(WHITE)]
SUCCESS2 := [$(INVERT)$(GREEN)✓$(WHITE)]

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -e -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@echo -e "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)

$(LIBFTPRINTF):
	@$(LFPMAKE)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJ)
	@echo -e -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)
	@echo -e "$(SUCCESS2)"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@echo -e "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug_all: set_cc_debug pre
	@echo -e "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: set_cc_debug all
	@echo -e "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean
	@$(LFPMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(LFPMAKE) fclean
	@$(DEL) $(NAME)
	@echo -e "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme:
	@echo -e "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

norme_all:
	@$(LMAKE) norme
	@$(LFPMAKE) norme
	norme

.PHONY: re fclean clean all norme_all norme del pre debug debug_all
