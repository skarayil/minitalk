NAME = minitalk

CC = @cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_SRC = server.c utils.c
CLIENT_SRC = client.c utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

BONUS_SERVER_SRC = server_bonus.c utils_bonus.c
BONUS_CLIENT_SRC = client_bonus.c utils_bonus.c

BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

$(BONUS_SERVER): $(BONUS_SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_SERVER) $(BONUS_SERVER_OBJ)

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_CLIENT) $(BONUS_CLIENT_OBJ)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re
