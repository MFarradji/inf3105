# Makefile pour le lab4
OPTIONS = -Wall -W -std=c++11

all: test_pile test_file lab4 test_pile_mem test_tableau

# Syntaxe : cible : dépendance1 dépendance2 ...
# Ensuite, la ou les ligne(s) débutant par une tabulation (\t) donne les commandes pour construire une cible.

lab4: lab4.cpp pile.h file.h
	g++ $(OPTIONS) -o lab4 lab4.cpp

test_pile: test_pile.cpp pile.h
	g++ $(OPTIONS) -o test_pile test_pile.cpp

test_file: test_file.cpp file.h
	g++ $(OPTIONS) -o test_file test_file.cpp

test_pile_mem: test_pile_mem.cpp file.h
	g++ $(OPTIONS) -o test_pile_mem test_pile_mem.cpp

test_tableau: test_tableau.cpp file.h tableau.h
	g++ $(OPTIONS) -o test_tableau test_tableau.cpp

clean:
	rm -f test_pile test_file test_pile_mem lab4 test_tableau
