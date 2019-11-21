# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/11/21 12:30:42 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(notdir $(CURDIR)).a
NPWD = $(CURDIR)/$(NAME)

NPROCS := 1
ECHO := echo
MAKE := make

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
ECHO += -e
AR := llvm-ar -rcs
NPROCS:=$(shell grep -c ^processor /proc/cpuinfo)
endif
ifeq ($(UNAME_S),Darwin)
AR := ar -rcs
MAKE := ~/.brew/bin/gmake
NPROCS:=$(shell system_profiler | awk '/Number Of CPUs/{print $4}{next;}')
endif

MAKE += -Otarget --no-print-directory
NPROCS := $(shell expr $(NPROCS) \* 2)

CC := clang

CFLAGS := -march=native -mtune=native -Ofast -pipe -flto -fpic
CFLAGS_DEBUG := -glldb -D DEBUG

CC_WARNINGS_FLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes -I $(CURDIR)/../libft/includes/

SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:%.c=%.o)

DEL := rm -rf

WHITE=\033[0m
BGREEN=\033[42m
GREEN=\033[32m
RED=\033[31m
INVERT=\033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]
SUCCESS_NO_CLR = [✓]

.PHONY: multi all
multi:
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) -j $(NPROCS) -l $(NPROCS) CFLAGS="$(CFLAGS_DEBUG)" all
else
	@$(MAKE) -j $(NPROCS) -l $(NPROCS) all
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) -q STATUS

$(OBJS): %.o: %.c
	@$(CC) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(SUCCESS)"

STATUS:
	@$(info / compiled: $(NPWD): $(SUCCESS_NO_CLR))
	@$(info \ flags: $(CFLAGS))

debug_all: pre
debug: multi

clean:
	@$(DEL) $(OBJS)
fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)deleted$(WHITE): $(NPWD)"

pre: fclean multi
re: fclean multi

norme:
	@$(ECHO) "$(INVERT)norminette$(WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean norme del pre debug debug_all norme STATUS
