GG=g++ -std=c++17

build: pb1 pb3

pb1: points.cpp
	$(GG) $^ -o $@

run-p1: pb1
	./pb1

pb3: stropitori.cpp
	$(GG) $^ -o $@

run-p3: pb3
	./pb3

clean:
	rm pb1 pb3
