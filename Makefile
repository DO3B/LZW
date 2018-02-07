lzw: main.o compression.o dictionnaire.o lecture_ecriture.o
	gcc -g -Wall -o lzw main.o compression.o dictionnaire.o lecture_ecriture.o

main.o: main.c compression.h dictionnaire.h
	gcc -ggdb -c -Wall main.c

dictionnaire.o: dictionnaire.c dictionnaire.h
		gcc -g -c -Wall dictionnaire.c

compression.o: compression.c compression.h dictionnaire.h lecture_ecriture.h
	gcc -g -c -Wall compression.c

lecture_ecriture.o : lecture_ecriture.c lecture_ecriture.h
	gcc -g -c -Wall lecture_ecriture.c
	
clean:
	rm lzw *.o *.txt
