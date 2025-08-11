CXX := g++
CXXFLAGS := -std=c++17 -Wall -Iinclude
TARGET := data_processor
SRC := src/DataProcessor.cpp src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
