B-Tree: main.o BTree.o Node.o
	g++ -g main.o BTree.o Node.o -o B-Tree

main.o: main.cpp BTree.h Node.h
	g++ -c -g main.cpp

BTree.o: BTree.h BTree.cpp Node.h
	g++ -c -g BTree.cpp

Node.o: Node.h Node.cpp
	g++ -c -g Node.cpp

valgrind: B-Tree
	valgrind --leak-check=full ./B-Tree

clean:
	rm *.o
	rm B-Tree

run: B-Tree
	./B-Tree
