lzw: main.o compression.o fichier.o dictionnaire.o
	gcc -g -Wall -o lzw main.o compression.o fichier.o dictionnaire.o

main.o: main.c compression.h fichier.h dictionnaire.h
	gcc -g -c -Wall main.c

compression.o: compression.c fichier.h compression.h
	gcc -g -c -Wall compression.c

fichier.o: fichier.c fichier.h
	gcc -g -c -Wall fichier.c

dictionnaire.o: dictionnaire.c dictionnaire.h
	gcc -g -c -Wall dictionnaire.c
clean:
	rm lzw *.o *.txt
