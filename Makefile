CXX := g++

CXXFLAGS := -std=c++17 -Wall -Wextra -g -I./include

LDFLAGS := -shared -fPIC

LIB_NAME := logginglib.so

LIB_TARGET := ./lib/$(LIB_NAME)

LIB_SRCS := src/logger.cpp

LIB_OBJS := $(LIB_SRCS:.cpp=.o)

all: $(LIB_TARGET)

$(LIB_TARGET): $(LIB_OBJS) | ./lib
	$(CXX) $(LDFLAGS) -o $@ $(LIB_OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

./lib:
	mkdir -p ./lib

clean:
	rm -f $(LIB_OBJS)
	rm -f $(LIB_TARGET)
	rm -rf ./lib

.PHONY: all clean