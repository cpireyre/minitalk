.DEFAULT_GOAL := all
.SUFFIXES:

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I./include/

applications := client server
src_dir := ./src
obj_dir := ./obj
client_sources := send.c client.c 
client_objects := $(client_sources:%.c=$(obj_dir)/%.o)
server_sources := server.c receive.c
server_objects := $(server_sources:%.c=$(obj_dir)/%.o)

$(obj_dir)/%.o: $(src_dir)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

client: $(client_objects)
	$(CC) $(CFLAGS) $(client_objects) -o $@

server: $(server_objects)
	$(CC) $(CFLAGS) $(server_objects) -o $@

.PHONY: all
all: $(applications)

.PHONY: bonus
bonus: $(applications)

.PHONY: clean
clean:
	$(RM) $(client_objects) $(server_objects)
	$(RM) $(client_objects:.o=.d) $(server_objects:.o=.d)
	@rmdir $(obj_dir) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	$(RM) $(applications)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CFLAGS += -g -fsanitize=address -fsanitize=undefined
debug: all

-include $(client_objects:.o=.d) $(server_objects:.o=.d)
