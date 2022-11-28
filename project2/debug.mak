project_debug: llist.o user_interface.o
		g++ -o project_debug llist.o user_interface.o

llist.o: llist.cpp record.h
		g++ -ansi -D DEBUG -pedantic-errors -Wall -c llist.cpp

user_interface.o: user_interface.cpp llist.h
		g++ -ansi -D DEBUG -pedantic-errors -Wall -c user_interface.cpp

