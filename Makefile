LIBFT =		ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
			ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
			ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
			ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c

GNL =	get_next_line_utils.c get_next_line.c

FT_PRINTF =	ft_printf.c ft_printf_utils.c

SRCS =	main.c \
	utils/is_space.c utils/clear_map_exit.c utils/free_array.c \
	parser/utils/add_pix.c parser/utils/add_nswe.c parser/utils/get_line.c parser/utils/add_map.c \
	parser/utils/get_position.c \
	parser/design_map.c parser/check_characters.c parser/arrange_tmap.c \
	parser/get_data.c parser/utils/condition.c \
	start_render/start_game.c start_render/render.c start_render/look_slope.c \
	start_render/draw.c start_render/image_pixel.c \
	motion/motion_setting.c motion/event_down.c motion/event_up.c motion/move.c \
	motion/update.c \
	$(addprefix help/libft/, $(LIBFT)) \
	$(addprefix help/gnl/, $(GNL)) \
	$(addprefix help/ft_printf/, $(FT_PRINTF))

OBJS = $(SRCS:.c=.o)

CC = gcc

FRAMEWORK = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

MLX = minilibx/libmlx.a

RM = rm -rf

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(FRAMEWORK) -o $(NAME)

$(MLX):
	make -C minilibx

clean:
	$(RM) $(OBJS)
	make clean -C minilibx

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re