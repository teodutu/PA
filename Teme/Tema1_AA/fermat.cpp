#include "fermat.h"

bool is_fermat_prime(const int n, const int num_tests) {
    // se testeaza cazuri banale
    if (n == 1) {
        return false;
    } else if (n == 2 || n == 3) {
        return true;
    } else if (!(n & 1)) {
        return false;
    }

    // se ruleaza numarul specificat de teste cu algoritmul lui Fermat
    for (int i = 0; i < num_tests; ++i) {
        // se aelge un numar aleator in intervalul [2, n - 2]
        int a = random() % (n - 3) + 2;

        // daca n si a nu sunt prime intre ele sau a^(n - 1) != 1 (mod n), inseamna ca numarul n
        // este compus; altfel, n poate fi prim
        if (gcd(n, a) != 1 || log_exp(a, n - 1, n) != 1) {
            return false;
        }
    }

    return true;
}