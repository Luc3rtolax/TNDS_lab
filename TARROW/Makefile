CXX = g++
CXXFLAGS = -std=c++17 -Wall $(shell root-config --cflags)
LDFLAGS = $(shell root-config --libs)

TARGET = campo_elettrico

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o *.png *.pdf
