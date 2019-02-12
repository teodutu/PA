#include "algo.h"
#include "miller_rabin.h"

std::vector<int> filter_non_prime(const std::vector<int>& sequence) {
    std::vector<int> primes;

    // se ruleaza testele specifice algoritmului Miller-Rabin pentru numarul curent
    for (int n : sequence) {
        if(is_miller_rabin_prime(n)) {
            primes.emplace_back(n);
        }
    }

    return primes;
}