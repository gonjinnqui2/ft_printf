SRCS = 	\
		flags.c \
		float.c \
		ft_printf.c \
		handle_number.c \
		handle_chars.c \
		modificators.c \
		parse.c \
		pointer.c

UTILS = write.c \
		ft_itoa_base.c \
		ft_ltoa_base.c

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra

OBJECTSFOLD = ./objs
UTILSFOLD = ./utils
SRCSFOLD = ./src

SOBJECTFILES = $(SRCS:.c=.o)
UOBJECTFILES = $(UTILS:.c=.o)
SOBJECTS = $(patsubst %.o, $(OBJECTSFOLD)/%.o, $(SOBJECTFILES))
UOBJECTS = $(patsubst %.o, $(OBJECTSFOLD)/%.o, $(UOBJECTFILES))

all: $(NAME)

$(NAME): $(OBJECTSFOLD) $(UOBJECTS) $(SOBJECTS)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar rc $(NAME) $(SOBJECTS) $(UOBJECTS)
	ranlib $(NAME)

$(OBJECTSFOLD)/%.o: $(UTILSFOLD)/%.c
	gcc -c $^ -Iinc/ -o $@

$(OBJECTSFOLD)/%.o: $(SRCSFOLD)/%.c
	gcc -c $^ -Iinc/ -o $@

$(OBJECTSFOLD):
	mkdir $(OBJECTSFOLD)

clean:
	rm -rf $(OBJECTSFOLD)

fclean: clean
	rm -f $(NAME)

re: fclean all
