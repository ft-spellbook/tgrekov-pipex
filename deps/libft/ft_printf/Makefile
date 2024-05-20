NAME = libftprintf.a

SRC_DIR = srcs
OBJ_DIR = obj
PATH_MANDATORY = mandatory
PATH_BONUS = bonus

SRC_NAMES_SHARED =	ft_printf.c			\
					utils/wrap_err.c
SRC_NAMES_MANDATORY =	utils/u_len_base.c				\
						utils/u_put_base.c				\
						conversion/handle_sequence.c	\
						conversion/identify_sequence.c	\
						conversion/handlers/char.c		\
						conversion/handlers/int.c		\
						conversion/handlers/percent.c	\
						conversion/handlers/pointer.c	\
						conversion/handlers/string.c	\
						conversion/handlers/uhex.c		\
						conversion/handlers/uint.c
SRC_NAMES_BONUS =	utils/repeat_str_n.c						\
					utils/u_len_base.c							\
					utils/u_put_base.c							\
					conversion/handle_sequence.c				\
					conversion/identify_sequence.c				\
					conversion/parse_subspec.c					\
					conversion/handlers/char.c					\
					conversion/handlers/int.c					\
					conversion/handlers/percent.c				\
					conversion/handlers/pointer.c				\
					conversion/handlers/set_fd.c				\
					conversion/handlers/store.c					\
					conversion/handlers/string.c				\
					conversion/handlers/uhex.c					\
					conversion/handlers/uint.c					\
					conversion/handlers/uoct.c					\
					conversion/handlers/utils/unsigned_arg.c	\
					conversion/handlers/utils/u_print_base.c

CC = cc
FLAGS = -Wall -Wextra -Werror

################################################################################

OBJS_SHARED = $(SRC_NAMES_SHARED:%.c=$(OBJ_DIR)/$(PATH_MANDATORY)/%.o)
OBJS_MANDATORY = $(SRC_NAMES_MANDATORY:%.c=$(OBJ_DIR)/$(PATH_MANDATORY)/%.o)
OBJS_BONUS = $(SRC_NAMES_BONUS:%.c=$(OBJ_DIR)/$(PATH_BONUS)/%.o)

.PHONY: all bonus \
clean fclean re

################################################################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################

all: $(NAME)

$(NAME): $(OBJS_SHARED) $(OBJS_MANDATORY)
	@ar rcs $(NAME) $^
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)Mandatory done$(DEFAULT)"

.bonus: $(OBJS_SHARED) $(OBJS_BONUS)
	@ar rcs $(NAME) $^
	@touch .bonus
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)Bonus done$(DEFAULT)"

bonus: .bonus

################################################################################

clean:
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR) and .bonus"
	@rm -rf $(OBJ_DIR) .bonus
	
fclean: clean
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME)"
	@rm -f $(NAME)

re: fclean all

################################################################################

GREEN = \033[38;5;84m
RED = \033[38;5;9m
BLUE = \033[38;5;45m
#PURPLE = \033[38;5;63m
PINK = \033[38;5;207m
PURPLE = \033[38;5;165m
BLACK = \033[38;5;0m
BG_WHITE = \033[48;5;15m
BG_GREEN = \033[48;5;84m
BG_RED = \033[48;5;9m
BG_PURPLE = \033[48;5;54m
GREY = \033[38;5;8m
BOLD = \033[1m
DEFAULT = \033[0m
CHECKMARK = \xE2\x9C\x93
