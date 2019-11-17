# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 10:24:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/11/18 01:16:22 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO := echo
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO += -e
endif

NAME := ft_ls
NPWD := $(CURDIR)/$(NAME)

CC_BASE := clang -march=native -mtune=native

CC := $(CC_BASE) -Ofast -pipe -flto -fpic
CC_DEBUG := $(CC_BASE) -glldb -D DEBUG

CFLAGS := -Wall -Wextra -Werror -Wunused -Weverything
IFLAGS := -I $(CURDIR)/includes \
	-I $(CURDIR)/libft/includes \
	-I $(CURDIR)/libstructs \
	-I $(CURDIR)/libftprintf/includes

SRCS := $(abspath $(wildcard $(shell find srcs -name "*.c")))
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

.PHONY: all multi
multi:
	@$(MAKE) -j8 all

all: $(NAME)

$(OBJ): %.o: %.c
	@$(ECHO) ' $| $@ '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(LIBFTPRINTF):
	@$(LFPMAKE)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJ)
	@$(ECHO) -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)
	@$(ECHO) "$(SUCCESS2)"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@$(ECHO) "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug_all: set_cc_debug pre
	@$(ECHO) "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: set_cc_debug all
	@$(ECHO) "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean
	@$(LFPMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(LFPMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme:
	@$(ECHO) "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

norme_all:
	@$(LMAKE) norme
	@$(LFPMAKE) norme
	@make norme

.PHONY: re fclean clean norme_all norme del pre debug debug_all
