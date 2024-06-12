
NAMEC = fractol

SRCC = main.c parcing.c
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

OBJ = $(SRCC:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAMEC) 

$(NAMEC) : $(OBJ) fractol.h
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAMEC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMEC)

re: fclean all