include configs/base.mk
include configs/flags.mk
include configs/os_dependency.mk
include configs/colors.mk

.PHONY: all multi $(LIBS_DIRS) STATUS_START
multi: $(LIBS_DIRS) STATUS_START
 ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(eval CFLAGS_OPTIONAL:=$(CFLAGS_DEBUG))
	@$(eval DEFINES:=$(shell echo $(basename $(NAME)) | tr a-z A-Z)_DEBUG)
 endif
 ifneq (,$(filter $(MAKECMDGOALS),sanitize sanitize_all))
	@$(eval CFLAGS_OPTIONAL:=$(CFLAGS_SANITIZE))
	@$(eval DEFINES:=$(shell echo $(basename $(NAME)) | tr a-z A-Z)_SANITIZE)
 endif
	@$(MAKE) -e $(MAKE_PARALLEL_FLAGS) all

STATUS_START:
	@$(ECHO) " | -------"
	@$(ECHO) " | making: $(CLR_UNDERLINE)$(NAME)$(CLR_WHITE) ..."
	@$(ECHO) " | -------"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(addprefix -D,$(DEFINES)) \
		$(IFLAGS) \
		$(OBJS) \
		$(CFLAGS) \
		$(CFLAGS_OPTIONAL) \
		$(CFLAGS_LIBS) \
		$(LIBS_NAMES) \
		-o $(NAME)
	@$(MAKE) STATUS

-include $(SRCS:.c=.d)
$(OBJS): %.o: %.c
	@$(CC) $(addprefix -D,$(DEFINES)) \
		$(CFLAGS) $(CFLAGS_OPTIONAL) $(IFLAGS) \
		-c $< -o $@
	@$(ECHO) " | $@: $(MSG_SUCCESS)"

$(LIBS_DIRS):
 ifeq (,$(filter $(MAKECMDGOALS), pre debug))
	$(MAKE) -C $@ $(MAKECMDGOALS)
 endif

STATUS:
	@$(ECHO) "/ -------------------------"
 ifneq (,$(NAME))
	@$(ECHO) "| compiled                : $(NAME) $(MSG_SUCCESS)"
 endif
 ifneq (,$(CC))
	@$(ECHO) "| compiler                : $(CC)"
 endif
 ifneq (,$(DEFINES))
	@$(ECHO) "| compiler custom defines : $(foreach dfns,$(DEFINES),$(CLR_INVERT)$(dfns)$(CLR_WHITE) )"
 endif
 ifneq (,$(CFLAGS))
	@$(ECHO) "| compiler          flags : $(CFLAGS)"
 endif
 ifneq (,$(CFLAGS_OPTIONAL))
	@$(ECHO) "| compiler optional flags : $(CLR_UNDERLINE)$(CFLAGS_OPTIONAL)$(CLR_WHITE)"
 endif
	@$(ECHO) "\\ -------------------------"

debug_all: pre
debug: multi

sanitize_all: pre
sanitize: multi

clean_deps:
	@$(DEL) $(OBJS:%.o=%.d)
clean: $(LIBS_DIRS) clean_deps
	@$(DEL) $(OBJS)
	@$(ECHO) " | $(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD) source objects"
fclean: clean $(LIBS_DIRS)
	@$(DEL) $(NAME)
	@$(ECHO) " | $(CLR_INVERT)deleted$(CLR_WHITE): $(NPWD)"

del:
	@$(DEL) $(OBJS)
	@$(DEL) $(NAME)
del_libs:
	@$(DEL) $(LIBS_NAMES)

pre: del multi
re: fclean multi

norme:
	@$(ECHO) "$(CLR_INVERT)norminette$(CLR_WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

norme_all: $(LIBS_DIRS)
	@$(ECHO) "$(CLR_INVERT)norminette$(CLR_WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean clean_deps norme norme_all del pre sanitize sanitize_all debug debug_all STATUS
.EXPORT_ALL_VARIABLES:
