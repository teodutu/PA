#include <iostream>
#include <chrono>
#include <climits>

#include "algo.h"
#include "input_parser.h"
#include "output_parser.h"

#define MAX_SQRT 46340  // sqrt(INT_MAX)

/**
 * Verifica daca un numar este prim folosind un bitset.
 *
 * @param p pointer la bitsetul de numere prime
 * @param n numarul verificat
 * @return true daca n este prim, false daca nu
 */
bool is_true_prime(const char* p, int n) {
    return (n == 2 || ((n & 1) && p[n >> 4] & (1 << ((n % 16) / 2))));
}

/**
 * Foloseste Ciurul lui Atkin optimizat pe biti pentru a genera toate numere prime intre 0 si
 * INT_MAX.
 *
 * @param p pointer la bitsetul de numere prime
 */
void generate_primes(char* p) {
    int lim = MAX_SQRT;
    long long res;
    p[0] = 0b10;  // 3 e prim

    // se folosesc numere modulo 60, optimizate prin reducerea la 4 cazuri modulo 12
    // numerele pare se ignora in reprezentarea pe biti, iar cele impare vor fi retinute pe bitii
    // cate unui char
    for (int i = 1; i <= lim; ++i) {
        for (int j = 1; j <= lim; ++j) {
            res = 1LL * 4 * i * i + 1LL * j * j;
            if (res & 1 && res <= INT_MAX && (res % 12 == 1 || res % 12 == 5)) {
                p[res >> 4] ^= (1 << ((res % 16) / 2));
            }

            res = 1LL * 3 * i * i + 1LL * j * j;
            if (res & 1 && res <= INT_MAX && res % 12 == 7) {
                p[res >> 4] ^= (1 << ((res % 16) / 2));
            }

            res = 1LL * 3 * i * i - 1LL * j * j;
            if (i > j && res & 1 && res <= INT_MAX && res % 12 == 11) {
                p[res >> 4] ^= (1 << ((res % 16) / 2));
            }
        }
    }

    // se elimina patratele perfecte
    for (int i = 5; i <= lim; i += 2) {
        if (p[i >> 4] & (1 << ((i % 16) / 2))) {
            long long k = i * i;

            for (long long j = k; j <= INT_MAX; j += 2 * k) {
                 p[j >> 4] &= ~(1 << ((j % 16) / 2));
            }
        }
    }
}

int main() {
    char in_file_name[] = "in/test0.in";
    char out_file_name[] = "out/test0.out";

    int num_ints;
    char *p = new char[(INT_MAX >> 4) + 1];
    std::vector<int> sequence;

    generate_primes(p);

    // se testeaza toate input-urile cu algoritmul ales
    for (int i = 0; i <= 9; ++i) {
        in_file_name[7] = i + '0';
        out_file_name[8] = i + '0';

        InputReader reader(in_file_name);
        OutputWriter writer(out_file_name);

        std::cout << "============= Checking test " << i << " =============\n\n";

        num_ints = reader.read_int();

        for (int j = 0; j < num_ints; ++j) {
            sequence.emplace_back(reader.read_int());
        }

        double num_true_primes = 0;

        // se returneaza vectorul de numere prime si se cronometreaza timpul de rulare al
        // algoritmului
        auto start = std::chrono::steady_clock::now();
        std::vector<int> primes = filter_non_prime(sequence);
        std::chrono::duration<double> duration = std::chrono::steady_clock::now() - start;
        std::cout << "Algorithm duration: " << duration.count() << " seconds\n";

        // se scriu numerele (pseudo)prime gasite in fisierul de output
        writer.write_int(primes.size());
        writer.write_char('\n');
        for (int n : primes) {
            writer.write_int(n);
            writer.write_char(' ');

            if (is_true_prime(p, n)) {
                ++num_true_primes;
            }
        }

        // se afiseaza precizia definita ca raportul dintre numarul real de numere prime si cel
        // de numere prime gasite
        double precision = (num_true_primes < 0.1 && !primes.size() ? 100 :
                            num_true_primes / (double)primes.size() * 100);
        std::cout << "Algorithm precision: " << precision << "%\n\n";

        writer.write_char('\n');
        sequence.clear();
    }

    delete[] p;

    return 0;
}
