NAME := ft_ls
NPWD := $(CURDIR)/$(NAME)

CC     := clang

# all .c files must to placed in to "srcs" folder(or sub-dirs) only.
ifneq (,$(wildcard ./srcs))
SRCS      := $(shell find srcs -name "*.c")
OBJS      := $(SRCS:.c=.o)
endif

# all submodules or additional libs must to be placed in to libs folder
#  and has it's own folder and Makefile with the same rules as this.
ifneq (,$(wildcard ./libs))
LIBS_DIRS := $(shell find ./libs -maxdepth 1 -type d)
LIBS_DIRS := $(filter-out ./libs, $(LIBS_DIRS))
LIBS_NAMES = $(join $(LIBS_DIRS),$(addsuffix .a,$(addprefix /,$(notdir $(LIBS_DIRS)))))
endif

DEL  := rm -rf
