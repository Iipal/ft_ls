include configs/default_lib_config.mk

.PHONY: all multi
multi: $(LIBS_NAMES)
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) CFLAGS="$(CFLAGS_DEBUG)" all
else
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) all
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) -q STATUS

$(OBJS): %.o: %.c
	@$(CC) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(SUCCESS)"

$(LIBS_NAMES):
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

STATUS:
	@$(info / compiled: $(NPWD): $(MSG_SUCCESS_NO_CLR))
	@$(info \ flags: $(CFLAGS))

debug_all: pre
debug: multi

clean:
	@$(DEL) $(OBJS)
	@$(ECHO) "$(CLR_INVERT)deleted$(CLR_WHITE): $(NAME) source objects."
fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD)"

pre: fclean multi
re: fclean multi

norme:
	@$(ECHO) "$(CLR_INVERT)norminette$(CLR_WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean norme del pre debug debug_all STATUS
