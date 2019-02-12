#ifndef PRIME_NUMBERS_UTILS_H

/**
 * Efectiueaza operatia a^b % m in complexitate O(logb).
 *
 * @param exp exponentul
 * @param base baza
 * @param mod numarul modulo care se va opera
 * @return
 */
int log_exp(const int n, int exp, const int mod);

/**
 * Calculeaza cmmdc-ul a 2 numere folosind operatii pe biti (Algoritmul lui Stein)
 *
 * @param a primul numar
 * @param b al doilea numar
 * @return cmmdc(a, b)
 */
int gcd(int a, int b);

#define PRIME_NUMBERS_UTILS_H

#endif //PRIME_NUMBERS_UTILS_H
