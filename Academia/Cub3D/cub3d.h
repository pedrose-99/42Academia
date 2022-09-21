#ifndef CUBB3D_H
# define CUB3D_H

# define TEXTURES	9
# define C_LAST     13

typedef struct s_config
{
    int     height;
    int     width;
    int     *map;
    int     rows;
    int     columns;
    int     arg;
    double  rotate_speed;
    double  move_speed;
    char    *tex_path[TEXTURES];
    unsigned    c[TEXTURES];
    int     set[C_LAST];
    double  fov;
}               t_config;

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_tex
{
	char	*path;
	void	*tex;
	void	*ptr;
	t_pos	start;
	t_pos	end;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_tex;

typedef struct	s_image
{
	void	*img;
	void	*ptr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef	struct	s_window
{
	void		*ptr;
	void		*win;
	t_image		screen;
	t_pos		size;
	t_pos		half;
	double		ratio;
}				t_window;

typedef struct	s_camera
{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
}				t_camera;

typedef	struct	s_game
{
	t_config	config;
	t_window	window;
	t_camera	camera;
	t_tex		tex[TEXTURES];
	t_pos		move;
	t_pos		x_move;
	t_pos		rotate;
	int			options;
	int			to_collect;
	int			collected;
	double		camera_x[1920];
	double		depth[1920];
	double		sf_dist[1080];
	double		cos[2];
	double		sin[2];
}				t_game;
#endif

