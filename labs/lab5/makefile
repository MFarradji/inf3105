CC = g++
OPTIONS = -g -Wall -O3 -std=c++11

all: lab5 random_passages test_liste

test_liste: test_liste.cpp liste.h
	$(CC) $(OPTIONS) -o test_liste test_liste.cpp liste.h

lab5: lab5.cpp liste.h
	$(CC) $(OPTIONS) -o lab5 lab5.cpp liste.h

random_passages: random_passages.cpp
	$(CC) $(OPTIONS) -o random_passages random_passages.cpp

clean :
	rm -f lab5 random_passages test_liste
