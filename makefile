all: zll_sample

zll_sample: zll_sample.o Thing.o
	g++ zll_sample.o Thing.o -o zll_sample

zll_sample.o: zll_sample.cpp ZLL.h Zany.h 
	-g++ -c zll_sample.cpp 

Thing.o: Thing.cpp
	-g++ -c Thing.cpp
clean:
	rm -f *.o zll_sample


