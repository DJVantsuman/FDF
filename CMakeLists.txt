cmake_minimum_required(VERSION 3.6)
project(FdF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES
    main.c
        get_next_line.c
        libft/ft_strdel.c
        libft/ft_strjoin.c
        libft/ft_strsplit.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_strlen.c
        libft/ft_strsub.c
        libft/ft_atoi.c
        libft/ft_atoi_base.c write_line.c create_image.c create_3dmap.c)

add_executable(FdF ${SOURCE_FILES} libft/ft_atoi_base.c write_line.c create_image.c)