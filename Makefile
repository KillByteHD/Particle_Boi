OBJECTS = main.o particle.o
HEADERS = particle.hpp
CPP_FILES = main.cpp particle.cpp

CC = g++
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
OUT_NAME = particle_boi
CPP_FLAGS = -W -Wextra -std=c++11
FULL_FLAGS = $(CPP_FLAGS) $(LDLIBS)



compile: $(OBJECTS) 
	$(CC) $(FULL_FLAGS) -o $(OUT_NAME) $(OBJECTS) 

%.o: %.cpp $(HEADERS)
	$(CC) $(FULL_FLAGS) -c -o $@ $<
	

run: compile
	./$(OUT_NAME)

clean:
	rm -rf $(OUT_NAME) $(OBJECTS)