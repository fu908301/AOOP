all:mytar 
mytar:main.o tarfile.o
	g++ -ggdb -o mytar main.o tarfile.o
tarfile.o:
	g++ -ggdb -c tarfile.cpp
main.o:
	g++ -ggdb -c main.cpp
dep:
	g++ -ggdb -M main.cpp tarfile.cpp > depend
clean:
		rm *.o mytar depend
