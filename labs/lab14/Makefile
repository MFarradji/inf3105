# Makefile pour INF3105 / Lab14
OPTIONS = -std=c++11 -W -Wall -g

all: lab14a lab14b lab14b-2

lab14a: lab14a.cpp date.cpp date.h dictionnaire.h
	g++ ${OPTIONS} -o lab14a lab14a.cpp date.cpp

lab14b: lab14b.cpp
	g++ ${OPTIONS} -o lab14b lab14b.cpp

lab14b-2: lab14b-2.cpp
	g++ ${OPTIONS} -o lab14b-2 lab14b-2.cpp

clean:
	rm -rf lab14a lab14b lab14b-2
