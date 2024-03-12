# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 11:54:25 by dodordev          #+#    #+#              #
#    Updated: 2024/03/12 16:25:01 by dodordev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I include/

RM = rm -f

CYAN = \033[0;1;3;36m
GREEN = \033[0;1;32m
RED = \033[0;1;31m
BLUE = \033[0;34m
ECEND = \033[0m

SRC_SRV = src/server.c

SRC_CLIENT = src/client.c

CLIENT = client

SERVER = server

SRC_HELPERS = src/helpers.c

HELPERS = helpers.o

SRC_SRV_BONUS = src_bonus/server_bonus.c

SRC_CLIENT_BONUS = src_bonus/client_bonus.c

SRC_HELPERS_BONUS = src_bonus/helpers_bonus.c

HELPERS_BONUS = helpers_bonus.o

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(HELPERS): $(SRC_HELPERS)
	@$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled"

$(CLIENT): $(SRC_CLIENT) $(HELPERS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_CLIENT) $(HELPERS) -o $(CLIENT)
	@echo "$(CYAN)$(CLIENT) $(BLUE)successfully created!$(ECEND)"

$(SERVER): $(SRC_SRV) $(HELPERS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_SRV) $(HELPERS) -o $(SERVER)
	@echo "$(CYAN)$(SERVER) $(BLUE)successfully created!$(ECEND)"

bonus: all $(CLIENT_BONUS) $(SERVER_BONUS)

$(HELPERS_BONUS): $(SRC_HELPERS_BONUS)
	@$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled"

$(CLIENT_BONUS): $(SRC_CLIENT_BONUS) $(HELPERS_BONUS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_CLIENT_BONUS) $(HELPERS_BONUS) -o $(CLIENT_BONUS)
	@echo "$(CYAN)$(CLIENT_BONUS) $(BLUE)successfully created!$(ECEND)"

$(SERVER_BONUS): $(SRC_SRV_BONUS) $(HELPERS_BONUS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_SRV_BONUS) $(HELPERS_BONUS) -o $(SERVER_BONUS)
	@echo "$(CYAN)$(SERVER_BONUS) $(BLUE)successfully created!$(ECEND)"

clean:
	@$(RM)  $(HELPERS) $(HELPERS_BONUS)
	@echo "$(RED)helpers objs deleted $(ECEND)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(RED)$(NAME) $(BLUE)successfully deleted$(ECEND)"

re: fclean all

.PHONY: all bonus clean fclean re