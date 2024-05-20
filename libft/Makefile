.DEFAULT_GOAL: all
.DELETE_ON_ERROR:
.SUFFIXES:

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I./include

libft := libft.a
src := ./ctype/ft_atoi.c \
       ./ctype/ft_isalnum.c \
       ./ctype/ft_isalpha.c \
       ./ctype/ft_isascii.c \
       ./ctype/ft_isdigit.c \
       ./ctype/ft_isprint.c \
       ./ctype/ft_itoa.c \
       ./ft_printf/src/charformat_bonus.c \
       ./ft_printf/src/emit.c \
       ./ft_printf/src/ft_printf.c \
       ./ft_printf/src/ft_ulltoa.c \
       ./ft_printf/src/intformat_bonus.c \
       ./ft_printf/src/parse_bonus.c \
       ./ft_printf/src/strformat_bonus.c \
       ./ft_printf/src/uintformat_bonus.c \
       ./ft_printf/src/ptrformat.c \
       ./gnl/get_next_line.c \
       ./gnl/get_next_line_utils.c \
       ./io/ft_putchar_fd.c \
       ./io/ft_putendl_fd.c \
       ./io/ft_putnbr_fd.c \
       ./io/ft_putstr_fd.c \
       ./list/ft_lstadd_back.c \
       ./list/ft_lstadd_front.c \
       ./list/ft_lstclear.c \
       ./list/ft_lstdelone.c \
       ./list/ft_lstiter.c \
       ./list/ft_lstlast.c \
       ./list/ft_lstnew.c \
       ./list/ft_lstsize.c \
       ./mem/ft_bzero.c \
       ./mem/ft_calloc.c \
       ./mem/ft_memchr.c \
       ./mem/ft_memcmp.c \
       ./mem/ft_memcpy.c \
       ./mem/ft_memmove.c \
       ./mem/ft_memset.c \
       ./str/ft_split.c \
       ./str/ft_strchr.c \
       ./str/ft_strdup.c \
       ./str/ft_strndup.c \
       ./str/ft_striteri.c \
       ./str/ft_strjoin.c \
       ./str/ft_strlcat.c \
       ./str/ft_strlcpy.c \
       ./str/ft_strlen.c \
       ./str/ft_strmapi.c \
       ./str/ft_strncmp.c \
       ./str/ft_strnstr.c \
       ./str/ft_strrchr.c \
       ./str/ft_strtrim.c \
       ./str/ft_substr.c \
       ./str/ft_tolower.c \
       ./str/ft_toupper.c
obj_dir := ./obj
obj := $(src:%.c=$(obj_dir)/%.o)

$(obj_dir)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(libft): $(obj)
	ar rcs $@ $^

.PHONY: all
all: $(libft)

.PHONY: clean
clean:
	$(RM) $(obj)
	$(RM) $(obj:.o=.d)
	$(RM) -r $(obj_dir) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	$(RM) $(libft)

.PHONY: re
re: fclean all

-include $(client_objects:.o=.d) $(server_objects:.o=.d)
