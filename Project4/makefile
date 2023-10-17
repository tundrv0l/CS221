# Project03 Makefile -- CPE 212-01, Fall 2010

Prog3Main:  Prog3Main.o Character.o Possessions.o
	g++  Prog3Main.o Character.o Possessions.o  -o Prog3Main


Prog3Main.o:  Prog3Main.cpp Character.h Possessions.h Item.h
	g++ -c Prog3Main.cpp


Character.o:  Character.cpp Character.h Item.h
	g++ -c Character.cpp


Possessions.o:  Possessions.cpp Possessions.h Item.h
	g++ -c Possessions.cpp


# Remove executable and all object files if they exist
clean:
	rm  *.o  Prog3Main


