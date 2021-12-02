FLAGS = g++ -pedantic-errors -std=c++11

skeleton.o: skeleton.cpp skeleton.h
	$(FLAGS) -c skeleton.cpp

lifelines.o: lifelines.cpp skeleton.h lifelines.h
	$(FLAGS) -c lifelines.cpp

functions.o: functions.cpp skeleton.h functions.h lifelines.h
	$(FLAGS) -c functions.cpp
	
main.o: main.cpp skeleton.h functions.h lifelines.h
	$(FLAGS) -c main.cpp

game: main.o skeleton.o functions.o lifelines.o
	$(FLAGS) main.o skeleton.o functions.o lifelines.o -o game

clean:
	rm -rf game main.o skeleton.o functions.o lifelines.o

.PHONY: clean