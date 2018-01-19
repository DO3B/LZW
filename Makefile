lzw: main.o compression.o dictionnaire.o
	gcc -g -Wall -o lzw main.o compression.o dictionnaire.o ecriture_bit.o

main.o: main.c compression.h dictionnaire.h
	gcc -ggdb -c -Wall main.c

compression.o: compression.c compression.h
	gcc -g -c -Wall compression.c

dictionnaire.o: dictionnaire.c dictionnaire.h
	gcc -g -c -Wall dictionnaire.c

ecriture_bit.o: ecriture_bit.c ecriture_bit.h
	gcc -g -c -Wall ecriture_bit.c

clean:
	rm lzw *.o *.txt
