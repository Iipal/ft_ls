include configs/default_config.mk

.PHONY: all multi
multi:
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	$(info $(MAKE))
	@$(MAKE) -j $(NPROCS) -l $(NPROCS) CFLAGS="$(CFLAGS_DEBUG)" all
else
	@$(MAKE) -j $(NPROCS) -l $(NPROCS) all
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS_NAMES) $(IFLAGS) -o $(NAME)
	@$(MAKE) -q STATUS

$(OBJS): %.o: %.c
	@$(CC) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(SUCCESS)"

STATUS:
	@$(info / compiled: $(NPWD): $(SUCCESS_NO_CLR))
	@$(info | flags: $(CFLAGS))

debug_all: fclean multi
debug: multi

clean:
	@$(DEL) $(OBJS)
	# @$(LMAKE) clean
	# @$(LFPMAKE) clean
fclean: clean
	@$(info fclean ft_ls)
	# @$(LMAKE) fclean
	# @$(LFPMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)deleted$(WHITE): $(NPWD)"

del:
	@$(DEL) $(OBJS)
	@$(DEL) $(NAME)
del_libs:
	@$(DEL) $(LIBS_NAMES)

pre: del multi
re: del del_libs multi

norme:
	@$(ECHO) "$(INVERT)norminette$(WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

norme_all:
	@$(LMAKE) norme
	@$(LFPMAKE) norme
	@$(MAKE) norme

.PHONY: re fclean clean norme_all norme del pre debug debug_all STATUS
