# Executable file to create and its dependencies
prog : driver_phase1.o Container.o Files.o
	g++ -std=c++11 -o prog driver_phase1.o Container.o Files.o

# File dependencies
driver_phase1.o : Container.h Files.h
	g++ -std=c++11 -c driver_phase1.cpp

Container.o : Container.h
	g++ -std=c++11 -c Container.cpp

Files.o : Files.h
	g++ -std=c++11 -c Files.cpp

# Files to remove
clean:
	rm -f driver_phase1.o Container.o Files.o prog
