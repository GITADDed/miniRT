NAME		= miniRT

SRC			= srcs/set_5.c \
              srcs/intersection.c \
              srcs/cylinder_intersection.c \
              srcs/init.c \
              srcs/light_and_shadows.c \
              srcs/main.c \
              srcs/map_errors.c \
              srcs/parser.c \
              srcs/plane_intersection.c \
              srcs/rendering.c \
              srcs/screen_shot.c \
              srcs/set_2.c \
              srcs/set.c \
              srcs/set_3.c \
              srcs/set_4.c \
              srcs/set_6.c \
              srcs/sphere_intersection.c \
              srcs/square_intersection.c \
              srcs/triangle_intersection.c \
              srcs/utils.c \
              srcs/utils_2.c \
              srcs/utils_3.c \
              gnl/get_next_line.c \
              libft/ft_lstadd_front.c \
              libft/ft_lstnew.c \
              srcs/hooks.c

HEADER		= srcs/minirt.h

OBJS		= ${SRC:.c=.o}

LIBFT		= make all -C libft

FLAGS		= -Wall -Wextra -Werror -g

FRAMEWORKS	= -lmlx -lX11 -lXext -lm

RM			= rm -f

all:	${NAME}

.c.o:
		gcc ${FLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${HEADER}
		${LIBFT}
		make bonus -C libft
		gcc ${FLAGS} ${OBJS} -o ${NAME} -L. -I. libft/libft.a ${FRAMEWORKS}

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft
re:		fclean all

.PHONY:		re all clean fclean
