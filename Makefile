CFLAGS = -g -Wall
CC = g++


compile: main.o BinaryTree.o
	$(CC) $(CFLAGS) -o main main.o BinaryTree.o

DoublyLinkedList:BinaryTree.o
	$(CC) $(CFLAGS) -c BinaryTree.cpp

main:main.o
	$(CC) $(CFLAGS) -c main.cpp

clean:
	-rm -f a.out *.o core atest
	-rm -f *.class
	-rm -f main 
	
