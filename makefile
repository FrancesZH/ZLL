all: zll 

zll: main.o
	g++ main.o -o zll

main.o: main.cpp ZLL.h Zany.h
	-g++ -c main.cpp 

clean:
	rm -f *.o zll


