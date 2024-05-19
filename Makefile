.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.SUFFIXES:

:wa
CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
LDFLAGS := -I./include/

client := client
server := server
src_dir := ./src/
obj_dir := ./obj/
client_files := send.c client.c receive.c
server_files := server.c receive.c
client_src := $(addprefix $(src_dir), $(client_files))
client_obj := $(client_src:$(src_dir)%.c=$(obj_dir)%.o)
server_src := $(addprefix $(src_dir), $(server_files))
server_obj := $(server_src:$(src_dir)%.c=$(obj_dir)%.o)
obj_files := $(server_obj) $(client_obj)
dep_files := $(obj_files:.o=.d)

$(obj_dir)%.o: $(src_dir)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(client): $(client_obj)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(server): $(server_obj)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: all
all: $(client) $(server)

.PHONY: clean
clean:
	$(RM) $(obj_files) $(dep_files)
	rmdir $(obj_dir) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	$(RM) $(client)

.PHONY: re
re: fclean all

.PHONY: debug
target debug: CFLAGS += -g -fsanitize=address
debug: fclean all

.PHONY: run
run: all
	./$(server)

-include $(dep_files)
