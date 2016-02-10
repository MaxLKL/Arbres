CC = gcc
EXEC = arbres
DEBUG = yes

ifeq ($(DEBUG),yes)
	CFLAGS = -g -W -Wall -Wextra
else
	CFLAGS = -W -Wall -Wextra -Werror --pedantic -O3
endif

all: $(EXEC) clean

$(EXEC): main.o fonctions_base.o generation_rnd.o affichage.o
	$(CC) $^ -o $(EXEC) $(CFLAGS) `sdl-config --libs` -lSDL_ttf -lm

main.o: affichage.h fonctions_base.h types.h generation_rnd.h
affichage.o: types.h graphics.h
fonctions_base.o: types.h
generation_rnd.o: types.h fonctions_base.h

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

clean:
	rm -rf *.bak rm -rf *.o

mrproper: clean
	rm -rf Quorridor
