CC = cc
SRC = printf.c utils.c put.c
# SRCS = $(addprefix src/, $(SRC))
OBJECTS = $(addprefix $(BUILDDIR)/, $(SRC:.c=.o))
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
BUILDDIR = build

all: submodules $(NAME)

$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(NAME): $(OBJECTS)
	@if [ ! -f "./libft/libft.h" ]; then \
		$(MAKE) submodules; \
		ar rc $(NAME) $(OBJECTS); \
		echo "\n\nCompilation completed for printf 1 🎉\n\n➤ ./$(NAME)"; \
	else \
		ar rc $(NAME) $(OBJECTS); \
		echo "\n\nCompilation completed for printf 🎉\n\n➤ ./$(NAME)"; \
	fi

norm:
	@norminette $(addprefix src/, $(SRC))

clean:
	@rm -f $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BUILDDIR)
	@make fclean -C $(LIBFT)

re: fclean all

run: $(NAME)
	@gcc -fsanitize=address -Werror -Wall -Wextra -L. -lftprintf main.c  && ./a.out

submodules:
	echo "📥 Updating submodules..." \
	git submodule sync > /dev/null \
	git submodule update --init --recursive > /dev/null \
	echo "✅ Submodules updated!" \

.PHONY: all clean fclean re
