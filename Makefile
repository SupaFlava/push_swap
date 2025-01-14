# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)

# Directories
SRCDIR = srcs
INCDIR = includes
LIBFT = $(LIBDIR)/libft.a
LIBDIR = libft

# Files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Output executable
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	make -C $(LIBDIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all
