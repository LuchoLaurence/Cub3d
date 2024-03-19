NAME = cub3D

SRCS =	srcs/main.c \
		srcs/graphism/events.c \
		srcs/graphism/events2.c \
		srcs/graphism/utils.c \
		srcs/graphism/inits.c \
		srcs/graphism/inits2.c \
		srcs/graphism/raycast.c \
		srcs/graphism/raycast2.c \
		srcs/graphism/floor_ceiling.c \
		srcs/parsing/checks.c \
		srcs/parsing/checks2.c \
		srcs/parsing/gnl.c \
		srcs/parsing/gnl2.c \
		srcs/parsing/lib1.c \
		srcs/parsing/verif.c \
		srcs/parsing/add_data.c \
		srcs/parsing/add_data2.c \
		srcs/parsing/check_map.c \
		srcs/parsing/add_map.c \

OBJS = $(addprefix objs/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(dir $(SRCS))

HEADERS = -I ./includes -I /usr/X11/include

FLAGS = -Wall -Wextra -Werror

LIBS = -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(HEADERS) $(FLAGS) -O3 -o $(NAME) $(OBJS) $(LIBS) 

objs/%.o: %.c
	@mkdir -p objs
	gcc $(HEADERS) $(FLAGS) -c $< -o $@

clean:
	rm -f objs/*

fclean: clean
	rm -f $(NAME)

re: fclean all
