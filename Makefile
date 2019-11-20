# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 10:24:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/11/20 14:47:29 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO := echo
MAKE := make

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
ECHO += -e
endif
ifeq ($(UNAME_S),Darwin)
MAKE := ~/.brew/bin/gmake
endif

MAKE += -Otarget --no-print-directory

NAME := $(notdir $(CURDIR))
NPWD := $(CURDIR)/$(NAME)

CC = clang

CFLAGS := -march=native -mtune=native -Ofast -pipe -flto -fpic
CFLAGS_DEBUG := -glldb -D DEBUG

CC_WARNINGS_FLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes \
	-I $(CURDIR)/libft/includes \
	-I $(CURDIR)/libstructs \
	-I $(CURDIR)/libftprintf/includes

SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LMAKE := $(MAKE) -C libft
LMAKE_DEP := $(MAKE) -C libft $(MAKECMDGOALS)

LIBFTPRINTF := $(CURDIR)/libftprintf/libftprintf.a
LFPMAKE := $(MAKE) -C libftprintf
LFPMAKE_DEP := $(MAKE) -C libftprintf $(MAKECMDGOALS)

DEL := rm -rf

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS := [$(GREEN)✓$(WHITE)]
SUCCESS2 := [$(INVERT)$(GREEN)✓$(WHITE)]

.PHONY: all multi
multi: $(LIBFT) $(LIBFTPRINTF)
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) -j CFLAGS="$(CFLAGS_DEBUG)" all
else
	@$(MAKE) -j all
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(LIBFT) $(IFLAGS) -o $(NAME)
	@$(MAKE) -q STATUS

$(OBJS): %.o: %.c
	@$(CC) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(SUCCESS)"

$(LIBFT):
	@$(LMAKE_DEP)

$(LIBFTPRINTF):
	@$(LFPMAKE_DEP)

STATUS:
	@$(info / compiled: $(NPWD): $(SUCCESS_NO_CLR))
	@$(info | flags: $(CFLAGS))

debug_all: fclean multi
debug: multi

clean:
	@$(DEL) $(OBJS)
	@$(LMAKE) clean
	@$(LFPMAKE) clean
fclean: clean
	@$(info fclean ft_ls)
	@$(LMAKE) fclean
	@$(LFPMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)deleted$(WHITE): $(NPWD)"

del:
	@$(DEL) $(OBJS)
	@$(DEL) $(NAME)

del_libs:
	@$(DEL) $(LIBFT)
	@$(DEL) $(LIBFTPRINTF)

pre: del multi
re: del del_libs multi

norme:
	@$(ECHO) "$(INVERT)norminette$(WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

norme_all:
	@$(LMAKE) norme
	@$(LFPMAKE) norme
	@make norme

.PHONY: re fclean clean norme_all norme del pre debug debug_all STATUS
