# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 10:00:18 by mhirch            #+#    #+#              #
#    Updated: 2023/01/31 15:17:50 by mhirch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER_NAME = server

CLIENT_NAME = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

SOURCES = minitalk_utils.c

HEADER_BONUS = minitalk_bonus.h

SOURCES_BONUS = minitalk_utils_bonus.c

OBJECTS = 

OBJECTS_BONUS = 

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : server.c $(HEADER)
	 		$(CC) $(CFLAGS) server.c $(SOURCES) -o server

$(CLIENT_NAME) : client.c $(HEADER)
			$(CC) $(CFLAGS) client.c $(SOURCES) -o client

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : server_bonus.c $(HEADER_BONUS)
	 		$(CC) $(CFLAGS) server_bonus.c $(SOURCES_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c $(HEADER_BONUS)
			$(CC) $(CFLAGS) client_bonus.c $(SOURCES_BONUS) -o $(CLIENT_BONUS)

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
