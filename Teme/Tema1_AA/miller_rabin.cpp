#include "miller_rabin.h"

bool is_miller_rabin_prime(const int n) {
    // cea mai mare putere a lui 2 care divide x este data de primul bit de 1 al acestuia, adica
    // x & -x
    int pow2 = (n - 1) & (1 - n);

    // se trateaza cazurile banale
    if (pow2 == 1 && n != 2) {
        return false;
    } else if (n == 1) {
        return false;
    } else if (n == 2 || n == 3) {
        return true;
    }

    int num_tests, m = n / pow2;
    int a[4];

    // se va demonstra in etapa urmatoare ca urmatoarele alegeri sunt suficiente pentru a determina
    // in mod corect numerele prime
    if (n < 2047) {
        num_tests = 1;
        a[0] = 2;
    } else if (n < 1373653) {
        num_tests = 2;
        a[0] = 2;
        a[1] = 3;
    } else if (n < 25326001) {
        num_tests = 3;
        a[0] = 2;
        a[1] = 3;
        a[2] = 5;
    } else {
        num_tests = 4;
        a[0] = 2;
        a[1] = 3;
        a[2] = 5;
        a[3] = 7;
    }

    // se ruleaza algoritmul propriu-zis
    for (int i = 0; i < num_tests; ++i) {
        if (!(n % a[i]) || !test_miller_rabin(a[i], m, n, pow2)) {
            return false;
        }
    }

    return true;
}

bool test_miller_rabin(int a, int m, int n, int pow2) {
    int res = log_exp(a, m, n);   // a^m (mod n)

    if (res == 1 || res == n - 1) {
        return true;
    }

    // daca pow2 = 2^k, exp = k;
    // functia returneaza numarul de biti de 0 de la finalul numarului dat ca parametru
    int exp = __builtin_ctz(pow2);

    // se continua algoritmlul ridicand la a^m la patrat (mod n) de exp - 1 ori
    for (int j = 1; j < exp; ++j) {
        res = (1LL * res * res) % n;

        if (res == 1) {
            return false;
        } else if (res == n - 1) {
            return true;
        }
    }

    return false;
}