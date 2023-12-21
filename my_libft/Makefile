# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 08:41:33 by malena-b          #+#    #+#              #
#    Updated: 2023/12/21 09:10:35 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c \
		ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c
GNL = get_next_line.c get_next_line_utils.c get_next_line_bonus.c

PRINTF = ft_printchar.c ft_printdecimal.c ft_printf.c ft_printhex.c ft_printstr.c ft_printunsint.c

OBJECTS = $(SOURCE:.c=.o)

BOBJECTS = $(BONUS:.c=.o)

GNLOBJECTS = $(GNL:.c=.o)

PRINTFOBJECTS = $(PRINTF:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
EC=\033[0m

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "$(BLUE)Libft/Base_code:    	$(GREEN)[COMPILED]$(EC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) bonus gnl ptf

clean:
	@rm -f $(OBJECTS) $(BOBJECTS) $(GNLOBJECTS) $(PRINTFOBJECTS)
	@echo "$(YELLOW)Libft clean:       	$(GREEN)[COMPLETED]$(EC)"

fclean: clean
	@rm -f $(NAME) clean
	@echo "$(YELLOW)Libft fclean:      	$(GREEN)[COMPLETED]$(EC)"

re: fclean all

bonus: $(BOBJECTS)
	@ar rcs $(NAME) $(BOBJECTS)
	@echo "$(BLUE)Libft/Bonus:       	$(GREEN)[COMPILED]$(EC)"

gnl: $(GNLOBJECTS)
	@ar rcs $(NAME) $(GNLOBJECTS)
	@echo "$(BLUE)Libft/Get_next_line:	$(GREEN)[COMPILED]$(EC)"

ptf: $(PRINTFOBJECTS)
	@ar rcs $(NAME) $(PRINTFOBJECTS)
	@echo "$(BLUE)Libft/Printf:       	$(GREEN)[COMPILED]$(EC)"

.PHONY: all clean fclean re bonus gnl ptf