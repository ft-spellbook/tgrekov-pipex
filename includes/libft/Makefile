NAME = libft.a
SOFT_NAME = libft
DEBUG_NAME = debug.out

STANDARD_CC = cc
STANDARD_FLAGS = -Wall -Wextra -Werror
DEBUG_CC = cc
DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

SRC_DIR = 
SRC_PATH_MANDATORY=
SRC_PATH_BONUS=
OBJ_DIR = objs/

SRC_NAMES =	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c

SRC_BONUS_NAMES =	ft_lstadd_back_bonus.c	\
					ft_lstadd_front_bonus.c	\
					ft_lstclear_bonus.c		\
					ft_lstdelone_bonus.c	\
					ft_lstiter_bonus.c		\
					ft_lstlast_bonus.c		\
					ft_lstmap_bonus.c		\
					ft_lstnew_bonus.c		\
					ft_lstsize_bonus.c		\
					get_next_line_bonus.c

HEADER_NAMES = libft.h get_next_line_bonus.h

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

.PHONY: all bonus \
debug_set debug debug_bonus \
clean .clean fclean re

$(OBJ_DIR)%.o \
$(OBJ_DIR)debug/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(CFLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf/ bonus
	@cp ft_printf/libftprintf.a $(NAME)
	@ar rcs $(NAME) $^
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Mandatory part done$(DEFAULT)"

.bonus: $(NAME) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@touch .bonus
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Bonus part done$(DEFAULT)"

bonus: .bonus

################################################################################

$(DEBUG_NAME): $(OBJS_DEBUG)
	@make -C ft_printf/ bonus
	@cp ft_printf/libftprintf.a $(NAME)
	@ar rcs $(NAME) $^
	@$(CC) $(CFLAGS) $(NAME) -o $(DEBUG_NAME)
	@touch .debug
	@echo "$(GREY)$(SOFT_NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Mandatory part done$(DEFAULT)"

debug_set:
	$(eval CC = $(DEBUG_CC))
	$(eval CFLAGS = $(DEBUG_FLAGS))

.debug: debug_set $(DEBUG_NAME)

debug: .debug

.debug_bonus: debug_set $(NAME) $(OBJS_DEBUG_BONUS)
	@$(CC) $(CFLAGS) $(NAME) -o $(DEBUG_NAME)
	@touch .debug_bonus
	@echo "$(GREY)$(SOFT_NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Bonus part done$(DEFAULT)"

debug_bonus: .debug_bonus

################################################################################

.clean:
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR), .bonus, .debug, and .debug_bonus"
	@rm -rf $(OBJ_DIR) .bonus .debug .debug_bonus

clean: .clean
	@make -C ft_printf/ clean

fclean: .clean
	@make -C ft_printf/ fclean
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME) and $(DEBUG_NAME)"
	@rm -rf $(NAME) $(DEBUG_NAME)

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
