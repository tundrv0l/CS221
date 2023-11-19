# Project03 Makefile -- CPE 212-01, Fall 2010

Prog2Main:  Prog2Main.o Character.o CharacterList.o
	g++  Prog2Main.o Character.o CharacterList.o  -o Prog2Main


Prog2Main.o:  Prog2Main.cpp Character.h CharacterList.h Item.h
	g++ -c Prog2Main.cpp


Character.o:  Character.cpp Character.h Item.h
	g++ -c Character.cpp


CharacterList.o:  CharacterList.cpp CharacterList.h Item.h
	g++ -c CharacterList.cpp


# Remove executable and all object files if they exist
clean:
	rm  *.o  Prog2Main


