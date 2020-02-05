#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

a.exe: date.o friends.o fbfriends.o main.o
	$(CC) $(CFLAGS) date.o friend.o fbfriends.o main.o -o a.exe

fbfriends.o: fbfriends.cc fbfriends.h
	$(CC) -c $(CFLAGS) fbfriends.cc -o fbfriends.o

friend.o: friend.cc friend.h
	$(CC) -c $(CFLAGS) friend.cc -o friend.o

date.o: date.cc date.h
	$(CC) -c $(CFLAGS) date.cc -o date.o

main.o: main.cc 
	$(CC) -c $(CFLAGS) main.cc -o main.o

clean:
	rm -rf date.o friend.o fbfriends.o a.exe