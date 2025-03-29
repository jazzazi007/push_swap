CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libftprintf.a



# Source files
SRCS = ft_decm.c ft_hexnum.c ft_hexnum_upper.c ft_p_itoa.c ft_printf.c ft_ptr.c ft_p_putchar_fd.c \
		ft_p_putstr_fd.c ft_p_strlen.c ft_udecm.c ft_p_numlen.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Rule to create the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean all generated files
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# Rule to build all
all: $(NAME)

.PHONY: all clean fclean re