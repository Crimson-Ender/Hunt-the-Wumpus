CC=g++ -std=c++11
exe=huntWumpus

$(exe): corpse.o bat.o wumpus.o pit.o gold.o event.o room.o game.o player.o huntWumpus.cpp
	$(CC) corpse.o bat.o wumpus.o pit.o gold.o event.o room.o game.o player.o huntWumpus.cpp -o $(exe)

player.o: player.cpp player.h
	$(CC) -c player.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp


gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

pit.o: pit.cpp pit.h
	$(CC) -c pit.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

bat.o: bat.cpp bat.h
	$(CC) -c bat.cpp

corpse.o: corpse.cpp corpse.h
	$(CC) -c corpse.cpp

clean:
	rm -f *.o $(exe)