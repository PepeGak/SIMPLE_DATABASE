TARGET = main.out
CC = g++
VERSION = -std=c++17

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(VERSION) -o $(TARGET) $(OBJ)

$(PREF_OBJ)%.o: $(PREF_SRC)%.cpp
	$(CC) $(VERSION) -g -c $< -o $@

clean:
	rm *.o