#include "utils.h"

int log_exp(int base, int exp, const int mod) {
    int res = 1;

    // se ridica base^exp modulo mod prin ridicari la patrat succesive ale rezultatului
    while (exp) {
        if (exp & 1) {
            res = 1LL * res * base % mod;
        }

        base = 1LL * base * base % mod;
        exp >>= 1;
    }

    return res;
}

int gcd(int a, int b) {
    // shift pastreaza cea mai mare putere a lui 2 care divide atat a cat si b
    int shift = __builtin_ctz(a | b);
    int aux;

    // orice alte puteri ale lui 2 in afara de shift sunt irelevante pentru cmmdc, deci se elimina
    // funcita __builtin_ctz returneaza numarul de biti de 0 de la finalul numarului
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);

        if (a > b) {
            aux = b;
            b = a;
            a = aux;
        }

        b -= a;
    } while (b);

    return a << shift;
}

