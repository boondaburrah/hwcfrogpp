CC=clang
CFLAGS=-std=c++11 -I. -I/usr/include
LDFLAGS=-lSDL2 -lstdc++ -L/usr/lib

hwcfrogpp: Sprite.o Frog.o GameWorld.o Game.o main.o
	$(CC) -o hwcfrogpp Sprite.o Frog.o GameWorld.o Game.o main.o $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm hwcfrogpp
