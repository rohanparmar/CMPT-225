all: fsrs

fsrs: FitStudioReg.o List.o Member.o
	g++ -Wall -o fsrs FitStudioReg.o List.o Member.o

FitStudioReg.o: FitStudioReg.cpp List.h Member.h
	g++ -Wall -c FitStudioReg.cpp

ltd: ListTestDriver.o List.o Member.o
	g++ -Wall -o ltd ListTestDriver.o List.o Member.o
	
ListTestDriver.o: List.h Member.h ListTestDriver.cpp
	g++ -Wall -c ListTestDriver.cpp

Member.o: Member.h Member.cpp
	g++ -Wall -c Member.cpp

clean:
	rm -f fsrs *.o