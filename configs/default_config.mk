NAME := $(notdir $(CURDIR))
NPWD := $(CURDIR)/$(NAME)

CC := clang

CFLAGS := -march=native -mtune=native -Ofast -pupe -flto -fpic
CFLAGS_DEBUG := -glldb -D DEBUG

CFLAGS_WARN := -Wall -Wextra -Werror -Wunused
IFLAGS := $(addprefix -I,$(shell find . -name includes))

SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:.c=.o)

LIBS_DIRS := $(shell find ./libs/ -maxdepth 1 -type d)
LIBS_DIRS := $(filter-out $(firstword $(LIBS_DIRS)), $(LIBS_DIRS))
LIBS_NAMES := $(join $(LIBS_DIRS),$(addsuffix .a,$(addprefix /,$(notdir $(LIBS_DIRS)))))

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
endif

# MacOS Specifications:
ifeq ($(UNAME_S),Darwin)
# Only for MacOS where brew install path on home directory
#  or user don't have enought permissions to install latest version of GNUMake on system globally.
# Remove this line if in your MacOS system already installed GNUMake 4.0.0 or later.
MAKE := ~/.brew/bin/gmake

NPROCS:=$(shell system_profiler | awk '/Number Of CPUs/{print $4}{next;}')
endif

MAKE += -Otarget --no-print-directory

CLR_INVERT := \033[7m
CLR_GREEN := \033[32m
CLR_WHITE := \033[0m

MSG_SUCCESS := [$(CLR_GREEN)✓$(CLR_WHITE)]
MSG_ISUCCESS := [$(CLR_INVERT)$(CLR_GREEN)✓$(CLR_WHITE)]
