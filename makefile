# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 10:00:18 by mhirch            #+#    #+#              #
#    Updated: 2023/01/28 15:05:32 by mhirch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER_NAME = server

CLIENT_NAME = client

CC = gcc

HEADER = minitalk.h

CFLAGS = -Wall -Wextra -Werror

SOURCES =	minitalk_utils.c

OBJECTS = $(SOURCES:.c=.o) 


all:$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : server.c $(HEADER)
	 		$(CC) $(CFLAGS) server.c $(SOURCES) -o server
$(CLIENT_NAME) : client.c $(HEADER)
			$(CC) $(CFLAGS) client.c $(SOURCES) -o client
clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all