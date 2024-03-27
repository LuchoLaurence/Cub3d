NAME = cub3D

SRCS =	srcs/main.c \
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
		srcs/graphism/init.c \
		srcs/graphism/events.c \
		srcs/graphism/utils.c \
		srcs/graphism/init_raycasting.c \
		srcs/graphism/key.c \
		srcs/graphism/key2.c \
		srcs/graphism/raycasting2.c \
		srcs/graphism/textures.c \
		srcs/graphism/init2.c

OBJS = $(addprefix objs/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(dir $(SRCS))

FLAGS = -Wall -Wextra -Werror

LIBS = -L /home/llaurenc/Documents/Cub3d/minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIBS) 

objs/%.o: %.c
	@mkdir -p objs
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f objs/*
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all
