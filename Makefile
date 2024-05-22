BIN_NAME	= ic

SRCS		= main.cpp\
			  src/ic_test.cpp

HEADERS		= include/ic.h

OBJ			= $(SRCS:.cpp=.o)

CC			= g++ -fsanitize=address -std=c++20

CFLAGS		= -Iinclude

LDFLAGS		= -fsanitize=address -lgtest -pthread

all: $(BIN_NAME) clean

clean:
	@rm -rf *.o src/*.o

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@