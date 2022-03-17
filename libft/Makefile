# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:49:17 by dcorenti          #+#    #+#              #
#    Updated: 2022/02/27 18:12:00 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CO_RED			= \033[1;31m
CO_GREEN		= \033[1;32m
CO_YELLOW		= \033[1;33m
CO_BLUE			= \033[1;34m
CO_WHITE_IT		= \033[7;37m
CO_DEFAULT		= \033[0m

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
				ft_itoa_hexa.c ft_itoa_unsigned.c ft_print_char.c ft_print_hexa.c ft_print_int.c ft_print_pointer.c ft_print_pourcent.c ft_print_string.c ft_print_unsigned_int.c ft_print_var.c ft_printf.c \
				ft_realloc.c ft_utils.c

OBJS		= $(SRCS:.c=.o)


${NAME}:	${OBJS}
			@printf "\033[1;33m"
			ar rc ${NAME} ${OBJS}
			@printf "${CO_GREEN} \"${NAME}\" successfully build!${CO_DEFAULT}\n"

all:		${NAME}

clean:
			/bin/${RM} ${OBJS}
			@printf "${CO_RED}'.o' files deleted successfully${CO_DEFAULT}\n"


fclean:		clean
			/bin/rm -f ${NAME}
			@printf "\033[1;31m ${NAME} file deleted successfully\e[0m\n"

re:			fclean all

help:
			@printf "\tUSAGE:\tUse ${CO_WHITE_IT}make${CO_DEFAULT} command with ${CO_BLUE}OPTIONS${CO_DEFAULT} (default is all)\n"
			@printf "\tOPTIONS:\n"
			@printf "\t\t${CO_BLUE}all${CO_DEFAULT}:\tcreate the library\n"
			@printf "\t\t${CO_BLUE}clean${CO_DEFAULT}:\tdelete all '.o' files\n"
			@printf "\t\t${CO_BLUE}fclean${CO_DEFAULT}:\tclean and delete the library\n"
			@printf "\t\t${CO_BLUE}re${CO_DEFAULT}:\tfclean and all\n"
			@printf "\t\t${CO_BLUE}help${CO_DEFAULT}:\tdisplay help\n"

.PHONY:		clean fclean re all help
