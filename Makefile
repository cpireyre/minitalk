.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.SUFFIXES:

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I./include/

applications := client server
src_dir := ./src
obj_dir := ./obj
client_sources := send.c client.c receive.c
client_objects := $(client_sources:%.c=$(obj_dir)/%.o)
server_sources := server.c receive.c
server_objects := $(server_sources:%.c=$(obj_dir)/%.o)

$(obj_dir)/%.o: $(src_dir)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

client: $(client_objects)
	$(CC) $(client_objects) -o $@

server: $(server_objects)
	$(CC) $(server_objects) -o $@

.PHONY: all
all: $(applications)

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

.PHONY: test
test: | all
	./test.sh

-include $(client_objects:.o=.d) $(server_objects:.o=.d)
