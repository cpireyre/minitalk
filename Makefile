CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -I./include/
SERVER := server
CLIENT := client

.PHONY: all
all: $(SERVER) $(CLIENT)

$(SERVER): ./src/server.c
	$(CC) $(CFLAGS) $< -o $@

$(CLIENT): ./src/client.c
	$(CC) $(CFLAGS) $< -o $@

target bonus: CFLAGS += -DBONUS=1
.PHONY: bonus
bonus: all

.PHONY: clean
clean:

.PHONY: fclean
fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

.PHONY: re
re: fclean all
