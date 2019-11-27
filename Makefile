include configs/default_config.mk

.PHONY: all multi
multi: $(LIBS_NAMES)
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) CFLAGS="$(CFLAGS_DEBUG)" all
else
ifneq (,$(filter $(MAKECMDGOALS),sanitize sanitize_all))
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) CFLAGS="$(CFLAGS_SANITIZE)" all
else
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) all
endif
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(addprefix "-D ",$(DEFINES)) $(CFLAGS) $(OBJS) $(LIBS_NAMES) $(IFLAGS) -o $(NAME)
	@$(MAKE) STATUS

$(OBJS): %.o: %.c
	@$(CC) $(addprefix "-D ",$(DEFINES)) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(MSG_BSUCCESS)"

$(LIBS_NAMES):
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

STATUS:
	@$(ECHO) "/ compiled: $(NAME) $(MSG_SUCCESS)"
ifneq (,$(DEFINES))
	@$(ECHO) "| defines: $(DEFINES)"
endif
	@$(ECHO) "| details: [$(words $(OBJS))].c, [$(words $(IFLAGS))].h files."
	@$(ECHO) "_ flags: $(CLR_BLUE)$(CFLAGS)$(CLR_WHITE)"

debug_all: fclean multi
debug: multi

sanitize_all: fclean multi
sanitize: multi

clean:
	@$(foreach L_DIRS,$(LIBS_DIRS),$(MAKE) -C $(L_DIRS) clean;)
	@$(DEL) $(OBJS)
	@$(ECHO) " | $(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD) source objects"
fclean: clean
	@$(foreach L_DIRS,$(LIBS_DIRS),$(MAKE) -C $(L_DIRS) fclean;)
	@$(DEL) $(NAME)
	@$(ECHO) " | $(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD)"

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

.PHONY: re fclean clean norme del pre sanitize sanitize_all debug debug_all STATUS
