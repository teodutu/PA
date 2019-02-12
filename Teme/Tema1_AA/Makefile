CC = g++
CFLAGS = -Wall -Wextra -O2
CFLAGSO3 = -Wall -Wextra -O3
LDLIBS = -lm
ELF = find_primes
GEN = generator

build_miller: tester.o algo.o input_parser.o output_parser.o
	$(CC) $^ -o $(ELF) 

build_fermat: tester.o algo1.o input_parser.o output_parser.o
	$(CC) $^ -o $(ELF)

algo1.o: algo_fermat.o libfermat.a libutils.a
	ld -r -o $@ $^

algo_fermat.o: algo1.cpp
	$(CC) $(CFLAGS) $^ -c -o $@

algo.o: algo_miller.o libmiller.a libutils.a
	ld -r -o $@ $^

algo_miller.o: algo.cpp
	 $(CC) $(CFLAGS) $^ -c -o $@

miller_rabin.o: miller_rabin.cpp
	$(CC) $(CFLAGS) $^ -c

libmiller.a: miller_rabin.o
	ar cr $@ $^

fermat.o: fermat.cpp
	$(CC) $(CFLAGS) $^ -c

libfermat.a: fermat.o
	ar cr $@ $^

utils.o: utils.cpp
	$(CC) $(CFLAGS) $^ -c

libutils.a: utils.o
	ar cr $@ $^

tester.o: tester.cpp
	$(CC) $(CFLAGSO3) $^ -c

input_parser.o: input_parser.cpp
	$(CC) $(CFLAGSO3) $^ -c

output_parser.o: output_parser.cpp
	$(CC) $(CFLAGSO3) $^ -c

$(GEN): generator.o output_parser.o
	$(CC) $(CFLAGSO3) $^ -o $@

generator.o: generator.cpp
	$(CC) $(CFLAGSO3) $^ -c

clean:
	rm -rf *.o *.a $(ELF) $(GEN)
