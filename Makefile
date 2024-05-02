NAME = pipex
AR_NAME = $(NAME).a
SOFT_NAME = pipex
DEBUG_NAME = debug.out
LIBFT_DIR = includes/libft/

STANDARD_CC = cc
STANDARD_FLAGS = -Wall -Wextra -Werror
DEBUG_CC = cc
DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

SRC_DIR = srcs/
SRC_PATH_MANDATORY=mandatory/
SRC_PATH_BONUS=bonus/
OBJ_DIR = objs/

SRC_NAMES =	main.c				\
			utils/arr_cut.c		\
			utils/arr_free.c	\
			utils/arr_has.c		\
			utils/arr_len.c		\
			utils/dedupe.c		\
			utils/err.c			\
			parent/dispatcher.c	\
			parent/get_paths.c	\
			parent/wait_all.c	\
			child/args_split.c	\
			child/dispatch.c	\
			child/get_cmd.c

SRC_BONUS_NAMES =	main.c				\
					parent/dispatcher.c	\
					parent/here_doc.c

#Make these actually do smth
HEADER_NAMES = utils/utils.h

HEADER_BONUS_NAMES =

################################################################################

CC = $(STANDARD_CC)
CFLAGS = $(STANDARD_FLAGS)

SRCS = $(addprefix $(SRC_DIR)$(SRC_PATH_MANDATORY), $(SRC_NAMES))
SRCS_BONUS = $(addprefix $(SRC_DIR)$(SRC_PATH_BONUS), $(SRC_BONUS_NAMES))

OBJS = $(SRC_NAMES:%.c=$(OBJ_DIR)$(SRC_PATH_MANDATORY)%.o)
OBJS_BONUS = $(SRC_BONUS_NAMES:%.c=$(OBJ_DIR)$(SRC_PATH_BONUS)%.o)

OBJS_DEBUG = $(SRC_NAMES:%.c=$(OBJ_DIR)debug/$(SRC_PATH_MANDATORY)%.o)
OBJS_DEBUG_BONUS = $(SRC_BONUS_NAMES:%.c=$(OBJ_DIR)debug/$(SRC_PATH_BONUS)%.o)

HEADERS = $(addprefix $(SRC_DIR)$(SRC_PATH_MANDATORY), $(HEADER_NAMES))
HEADERS_BONUS = $(addprefix $(SRC_DIR)$(SRC_PATH_BONUS), $(HEADER_BONUS_NAMES))

.PHONY: all bonus debug_set debug debug_bonus \
clean fclean re

$(OBJ_DIR)%.o \
$(OBJ_DIR)debug/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(CFLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

################################################################################

all: $(NAME)
	
$(NAME): $(AR_NAME)
	@$(CC) $(CFLAGS) $(AR_NAME) -o $(NAME)
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Mandatory executable done$(DEFAULT)"

$(AR_NAME): $(OBJS)
	@make -C $(LIBFT_DIR) bonus
	@cp $(LIBFT_DIR)libft.a $(AR_NAME)
	@ar rcs $(AR_NAME) $^
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Mandatory part done$(DEFAULT)"

.bonus: $(AR_NAME) $(OBJS_BONUS)
	@ar rcs $(AR_NAME) $(OBJS_BONUS)
	@touch .bonus
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Bonus part done$(DEFAULT)"

bonus: .bonus
	@$(CC) $(CFLAGS) $(AR_NAME) -o $(NAME)
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Bonus executable done$(DEFAULT)"

################################################################################

$(DEBUG_NAME): $(OBJS_DEBUG)
	@make -C $(LIBFT_DIR) bonus
	@cp $(LIBFT_DIR)libft.a $(AR_NAME)
	@ar rcs $(NAME) $^
	@$(CC) $(CFLAGS) $(AR_NAME) -o $(DEBUG_NAME)
	@touch .debug
	@echo "$(GREY)$(SOFT_NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Mandatory part done$(DEFAULT)"

debug_set:
	$(eval CC = $(DEBUG_CC))
	$(eval CFLAGS = $(DEBUG_FLAGS))

.debug: debug_set $(DEBUG_NAME)

debug: .debug

.debug_bonus: debug_set $(AR_NAME) $(OBJS_DEBUG_BONUS)
	@$(CC) $(CFLAGS) $(AR_NAME) -o $(DEBUG_NAME)
	@touch .debug_bonus
	@echo "$(GREY)$(SOFT_NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Bonus part done$(DEFAULT)"

debug_bonus: .debug_bonus

################################################################################

.clean:
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR), .bonus, .debug, and .debug_bonus"
	@rm -rf $(OBJ_DIR) .bonus .debug .debug_bonus

clean: .clean
	@make -C $(LIBFT_DIR) clean
	
fclean: .clean
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME), $(AR_NAME), and $(DEBUG_NAME)"
	@rm -rf $(NAME) $(AR_NAME) $(DEBUG_NAME)

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
