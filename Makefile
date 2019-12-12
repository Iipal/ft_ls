include configs/default_config.mk

.PHONY: all multi $(LIBS_DIRS) STATUS_START
multi: $(LIBS_DIRS) STATUS_START
 ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) CFLAGS="$(CFLAGS_DEBUG)" DEFINES="$(shell echo $(basename $(subst -,_,$(NAME))) | tr a-z A-Z)_DEBUG" all
 else
  ifneq (,$(filter $(MAKECMDGOALS),sanitize sanitize_all))
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) CFLAGS="$(CFLAGS_SANITIZE)" DEFINES="$(shell echo $(basename $(subst -,_,$(NAME))) | tr a-z A-Z)_SANITIZE" all
  else
	@$(MAKE) $(MAKE_PARALLEL_FLAGS) all
  endif
 endif

STATUS_START:
	@$(ECHO) " | -------"
	@$(ECHO) " | making: $(CLR_UNDERLINE)$(NAME)$(CLR_WHITE) ..."
	@$(ECHO) " | -------"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(addprefix -D,$(DEFINES)) $(CFLAGS) $(OBJS) $(LIBS_NAMES) $(CFLAGS_LIBS) $(IFLAGS) -o $(NAME)
	@$(MAKE) STATUS

-include $(DEPS)
$(OBJS): %.o: %.c
	@$(CC) $(addprefix -D,$(DEFINES)) -c $(CFLAGS) $(CFLAGS_DEFAULT) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(MSG_SUCCESS)"

$(LIBS_DIRS):
 ifneq ($(MAKECMDGOALS),pre)
	@$(MAKE) -C $@ $(MAKECMDGOALS)
 endif

STATUS:
	@$(ECHO) "/"
	@$(ECHO) "| compiled: $(NAME) $(MSG_SUCCESS)"
 ifneq (,$(DEFINES))
	@$(ECHO) "| compiler custom defines: $(foreach dfns,$(DEFINES),$(CLR_INVERT)$(dfns)$(CLR_WHITE) )"
 endif
	@$(ECHO) "| compiler default flags: $(CFLAGS_DEFAULT)"
	@$(ECHO) "| compiler optional flags: $(CLR_UNDERLINE)$(CFLAGS)$(CLR_WHITE)"
	@$(ECHO) "_"

debug_all: fclean multi
debug: multi

sanitize_all: fclean multi
sanitize: multi

del:
	@$(DEL) $(OBJS)
	@$(DEL) $(NAME)
del_libs:
	@$(DEL) $(LIBS_NAMES)

pre: del multi
re: fclean multi

clean: $(LIBS_DIRS)
	@$(DEL) $(OBJS)
	@$(ECHO) " | $(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD) source objects"
fclean: clean $(LIBS_DIRS)
	@$(DEL) $(NAME)
	@$(ECHO) " | $(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD)"

norme:
	@$(ECHO) "$(CLR_INVERT)norminette$(CLR_WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

norme_all:
	@$(foreach L_DIRS,$(LIBS_DIRS),$(MAKE) -C $(L_DIRS) norme;)
	@$(MAKE) norme

.PHONY: re fclean clean norme del pre sanitize sanitize_all debug debug_all STATUS
