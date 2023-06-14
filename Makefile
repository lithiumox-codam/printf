CC = cc
SRC = printf.c utils.c put.c
# SRCS = $(addprefix src/, $(SRC))
OBJECTS = $(addprefix $(BUILDDIR)/, $(SRC:.c=.o))
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
BUILDDIR = build

all: $(NAME)

$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "\n\nCompilation completed for printf 🎉\n\n➤ ./$(NAME)"

init:
	@if [ ! -d $(LIBFT) ]; then \
		git clone git@github.com:LithiumOx/libft.git $(LIBFT); \
		echo "Libft cloned"; \
	fi

norm:
	@norminette $(addprefix src/, $(SRC))

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BUILDDIR)

re: fclean all

run: $(NAME)
	@gcc -fsanitize=address -Werror -Wall -Wextra -L. -lftprintf main.c  && ./a.out

.PHONY: all clean fclean re
