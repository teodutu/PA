#include "fermat.h"

#define NUM_TESTS 8

std::vector<int> filter_non_prime(const std::vector<int>& sequence) {
    std::vector<int> primes;

    // se ruleaza cate 8 teste cu algoritmul lui Fermat pentru fiecare numar din secventa data
    for (int n : sequence) {
        if(is_fermat_prime(n, NUM_TESTS)) {
            primes.emplace_back(n);
        }
    }

    return primes;
}
