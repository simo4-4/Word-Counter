wcloud: wcloud.o wordlist.o
	gcc -o wcloud wcloud.o wordlist.o 

wordlist.o: wordlist.c wordlist.h
	gcc -c wordlist.c 

wcloud.o: wcloud.c  wordlist.h 
	gcc -c wcloud.c  

