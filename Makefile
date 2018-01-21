lzw: main.o compression.o dictionnaire.o
	gcc -g -Wall -o lzw main.o compression.o dictionnaire.o

main.o: main.c compression.h dictionnaire.h
	gcc -ggdb -c -Wall main.c

compression.o: compression.c compression.h
	gcc -g -c -Wall compression.c

dictionnaire.o: dictionnaire.c dictionnaire.h
	gcc -g -c -Wall dictionnaire.c

clean:
	rm lzw *.o *.txt
