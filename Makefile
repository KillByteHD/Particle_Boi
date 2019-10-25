CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OUT = particle_boi
CPP_FLAGS = -W -Wextra -std=c++11
FULL_FLAGS = $(CPP_FLAGS) $(LIBS)

HPP_PATH = header
CPP_PATH = source
O_PATH = object

HEADERS = $(wildcard $(HPP_PATH)/*.hpp)
SOURCES = $(wildcard $(CPP_PATH)/*.cpp)
OBJECTS = $(patsubst $(CPP_PATH)/%.cpp, $(O_PATH)/%.o, $(SOURCES))


all: $(O_PATH) compile

############################

compile: $(OBJECTS) 
	$(CC) $(FULL_FLAGS) -o $(OUT) $^

$(OBJECTS): $(O_PATH)/%.o : $(CPP_PATH)/%.cpp
	$(CC) $(FULL_FLAGS) -c $^ -o $@

############################

$(O_PATH):
	mkdir $@

############################


run: compile
	./$(OUT)


clean:
	rm -rf $(OUT) $(OBJECTS) $(O_PATH)