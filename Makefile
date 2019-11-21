include configs/default_config.mk

.PHONY: all multi
multi: $(LIBS_NAMES)
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) CFLAGS="$(CFLAGS_DEBUG)" all
else
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) all
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS_NAMES) $(IFLAGS) -o $(NAME)
	@$(MAKE) STATUS

$(OBJS): %.o: %.c
	@$(CC) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(MSG_BSUCCESS)"

$(LIBS_NAMES):
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

STATUS:
	@$(ECHO) "/ compiled [$(words $(OBJS))] objects to $(CLR_INVERT)$(NAME)$(CLR_WHITE): $(MSG_SUCCESS)"
	@$(ECHO) "\ flags: $(CLR_BLUE)$(CFLAGS)$(CLR_WHITE)"

debug_all: fclean multi
debug: multi

clean:
	@$(foreach L_DIRS,$(LIBS_DIRS),$(MAKE) -C $(L_DIRS) clean;)
	@$(DEL) $(OBJS)
	@$(ECHO) "$(CLR_INVERT)deleted$(CLR_WHITE): $(NAME) source objects."
fclean: clean
	@$(foreach L_DIRS,$(LIBS_DIRS),$(MAKE) -C $(L_DIRS) fclean;)
	@$(DEL) $(NAME)
	@$(ECHO) "$(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD)"

del:
	@$(DEL) $(OBJS)
	@$(DEL) $(NAME)
del_libs:
	@$(DEL) $(LIBS_NAMES)

pre: del multi
re: del del_libs multi

norme:
	@$(ECHO) "$(CLR_INVERT)norminette$(CLR_WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

norme_all:
	@$(foreach L_DIRS,$(LIBS_DIRS),$(MAKE) -C $(L_DIRS) norme;)
	@$(MAKE) norme

.PHONY: re fclean clean norme del pre debug debug_all STATUS
