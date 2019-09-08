cc = g++
cflag = -I../pre
objects = test_bst.o bst.o
test_bst : $(objects)
	$(cc) $(cflag) -o test_bst $(objects)
test_bst.o : test_bst.cpp
	$(cc) $(cflag) -c test_bst.cpp
bst.o : bst.cpp
	$(cc) $(cflag) -c bst.cpp
clean :
	rm test_bst $(objects)
