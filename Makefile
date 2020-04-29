# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:30:28 by dderevyn          #+#    #+#              #
#    Updated: 2020/04/29 20:26:35 by acyrenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS_DIR = .objects
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

LIBFT_PATH = libft/
LIBFT_INCS =	libft.h
LIBFT_SRCS = 	ft_isdigit.c\
				ft_memalloc.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_pow.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strnchr.c\
				ft_strnew.c\
				ft_strrev.c\
				ft_strsub.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memcpy.c\
				ft_get_nb_size.c\
				ft_putstr.c\
				ft_putchar.c\
				ft_strtrim.c\
				ft_atoi.c\
				ft_isspace.c
LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(LIBFT_OBJS_DIR)/%.o)
LIBFT_OBJS_DIR = $(OBJS_DIR)

PRINTF_PATH = src/
PRINTF_INCS =	./inc/ft_printf.h
PRINTF_SRCS =	ft_itoa_base.c\
				ft_ltoa_base.c\
				write.c\
				flags.c\
				float.c\
				ft_printf.c\
				handle_chars.c\
				handle_number.c\
				modificators.c\
				parse.c\
				print.c\
				undefined.c\
				pointer.c
PRINTF_OBJS = $(PRINTF_SRCS:%.c=$(PRINTF_OBJS_DIR)/%.o)
PRINTF_OBJS_DIR = $(OBJS_DIR)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(LIBFT_PATH),$(LIBFT_INCS))) -o $@

$(PRINTF_OBJS_DIR)/%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(PRINTF_PATH),$(PRINTF_INCS))) -o $@

clean:
	make clean -C libft/
	$(RM) $(OBJS_DIR)
	$(RM) peda*
	$(RM) mod

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(addprefix $(LIBFT_PATH),$(LIBFT_SRCS)) \
	$(addprefix $(LIBFT_PATH),$(LIBFT_INCS)) \
	$(addprefix $(PRINTF_PATH),$(PRINTF_SRCS)) \
	$(PRINTF_INCS)

test: all
	@$(CC) -g src/* $(NAME) test/main.c -o mod
	@./mod

.PHONY: all clean fclean re norm test
