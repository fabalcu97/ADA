TARGET = main
#LIBS = -L/usr/local/libntl.a
CCXX = g++
CXXFLAGS = -g -Wall -std=c++11 -o2 -march=corei7 -j5

.PHONY: default all clean hash

default: $(TARGET)
#all: default
# hash: ~/Programming/AED/Hash\ Table/$(TARGET)
insertion:
	/home/fabricio/Programming/V\ Semestre/ADA/Insertion\ sort/Insertion_Sort_func.cpp: $(OBJECTS)
		$(CCXX) $(CXXFLAGS) $(OBJECTS) -Wall $(LIBS) -o $@

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CCXX) $(CXXFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CCXX) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
