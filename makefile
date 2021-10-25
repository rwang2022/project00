all: main.o library.o songs.o
	gcc -o myTunez.out main.o library.o songs.o
	./myTunez.out

main.o: main.c library.h songs.h
	gcc -c main.c

library.o: library.c library.h songs.h
	gcc -c library.c

songs.o: songs.c songs.h
	gcc -c songs.c

clean:
	rm *.o
	rm myTunez.out

# use "make all" and "make clean"