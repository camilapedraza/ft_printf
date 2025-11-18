# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 17:45:39 by mpedraza          #+#    #+#              #
#    Updated: 2025/11/17 17:03:48 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I .
CPP_LIB_FLAGS := -L . -l:$(NAME) 
FTS := ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen \
	   ft_strlcpy ft_strlcat ft_strncmp ft_strchr ft_strrchr ft_strnstr \
	   ft_atoi ft_toupper ft_tolower ft_memset ft_bzero ft_memcpy ft_memmove \
	   ft_memchr ft_memcmp ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim \
	   ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd \
	   ft_putendl_fd ft_putnbr_fd
SRCS := $(FTS:%=%.c)
OBJS := $(SRCS:%.c=%.o)
BONUS := ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
		 ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
BONUS_SRCS := $(BONUS:%=%_bonus.c)
BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)
ALL_SRCS := $(SRCS) $(BONUS_SRCS)
ALL_OBJS := $(OBJS) $(BONUS_OBJS)
TESTNAME := test_libft
TEST_DIR := tests
TEST_SRCS := $(SRCS:%=$(TEST_DIR)/test_%)
TEST_OBJS := $(TEST_SRCS:%.c=%.o)
TEST_EXEC := $(TEST_DIR)/run_tests.sh
TEST_RUN := bash $(TEST_EXEC)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(ALL_OBJS)
	ar rcs $(NAME) $^

test: $(NAME) $(TEST_OBJS) $(TEST_EXEC)
	$(TEST_RUN)

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(CPP_LIB_FLAGS) -o $@
	@echo "./$@" >> $(TEST_EXEC)

$(TEST_DIR)/run_tests.sh: $(TEST_OBJS)
	touch $@

clean:
	$(RM) $(ALL_OBJS) $(TEST_OBJS) 

fclean: clean
	$(RM) $(NAME) $(TEST_EXEC)

re: fclean all

.PHONY: all clean fclean re test
