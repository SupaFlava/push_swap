CFLAGS = -Wall - Wextra -Werror -I $(LIBFT_DIR)
AR = ar
LIBFT_DIR = ./libft
NAME = libftprintf.a
INCLUDES = -I includes
SRC = push_swap.c
OBJ = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) rcs $(NAME) $(OBJ) $(LIBFT)
%.o: %.c
	echo "Compiling $<"
	cc $(CFLAGS) $(INLCUDES) -C $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -c $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re