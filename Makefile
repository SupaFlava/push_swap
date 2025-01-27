# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= includes/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g -I includes -I libft/includes
# Should *not* see -fsanitize=address

RM					= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)push_swap_commands/push.c \
						$(SRC_DIR)push_swap_commands/reverse_rotate.c \
						$(SRC_DIR)push_swap_commands/rotate.c \
						$(SRC_DIR)push_swap_commands/sort_stack.c \
						$(SRC_DIR)push_swap_commands/sort_three.c \
						$(SRC_DIR)push_swap_commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/error_handling.c \
						$(SRC_DIR)push_swap/initialize_a_to_b.c \
						$(SRC_DIR)push_swap/initialize_b_to_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/utils.c

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re