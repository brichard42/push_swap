# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/06/19 12:06:14 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = push_swap
NAME_C = checker

CC = gcc

CFLAGS = -Werror -Wall -Wextra

LDFLAGS = $(addprefix -L, $(LIB_PATH))

LDLIBS = $(subst lib, -l, $(LIB_PATH))

CPPFLAGS = -I$(INC_PATH)
CPPFLAGS_C = -I$(INC_PATH_C)

LIB_PATH = $(basename $(LIB_FILES))

INC_PATH = includes
INC_PATH_C = includes

SRCS_PATH = srcs

OBJS_PATH = .obj
OBJS_PATH_C = .obj_c

OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS_FILES_C = $(SRCS_FILES_C:.c=.o)

OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES))
OBJS_C = $(addprefix $(OBJS_PATH_C)/, $(OBJS_FILES_C))

LIBS = $(addprefix $(LIB_PATH)/, $(LIB_FILES))

INCS = $(addprefix $(INC_PATH)/, $(INC_FILES))
INCS_C = $(addprefix $(INC_PATH_C)/, $(INC_FILES_C))

CLEAN_LIB = $(addprefix && make clean -C , $(LIB_PATH))

FCLEAN_LIB = $(addprefix && make fclean -C , $(LIB_PATH))

################################################################################
#                                   LIB_FILES                                  #
################################################################################

LIB_FILES =		libft.a

################################################################################
#                                   INC_FILES                                  #
################################################################################

INC_FILES =		push_swap.h

INC_FILES_C =	checker.h

################################################################################
#                                   SRCS_FILES                                 #
################################################################################

SRCS_FILES =	push_swap.c \
				operators_s.c \
				operators_p.c \
				operators_r.c \
				operators_rr.c \
				slide.c \
				ps_op_tab.c \
				ps_parsing.c \
				print.c \
				ps_quicksort.c \
				ps_sort_case.c \
				ft_dlist.c \
				ps_save.c \
				ps_opti_inst.c \
				ps_opti_rr.c \

SRCS_FILES_C =	checker.c \
				operators_s.c \
				operators_p.c \
				operators_r.c \
				operators_rr.c \
				slide.c \
				ps_op_tab.c \
				ps_parsing.c \
				print.c \

################################################################################
#                                    COlORS                                    #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log 2> /dev/null; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

################################################################################
#                                   COMMANDS                                   #
################################################################################

.PHONY: all clean fclean re

all: $(NAME) $(NAME_C)

$(NAME): $(LIBS) $(OBJS)
	@$(call run_and_test, $(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJS))

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c  $(INCS) Makefile | $(OBJS_PATH)
	@$(call run_and_test, $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<)

$(OBJS_PATH):
	@$(call run_and_test, mkdir $@)

$(NAME_C): $(LIBS_C) $(OBJS_C)
	@$(call run_and_test, $(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJS_C))

$(OBJS_PATH_C)/%.o: $(SRCS_PATH)/%.c  $(INCS_C) Makefile | $(OBJS_PATH_C)
	@$(call run_and_test, $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<)

$(OBJS_PATH_C):
	@$(call run_and_test, mkdir $@)

$(LIBS):
	@echo "$(COM_COLOR)Compiling $(OBJ_COLOR)Libraries$(NO_COLOR)"
	@make -C $(LIB_PATH)

norme:
	@$(call run_and_test, norminette $(SRCS_PATH) $(INC_PATH) | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning')

lc:
	@$(call run_and_test, $(RM) $(D_OBJS) && rm -rf $(OBJS_PATH) $(CLEAN_LIB))

lfc:
	@$(call run_and_test, $(RM) $(D_OBJS) && rm -rf $(OBJS_PATH) && $(RM) $(NAME) $(FCLEAN_LIB))

clean:
	@$(call run_and_test, rm -rf $(OBJS_PATH) && rm -rf $(OBJS_PATH_C))

fclean: clean
	@$(call run_and_test, $(RM) $(NAME) && $(RM) $(NAME_C))

re: fclean all
