CFLAGS          := -Wall -Wextra -Werror -Wunused -MMD
CFLAGS_DEBUG    := -glldb -O0
CFLAGS_SANITIZE := $(CFLAGS_DEBUG) -Og -fsanitize=address
CFLAGS_OPTIMIZE := -march=native -mtune=native -Ofast -pipe -flto -fpic
CFLAGS_OPTIONAL := $(CFLAGS_OPTIMIZE)
CFLAGS_LIBS     :=
ARFLAGS         := -rcs

# all .h files must to placed in to "includes" folder(or sub-dirs) only.
I_PATHS := $(shell find . -name "includes" 2> /dev/null)
ifneq (,$(I_PATHS))
IFLAGS := $(addprefix -I,$(foreach ip,$(I_PATHS),$(shell find $(ip) -type d)))
endif
