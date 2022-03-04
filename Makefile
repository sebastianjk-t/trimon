CXX = clang++
CXXFLAGS = -Wall

all: run

compile: Move.o Mon.o Player.o Com.o Human.o main.cpp input.cpp
	@$(CXX) Move.o Mon.o Player.o Com.o Human.o main.cpp input.cpp -o trimon $(CXXFLAGS)

run: compile
	@./trimon

Move.o: Move.h Move.cpp
	@$(CXX) -c Move.cpp $(CXXFLAGS)

Mon.o: Mon.h Mon.cpp
	@$(CXX) -c Mon.cpp $(CXXFLAGS)

Player.o: Player.h Player.cpp
	@$(CXX) -c Player.cpp $(CXXFLAGS)

Com.o: Com.h Com.cpp
	@$(CXX) -c Com.cpp $(CXXFLAGS)

Human.o: Human.h Human.cpp
	@$(CXX) -c Human.cpp $(CXXFLAGS)

clean:
	@rm -f *.o program
