libhomework9.so: homework9.c homework9.h
		gcc -o libhomework9.so -shared -fPIE -I /usr/java/latest/include -I /usr/java/latest/include/linux homework9.c

homework9.h: homework9.class
		javah homework9

homework9.class: homework9.java
		javac homework9.java

run:
		java -Djava.library.path=. homework9
