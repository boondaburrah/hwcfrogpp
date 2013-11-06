CC=clang
CFLAGS=-std=c++11 -I. -I/usr/include
LDFLAGS=-lSDL2 -lstdc++ -L/usr/lib

hwcfrog: Sprite.o Frog.o GameWorld.o Game.o main.o
	$(CC) -o hwcfrog Sprite.o Frog.o GameWorld.o Game.o main.o $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm hwcfrog