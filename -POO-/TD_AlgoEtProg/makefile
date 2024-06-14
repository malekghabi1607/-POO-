Liste-main	:	Liste-main.cpp Liste.o Liste.h
	g++ -Wall -g -o Liste-main Liste-main.cpp Liste.o

Liste.o	:	Liste.cpp Liste.h
	g++ -Wall -g -c Liste.cpp

clean	:
	rm -f *.o 

mrproper	:	clean
	rm -f Liste-main
