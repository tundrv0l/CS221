# Project03 Makefile -- CPE 212-01, Fall 2010

Prog4Main:  Prog4Main.o GameGraph.o
	g++  Prog4Main.o GameGraph.o  -o Prog4Main


Prog4Main.o:  Prog4Main.cpp GameGraph.h
	g++ -c Prog4Main.cpp


GameGraph.o:  GameGraph.cpp GameGraph.h
	g++ -c GameGraph.cpp

# Remove executable and all object files if they exist
clean:
	rm  *.o  Prog4Main


