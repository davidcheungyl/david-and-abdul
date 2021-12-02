FLAGS = g++ -pedantic-errors -std=c++11

skeleton.o: skeleton.cpp skeleton.h
	$(FLAGS) -c skeleton.cpp

functions.o: functions.cpp skeleton.h functions.h
	$(FLAGS) -c functions.cpp
	
main.o: main.cpp skeleton.h functions.h
	$(FLAGS) -c main.cpp

game: main.o skeleton.o functions.o
	$(FLAGS) main.o functions.o skeleton.o -o game

clean:
	rm -rf game main.o skeleton.o functions.o

.PHONY: clean