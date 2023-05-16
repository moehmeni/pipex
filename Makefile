# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 15:45:32 by mmomeni           #+#    #+#              #
#    Updated: 2023/05/14 21:46:58 by mmomeni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		pipex
CFLAGS=		-Wall -Wextra -Werror
FUNCS=		env.c system.c
SRCS=		main.c $(FUNCS)
LIBFT_DIR=	libft
LIBFT=		$(LIBFT_DIR)/libft.a

BONUS_DIR=	bonus
BONUS_NAME=	pipex
BONUS_SRCS=	$(BONUS_DIR)/pipex_bonus.c

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_NAME)
	$(CC) $(CFLAGS) $(FUNCS) $(BONUS_SRCS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

debug: CFLAGS += -fsanitize=address -g
debug: $(NAME)

.PHONY: all clean fclean re bonus
