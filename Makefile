CFLAGS = -g -Wall
CC = g++


compile: main.o DoublyLinkedList.o
	$(CC) $(CFLAGS) -o main main.o DoublyLinkedList.o

DoublyLinkedList:DoublyLinkedList.o
	$(CC) $(CFLAGS) -c DoublyLinkedList.cpp

main:main.o
	$(CC) $(CFLAGS) -c main.cpp

clean:
	-rm -f a.out *.o core atest
	-rm -f *.class
	-rm -f main 
	
