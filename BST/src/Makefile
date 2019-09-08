cc = g++
cflag = -I../include
objects = test_bst.o bst.o
test_bst : $(objects)
	$(cc) -o test_bst $(objects)
test_bst.o : test_bst.cpp
	$(cc) $(cflag) -c test_bst.cpp
bst.o : bst.cpp
	$(cc) $(cflag) -c bst.cpp
clean :
	rm ../bin/test_bst $(objects)
