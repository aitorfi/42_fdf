CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = $(SRC:.c=.o)
BONUS_SRC = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS = $(BONUS_SRC:.c=.o)
GNL_SRC = gnl/get_next_line.c gnl/get_next_line_bonus.c
GNL_OBJS = $(GNL_SRC:.c=.o)
PRINTF_SRC = \
	ft_printf/ft_printf_chars.c ft_printf/ft_printf_hex.c \
	ft_printf/ft_printf_nums.c ft_printf/ft_printf.c ft_printf/utils_chars.c \
	ft_printf/utils_flags.c ft_printf/utils_hex.c ft_printf/utils_nums.c \
	ft_printf/utils_padding.c
PRINTF_OBJS = $(PRINTF_SRC:.c=.o)
LIB_GEN_CMD = ar -crs
RM = rm -f
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB_GEN_CMD) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(LIB_GEN_CMD) $(NAME) $(OBJS) $(BONUS_OBJS)

improved: $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	$(LIB_GEN_CMD) $(NAME) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
