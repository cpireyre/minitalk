.DEFAULT_GOAL := all
.SUFFIXES:

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I./include/ -I./libft/include
libft_dir := ./libft/
libft := $(libft_dir)libft.a
LDFLAGS := -L$(libft_dir) -lft

applications := client server
src_dir := ./src
obj_dir := ./obj
client_sources := send.c client.c 
client_objects := $(client_sources:%.c=$(obj_dir)/%.o)
server_sources := server.c receive.c
server_objects := $(server_sources:%.c=$(obj_dir)/%.o)

$(libft):
	$(MAKE)  -C $(libft_dir)

$(obj_dir)/%.o: $(src_dir)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

client: $(libft) $(client_objects)
	$(CC) $(CFLAGS) $(LDFLAGS) $(client_objects) -o $@

server: $(libft) $(server_objects)
	$(CC) $(CFLAGS) $(LDFLAGS) $(server_objects) -o $@

.PHONY: all
all: $(applications)

.PHONY: bonus
bonus: $(applications)

.PHONY: clean
clean:
	$(RM) $(client_objects) $(server_objects)
	$(RM) $(client_objects:.o=.d) $(server_objects:.o=.d)
	@rmdir $(obj_dir) 2> /dev/null || true
	$(MAKE) -C $(libft_dir) clean

.PHONY: fclean
fclean: clean
	$(RM) $(applications)
	$(MAKE) -C $(libft_dir) fclean

.PHONY: re
re: fclean all

.PHONY: debug
debug: CFLAGS += -g -fsanitize=address -fsanitize=undefined
debug: all

-include $(client_objects:.o=.d) $(server_objects:.o=.d)
