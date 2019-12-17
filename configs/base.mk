.EXPORT_ALL_VARIABLES:

NAME := $(notdir $(CURDIR))
NPWD := $(CURDIR)/$(NAME)

# all source code .c files must to places in to "srcs" folder(or sub-dirs) only.
ifneq (,$(wildcard ./srcs))
SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:.c=.o)
ASMS := # reversed for 'assembly' and 'assembly_all' rules where ASMS:=$(SRCS:%.c=%.S) and OBJS:= equals to nothing
else
$(error "all source code .c files must to places in to "srcs" folder(or sub-dirs) only.")
endif
# all header .h files must be placed in to "includes" folder(or sub-dirs) only.
I_PATHS := $(shell find . -name "includes" 2> /dev/null)
ifneq (,$(I_PATHS))
IFLAGS := $(addprefix -I,$(foreach ip,$(I_PATHS),$(shell find $(ip) -type d)))
else
$(error "all header .h files must be placed in to "includes" folder(or sub-dirs) only.")
endif

# all submodules or additional libs must to be placed in to libs folder
#  and has it's own folder and Makefile with the same rules as this.
ifneq (,$(wildcard ./libs))
LIBS_DIRS  := $(shell find ./libs -maxdepth 1 -type d)
LIBS_DIRS  := $(filter-out ./libs, $(LIBS_DIRS))
LIBS_NAMES := $(join $(LIBS_DIRS),$(addsuffix .a,$(addprefix /,$(notdir $(LIBS_DIRS)))))
endif

CC              := clang
CFLAGS          := -Wall -Wextra -Werror -Wunused -MMD
CFLAGS_DEBUG    := -glldb -Og
CFLAGS_SANITIZE := $(CFLAGS_DEBUG) -fsanitize=address
CFLAGS_OPTIMIZE := -march=native -mtune=native -Ofast -pipe -flto -fpic
CFLAGS_ASSEMBLY := $(filter-out -flto -fpic,$(CFLAGS_OPTIMIZE)) -S -masm=intel

CFLAGS_OPTIONAL := $(CFLAGS_OPTIMIZE)

AR              := ar
ARFLAGS         := -rcs

UNAME_S ?= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
AR := llvm-ar
endif
