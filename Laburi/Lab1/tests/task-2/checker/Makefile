CXX := g++
CXXFLAGS := -std=c++11

.PHONY: all
all: main

.PHONY: clean
clean:
	rm -f main

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
