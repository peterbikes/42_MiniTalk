SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
UTILS = utils/utils.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

SERVER_BONUS_SRC = server_bonus.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_SRC = client.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

CLIENT_BONUS_SRC = client_bonus.c

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(UTILS):
	make -C utils

$(SERVER): $(SERVER_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS) -o server

$(CLIENT): $(CLIENT_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS) -o client
	
$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(UTILS) -o server_bonus

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(UTILS) -o client_bonus

clean:
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	make clean -C utils

fclean:
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	make fclean -C utils
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re
