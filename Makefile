SERVER := server
CLIENT := client

$(SERVER): ./src/server.c
	$(CC) $(CFLAGS) $< -o $@

$(CLIENT): ./src/client.c
	$(CC) $(CFLAGS) $< -o $@

all: $(SERVER) $(CLIENT)

bonus: all

.PHONY: fclean
fclean:
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

.PHONY: re
re: fclean all
