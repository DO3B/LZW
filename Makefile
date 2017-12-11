lzw: main.o compression.o fichier.o
	gcc -g -Wall -o lzw main.o compression.o fichier.o

main.o: main.c compression.h fichier.h
	gcc -g -c -Wall main.c

compression.o: compression.c fichier.h compression.h
	gcc -g -c -Wall compression.c

fichier.o: fichier.c fichier.h
	gcc -g -c -Wall fichier.c

clean:
	rm lzw *.o
