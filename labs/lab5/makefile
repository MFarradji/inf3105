CC = g++
OPTIONS = -g -Wall -std=c++11

all: lab5 random_passages test_liste

test_liste: test_liste.cpp liste.h
	$(CC) $(OPTIONS) -o test_liste test_liste.cpp liste.h

lab5: lab5.cpp liste.h
	$(CC) $(OPTIONS) -o lab5 lab5.cpp

# Lab 6
lab5_arbreavl: lab5_arbreavl.cpp arbreavl.h pile.h
	$(CC) $(OPTIONS) -o lab5_arbreavl lab5_arbreavl.cpp

random_passages: random_passages.cpp
	$(CC) $(OPTIONS) -o random_passages random_passages.cpp

clean :
	rm -f lab5 random_passages test_liste lab5_arbreavl
