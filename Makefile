# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:57:36 by pleander          #+#    #+#              #
#    Updated: 2024/05/15 15:20:12 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CFILES := ft_printf.c ft_utoa_base.c handlers.c handlers2.c

LIBFT := libft/libft.a

OBJECTS := $(CFILES:.c=.o)

BONUS_CFILES := ft_printf_bonus.c \
	ft_utoa_base_bonus.c \
	conversions_bonus.c \
	parse_conversion_bonus.c \
	precision_bonus.c \
	printers_bonus.c \
	utils_bonus.c \
	plus_bonus.c \
	poundsign_bonus.c \
	field_width_bonus.c \
	space_bonus.c

BONUS_OBJECTS := $(BONUS_CFILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)
	rm -f .bonus
	make clean -C libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJECTS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJECTS)
	touch .bonus
