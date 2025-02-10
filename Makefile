NAME				= push_swap

LIBFT				= ./libft/libft.a
INC					= includes/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g -I includes -I libft/includes -g

RM					= rm -f

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
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/utils.c \
						$(SRC_DIR)push_swap/free_handling.c \
						$(SRC_DIR)push_swap/parsing.c

SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJ 				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

start:				
					@make all
$(LIBFT):
					@make -C ./libft
all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

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

.PHONY: 			start all clean fclean re