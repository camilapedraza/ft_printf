# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 16:52:21 by mpedraza          #+#    #+#              #
#    Updated: 2025/11/18 18:48:55 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I libft
#LDFLAGS := -L . /$(LIBFT_DIR)
#LDLIBS := -l:$(LIBFT)

FTS := ft_printf
SRCS := $(FTS:%=%.c)
OBJS := $(SRCS:%.c=%.o)

LIBFT := libft.a
LIBFT_DIR = libft

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	ar rcs $@ $^

$(LIBFT_DIR)/$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_DIR)/*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re test



