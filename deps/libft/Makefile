NAME = libft.a

SRC_DIR =
OBJ_DIR = obj/
PATH_MANDATORY =
PATH_BONUS =

SRC_NAMES_SHARED =	ft_atoi.c		\
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
SRC_NAMES_MANDATORY =
SRC_NAMES_BONUS =	ft_lstadd_back_bonus.c	\
					ft_lstadd_front_bonus.c	\
					ft_lstclear_bonus.c		\
					ft_lstdelone_bonus.c	\
					ft_lstiter_bonus.c		\
					ft_lstlast_bonus.c		\
					ft_lstmap_bonus.c		\
					ft_lstnew_bonus.c		\
					ft_lstsize_bonus.c		\
					get_next_line_bonus.c

CC = cc
FLAGS = -Wall -Wextra -Werror

################################################################################

OBJS_SHARED = $(SRC_NAMES_SHARED:%.c=$(OBJ_DIR)$(PATH_MANDATORY)%.o)
OBJS_MANDATORY = $(SRC_NAMES_MANDATORY:%.c=$(OBJ_DIR)$(PATH_MANDATORY)%.o)
OBJS_BONUS = $(SRC_NAMES_BONUS:%.c=$(OBJ_DIR)$(PATH_BONUS)%.o)

.PHONY: all bonus \
clean .clean fclean re

################################################################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################

all: $(NAME)

$(NAME): $(OBJS_SHARED) $(OBJS_MANDATORY)
	@make -C ft_printf bonus
	@cp ft_printf/libftprintf.a $(NAME)
	@ar rcs $(NAME) $^
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)Mandatory done$(DEFAULT)"

.bonus: $(OBJS_SHARED) $(OBJS_BONUS)
	@make -C ft_printf bonus
	@cp ft_printf/libftprintf.a $(NAME)
	@ar rcs $(NAME) $^
	@touch .bonus
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)Bonus done$(DEFAULT)"

bonus: .bonus

################################################################################

.clean:
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR) and .bonus"
	@rm -rf $(OBJ_DIR) .bonus

clean: .clean
	@make -C ft_printf clean
	
fclean: .clean
	@make -C ft_printf fclean
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
