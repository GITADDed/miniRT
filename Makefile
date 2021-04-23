.PHONY: all clean fclean re

OBJ:= ./bin

SRC:= ./src

SRCS:= $(wildcard $(SRC)/*.c)

OBJS:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

MVOBJ = $(wildcard bin/*.o)

CC:= gcc

CFLAGS:= -Wall -Wextra -Werror -Iinclude

LIB:= -lmlx -lX11 -lXext -lm

NAME:= miniRT.exe

all:		$(NAME)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
			rm -rf $(MVOBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all