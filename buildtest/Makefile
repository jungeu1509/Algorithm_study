CXX=g++
CXXFLAGS=-std=c++98 -g
OBJS=test.o
TARGET=algorithm.out

$(TARGET):$(OBJS)
	$(CXX) -o $@ $(OBJS)
	rm *.o

clean:
	rm -f *.o
	rm $(TARGET)
