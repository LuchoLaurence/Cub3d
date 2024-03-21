/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:26:46 by fabperei          #+#    #+#             */
/*   Updated: 2024/03/21 15:15:31 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH 1400
# define HEIGHT 700
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define BUFFER_SIZE 1000

# define ESC 65307
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD 119
# define BACK 115
# define RIGHT 100
# define LEFT 97

typedef struct s_Mlxdata
{
	void			*mlx;
	void			*win;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	*img_addr;
}					t_mlxdatas;

typedef struct s_CoordonatesCharacter
{
	int				x;
	int				y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			raydir_x;
	double			raydir_y;
	double			plane_x;
	double			plane_y;
	double			map_x;
	double			map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			facedist_x;
	double			facedist_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	int				drawstart;
	int				drawend;
	double			move_speed;
	double			rot_speed;
	int				line_height;
	double			perp_wall_dist;
	double			camera_x;
	int				hit;
	int				side;
	double			olddir_x;
	double			oldplane_x;
	unsigned int	color_text;
	char			orientation;
}					t_CoordonatesCharacter;

typedef struct s_texture
{
	int				tex_num;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	unsigned int	color;
	void			*img[4];
	int				*img_data[4];
}					t_texture;

typedef struct s_Floor
{
	int		x;
	int		y;
	float	raydir_x0;
	float	raydir_y0;
	float	raydir_x1;
	float	raydir_y1;
	int		p;
	float	pos_z;
	float	row_distance;
	float	floorstep_x;
	float	floorstep_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
	int		tx;
	int		ty;
	int		checkerboardpattern;
	int		floortexture;
	int		ceilingtexture;
}	t_floor;

typedef struct s_map
{
	int		line_nb;
	int		map_line2;
	int		index_end;
	int		index_start;
	int		index1;
	int		index2;
	int		long_map;
	int		color_line;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	int		player_x;
	int		player_y;
	char	**map;
	int		x;
	int		player;
	int		path_nb;
	int		mapheight;
	int		mapwith;
}	t_map;

typedef struct s_all
{
	t_mlxdatas				mlxdatas;
	t_CoordonatesCharacter	c;
	t_texture				texture;
	t_floor					floor;
	t_map					map;
}							t_all;

typedef struct s_index_vars
{
	int		fd3;
	char	*line;
	int		i;
	int		index;
}					t_index_vars;

int					check(int argc, char **argv, t_all *a);
int					check2(int argc, char **argv);
int					check3(t_all *a);
void				check4(t_all *a);
int					verif_cub(char *argv);
int					is_file_empty(char *file);
int					verif_isnt_directory(char *argv);
void				open_and_add_data(char **argv, t_all *a);
void				index_first_line(char **argv, t_all *a);
void				add_path_direction(char *line, t_all *a);
void				add_path_direction2(char *line, t_all *a);
void				set_texture_path(char **dest, char *src, t_all *a);
void				add_color(char *line, t_all *a);
void				add_color_floor(char *line, t_all *a);
void				add_color_ceilling(char *line, t_all *a);
void				add_map(char *line, t_all *a);
int					verif_xpm(char *file, t_all *a);
void				check_line(char *line, int map_line);
void				check_1_first_line(char *line);
void				check_1_start_line(char *line);
void				check_1_end_line(char *line);
int					line_is_map(char *line);
int					line_is_map2(char *line);
void				create_map(t_all *a);
void				create_map2(char line, int i, t_all *a);
int					map_height(char **argv, t_all *a);
void				free_map(t_all *a);
void				free_map2(t_all *a);
void				init_map_data(t_all *a);
int					ft_line_empty(char *line);
void				error_print(char *temp, t_all *a);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc_bzero(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *string, int searchedChar);
char				*ft_strjoin(char const *s1, char const *s2);
char				*get_right(char *all_line);
char				*get_left(char *all_line);
char				*recup_the_total_row(int fd, char *buf, char *stack);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*get_next_line(int fd);
char				*ft_strdup(const char *string);
int					ft_strchr_count(char *s, int c);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_strchr_xpm(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
t_index_vars		init_index_vars(char **argv);
void				mlx_begin(t_all *a);
void				my_mlx_pixel_put(t_all *a, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);
void				print_c_and_f(t_all *a);
void				init_raytracing(t_all *a);
void				init_player(t_all *a);
void				print_textures(t_all *a);
void				ft_verline(t_all *a, int x, int color);
int					ft_key_pressed(int	key, t_all *a);
void				ft_forward(t_all *a);
void				ft_backward(t_all *a);
void				ft_rotate_left(t_all *a);
void				ft_rotate_right(t_all *a);
void				ft_move_left(t_all *a);
void				ft_move_right(t_all *a);
int					close_window(void *param);
void				dist_to_side(t_all *a);
void				side_dist(t_all *a);
void				dda(t_all *a);
void				dist_projected(t_all *a);
#endif