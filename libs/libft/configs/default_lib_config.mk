NAME := $(notdir $(CURDIR)).a
NPWD := $(CURDIR)/$(NAME)

CC := clang

CFLAGS := -march=native -mtune=native -Ofast -pipe -flto -fpic
CFLAGS_DEBUG := -glldb -D DEBUG

CFLAGS_WARN := -Wall -Wextra -Werror -Wunused
IFLAGS := $(addprefix -I,$(shell find ../.. -name includes))

SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:.c=.o)

ECHO := echo
MAKE := make
DEL := rm -rf

NPROCS := 1

UNAME_S := $(shell uname -s)
# Linux Specifications:
ifeq ($(UNAME_S),Linux)
# Only for Red-Hat systems where -e param isn't enabled by default in echo built-in command.
# Remove this line if you have enabled -e option.
ECHO += -e

NPROCS := $(shell grep -c ^processor /proc/cpuinfo)
AR := llvm-ar -rcs
endif

# MacOS Specifications:
ifeq ($(UNAME_S),Darwin)
# Only for MacOS where brew install path on home directory
#  or user don't have enought permissions to install latest version of GNUMake on system globally.
# Remove this line if in your MacOS system already installed GNUMake 4.0.0 or later.
MAKE := ~/.brew/bin/gmake

NPROCS := $(shell sysctl -n hw.ncpu)
AR := ar -rcs
endif

MAKE += --no-print-directory
MAKE_PARALLEL_FLAGS := -j $(NPROCS) -l $(NPROCS) -Otarget

CLR_INVERT := \033[7m
CLR_GREEN := \033[32m
CLR_WHITE := \033[0m

MSG_SUCCESS := [$(CLR_GREEN)✓$(CLR_WHITE)]
MSG_ISUCCESS := [$(CLR_INVERT)$(CLR_GREEN)✓$(CLR_WHITE)]
MSG_SUCCESS_NO_CLR := [✓]
