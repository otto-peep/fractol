NAME = libft.a

FILES = ./ft_lastchr.c	\
	./ft_putnbrs.c	\
	./ft_putstrs.c	\
	./get_next_line.c \
	./ft_putchar.c	\
	./ft_putstr.c	\
	./ft_strdup.c	\
	./ft_strlen.c	\
	./ft_strcpy.c	\
	./ft_strncpy.c	\
	./ft_strclr.c	\
	./ft_striter.c	\
	./ft_putendl.c	\
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr.c	\
	./ft_putnbr_fd.c	\
	./ft_atoi.c		\
	./ft_memset.c	\
	./ft_bzero.c	\
	./ft_isalpha.c	\
	./ft_isdigit.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_strcat.c	\
	./ft_toupper.c	\
	./ft_tolower.c	\
	./ft_strncat.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strstr.c	\
	./ft_strnstr.c	\
	./ft_strcmp.c	\
	./ft_strncmp.c	\
	./ft_memcpy.c	\
	./ft_memccpy.c	\
	./ft_memalloc.c	\
	./ft_memdel.c	\
	./ft_strnew.c	\
	./ft_strdel.c	\
	./ft_strsub.c	\
	./ft_strjoin.c	\
	./ft_striteri.c	\
	./ft_strmap.c	\
	./ft_strmapi.c	\
	./ft_strequ.c	\
	./ft_strnequ.c	\
	./ft_strtrim.c	\
	./ft_memmove.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_itoa.c		\
	./ft_strsplit.c	\
	./ft_strlcat.c	\
	./ft_lstnew.c	\
	./ft_lstdelone.c	\
	./ft_lstdel.c	\
	./ft_lstadd.c	\
	./ft_lstiter.c	\
	./ft_lstmap.c	\
	./ft_isspace.c	\
	./ft_isblank.c	\
	./ft_isupper.c	\
	./ft_sqrt.c		\
	./ft_lstaddback.c	\
	./ft_printbits.c

SRCPATH = ./src/

SRC = $(FILES:%c=$(SRCPATH)%c)

OB = $(patsubst %.c,%.o,$(FILES))

HDER = ./libft.h

all: $(NAME)

$(NAME):
	@echo Compiling libft
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OB)
	@ranlib $(NAME)

clean:
	@echo Cleaning libft
	@rm -f $(OB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
