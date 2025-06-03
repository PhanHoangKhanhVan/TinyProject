CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Vector.o Matrix.o LinearSystem.o PosSymLinSystem.o

solver: $(OBJS)
	$(CXX) $(OBJS) -o solver

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o solver