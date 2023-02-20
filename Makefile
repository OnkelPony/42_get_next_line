# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:16:40 by jimartin          #+#    #+#              #
#    Updated: 2023/02/18 14:59:21 by jimartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror --target=x86_64-apple-darwin-gnu
NAME = get_next_line
SRCFILES = get_next_line_utils.c get_next_line.c main.c
BONUS_SRCFILES = SRCFILES = get_next_line_utils_bonus.c get_next_line_bonus.c main_bonus.c

all: $(NAME)

$(NAME): $(SRCFILES) $(NAME).h
	$(CC) $(CFLAGS) $(SRCFILES) -o $(NAME)

bonus: $(NAME) $(BONUS_SRCFILES)
	ar rc libft.a $(BONUS_SRCFILES)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
