all: hftd

hftd: hashFunctionTestDriver.o hashDataCollection.o
	g++ -Wall -o hftd hashFunctionTestDriver.o hashDataCollection.o
	
hashFunctionTestDriver.o: hashFunctionTestDriver.cpp
	g++ -Wall -c hashFunctionTestDriver.cpp
			
hashDataCollection.o: hashDataCollection.h hashDataCollection.cpp
	g++ -Wall -c hashDataCollection.cpp

clean:
	rm -f hftd *.o
