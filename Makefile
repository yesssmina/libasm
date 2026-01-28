NAME = libasm.a

SRC = ft_strlen.s \
      ft_strcpy.s \
      ft_strcmp.s \
      ft_write.s \
      ft_read.s \
      ft_strdup.s

OBJ = $(SRC:.s=.o)

NASM = nasm
NFLAGS = -f elf64

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

test: all
	gcc -o test main.c libasm.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test
