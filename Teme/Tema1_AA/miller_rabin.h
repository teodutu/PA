#ifndef PRIME_NUMBERS_MILLER_RABIN_H
#define PRIME_NUMBERS_MILLER_RABIN_H

#include "utils.h"

/**
 * Ruleaza algoritmul lui Miller-Rabin pentru a determina daca un numar este prim.
 *
 * @param n numarul verificat
 * @return true daca numarul pare prim, false daca este compus
 */
bool is_miller_rabin_prime(const int n);

/**
 * Efectueaza un test corespunzator algoritmului Miller-Rabin, de tipul a^m (mod n).
 * Se considera descompunerea: n - 1 = pow2 * m, cu pow2 = 2^k.
 *
 * @param a "martor" ales in is_fermat_prime
 * @param m factorul ce nu reprezinta o putere a lui 2 din descompunerea lui n - 1
 * @param n numarul verificat
 * @param pow2 cea mai mare putere a lui 2 care divide n
 * @return
 */
bool test_miller_rabin(int a, const int m, const int n , const int pow2);

#endif //PRIME_NUMBERS_MILLER_RABIN_H
