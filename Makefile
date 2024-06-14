
NAMEC = fractol

SRCC = main.c parcing.c mlx.c fractal.c
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

OBJ = $(SRCC:%.c=%.o)

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAMEC) 

$(NAMEC) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAMEC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMEC)

re: fclean all
