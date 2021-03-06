# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️$(WHITE)] $(NOP)
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=push_swap
CHECKER_NAME=checker

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INCDIR = includes

# Name
SRC_NAME = main.c \
			parsing/parser.c \
			elements/element_size.c \
			elements/get_element.c \
			elements/new_element.c \
			elements/clear_elements.c \
			operations/swap.c \
			operations/push.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			sorting/sort.c \
			sorting/pre_sort.c \
			utils/sorting_utils.c \
			utils/element_utils.c \
			utils/utils.c

CHECKER_SRCS = checker/checker.c \
			parsing/parser.c \
			elements/element_size.c \
			elements/get_element.c \
			elements/new_element.c \
			elements/clear_elements.c \
			operations/swap.c \
			operations/push.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			sorting/sort.c \
			sorting/pre_sort.c \
			utils/sorting_utils.c \
			utils/element_utils.c \
			utils/utils.c \
			../gnl/get_next_line.c \
			../gnl/get_next_line_utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CHECKER_OBJ_NAME = $(CHECKER_SRCS:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CHECKER_SRC = $(addprefix $(SRC_PATH)/, $(CHECKER_SRCS))
CHECKER_OBJ = $(addprefix $(OBJ_PATH), $(CHECKER_OBJ_NAME))

# Libft
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror


all: obj $(FT_LIB) $(NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/elements
	@mkdir -p $(OBJ_PATH)/sorting
	@mkdir -p $(OBJ_PATH)/operations
	@mkdir -p $(OBJ_PATH)/checker
	@mkdir -p $(OBJ_PATH)/utils
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@echo "$(INFO)Building libft library...$(NOC)"
	@make -C $(FT)
	@echo "$(SUCCESS)Libft library built successfully!$(NOC)"

$(NAME): $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

$(CHECKER_NAME): $(CHECKER_OBJ)
	@echo "$(INFO)Building $(CHECKER_NAME)...$(NOC)"
	@$(CC) $(CHECKER_OBJ) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(CHECKER_NAME) built successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting checker .o files...$(NOC)"
	@rm -rf $(CHECKER_OBJ_PATH)
	@echo "$(SUCCESS)Checker .o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"
	@make -C $(FT) fclean

re: fclean all