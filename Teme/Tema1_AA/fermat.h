#ifndef PRIME_NUMBERS_FERMAT_H
#define PRIME_NUMBERS_FERMAT_H

#include <random>

#include "algo.h"
#include "utils.h"

/**
 * Ruleaza algoritmul lui Fermat pentru a determina daca un numar este prim.
 *
 * @param n numarul verificat
 * @param num_tests numarul de rulari ale algoritmului lui Fermat care se vor efectua
 * @return true daca numarul pare prim, false daca este compus
 */
bool is_fermat_prime(const int n, const int num_tests);

#endif //PRIME_NUMBERS_FERMAT_H
