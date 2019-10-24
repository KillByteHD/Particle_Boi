OBJS = main.o
CC = g++
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
OUT_NAME = particle_boi
CPP_FLAGS = -std=c++11

game: $(OBJS)
	$(CC) -o $(OUT_NAME) $(OBJS) $(LDLIBS)

run: game
	./$(OUT_NAME)

clean:
	rm -rf $(OUT_NAME) $(OBJS)