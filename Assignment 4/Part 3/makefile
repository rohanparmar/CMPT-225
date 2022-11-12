
all: tdPQ

tdPQ: testDriver_PQ.o Queue.h BinaryHeap.h PriorityQueue.h Event.o EmptyDataCollectionException.o
	g++ -o tdPQ -Wall testDriver_PQ.o Event.o EmptyDataCollectionException.o
	
testDriver_PQ.o: testDriver_PQ.cpp 
	g++ -c -Wall testDriver_PQ.cpp
	
Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f tdPQ *.o
