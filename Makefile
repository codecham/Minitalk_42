# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 03:23:11 by dcorenti          #+#    #+#              #
#    Updated: 2022/03/04 04:52:54 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CO_RED			= \033[1;31m
CO_GREEN		= \033[1;32m
CO_YELLOW		= \033[1;33m
CO_BLUE			= \033[1;34m
CO_WHITE_IT		= \033[7;37m
CO_DEFAULT		= \033[0m

LIBFT 				= ./libft/libft.a

NAME				=	minitalk
NAME_BONUS			=	minitalk_bonus
NAME_CLIENT 		= 	client
NAME_CLIENT_BONUS 	= 	client_bonus

NAME_SERVER 		= 	server
NAME_SERVER_BONUS 	= 	server_bonus

SRCS_CLIENT			=	client.c
SRCS_CLIENT_BONUS	=	client_bonus.c

SRCS_SERVER 		=	server.c \
						server_utils.c
SRCS_SERVER_BONUS 	=	server_bonus.c \
						server_utils_bonus.c
CC 					= gcc

FLAGS 				= -Wall -Wextra -Werror

INCLUDES 			= -I./includes

OBJS_CLIENT 		= ${SRCS_CLIENT:.c=.o}
OBJS_CLIENT_BONUS 	= ${SRCS_CLIENT_BONUS:.c=.o}

OBJS_SERVER 		= $(SRCS_SERVER:.c=.o)
OBJS_SERVER_BONUS 	= $(SRCS_SERVER_BONUS:.c=.o)

$(NAME): $(OBJS_CLIENT) ${OBJS_SERVER}
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS_CLIENT)  -o $(NAME_CLIENT)
	@printf "${CO_GREEN} ${NAME_CLIENT} successfully build!${CO_DEFAULT}\n"
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS_SERVER)  -o $(NAME_SERVER)
	@printf "${CO_GREEN} ${NAME_SERVER} successfully build!${CO_DEFAULT}\n"


$(NAME_BONUS): $(OBJS_CLIENT_BONUS) ${OBJS_SERVER_BONUS}
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS_CLIENT_BONUS)  -o $(NAME_CLIENT_BONUS)
	@printf "${CO_GREEN} ${NAME_CLIENT_BONUS} successfully build!${CO_DEFAULT}\n"
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS_SERVER_BONUS)  -o $(NAME_SERVER_BONUS)
	@printf "${CO_GREEN} ${NAME_SERVER_BONUS} successfully build!${CO_DEFAULT}\n"

all : $(NAME)

bonus : ${NAME_BONUS}

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS_SERVER) ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}
	@printf "${CO_RED} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS} successfully deleted${CO_DEFAULT}"

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@printf "${CO_RED} ${NAME_CLIENT} ${NAME_SERVER} ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS} successfully deleted${CO_DEFAULT}"

re : fclean all

.PHONY: all clean fclean re
