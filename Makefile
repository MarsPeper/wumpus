CC = g++
exe_file = wumpus

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -O3
endif

$(exe_file): event.o wumpus.o rope.o room.o points.o pit.o gold.o empty.o bats.o main.o player.o game.o
	$(CC) event.o wumpus.o rope.o room.o points.o pit.o gold.o empty.o bats.o main.o player.o game.o -o $(exe_file) $(CFLAGS)
event.o: event.cpp
	$(CC) -c event.cpp $(CFLAGS)
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp $(CFLAGS)
rope.o: rope.cpp
	$(CC) -c rope.cpp $(CFLAGS)
room.o: room.cpp
	$(CC) -c room.cpp $(CFLAGS)
points.o: points.cpp
	$(CC) -c points.cpp $(CFLAGS)
pit.o: pit.cpp
	$(CC) -c pit.cpp $(CFLAGS)
gold.o: gold.cpp
	$(CC) -c gold.cpp $(CFLAGS)
empty.o: empty.cpp
	$(CC) -c empty.cpp $(CFLAGS)
bats.o: bats.cpp
	$(CC) -c bats.cpp $(CFLAGS)
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)
player.o: player.cpp
	$(CC) -c player.cpp $(CFLAGS)
game.o: game.cpp
	$(CC) -c game.cpp $(CFLAGS)
clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
