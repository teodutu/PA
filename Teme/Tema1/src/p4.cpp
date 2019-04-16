#include <fstream>
#include <iostream>

using namespace std;

#define MOD 1000000007

// functia realizeaza operatia base^exp in Theta(log(exp)) timp
int logExp(int base, int exp) {
    int res = 1;

    while (exp) {
        if (exp & 1) {
            res = (1LLU * res * base) % MOD;
        }

        base = (1LLU * base * base) % MOD;
        exp >>= 1;
    }

    return res;
}

// functia calculeaza C_n^k folosindu-se de inversul modular descris in README
// C_n^k = n! * (k!)^(-1) * (n - k)!^(-1)
int calculateCombs(int* fact, int n, int k) {
    int invKFact = logExp(fact[k], MOD - 2);
    int invNKFact = logExp(fact[n - k], MOD - 2);

    int res = (1LLU * fact[n] * invKFact) % MOD;
    res = (1LLU * res * invNKFact) % MOD;

    return res;
}

// functia calculeaza numarul de jocuri cu monede diferite (fara permutari) pentru n, k si v
int calculateGamesEven(int* fact, int* sumCombs, int n, int k, int v) {
    if (k < n / 2 || v < n) {
        return 0;
    }

    // numarul de moduri in care se poate partiiona k in n/2 diferente * numarul de diferente
    // posibile
    return (1LLU * calculateCombs(fact, k - 1, n / 2 - 1) * sumCombs[v - k - n / 2]) % MOD;
}

// functia precalculeaza factorialele si combinarile necesare in formula finala
void makeFactCombs(int* fact, int* sumCombs, int n, int k, int v) {
    // se calculeaza factorialele numerelor necesare
    fact[0] = 1;
    for (int i = 1; i <= v; ++i) {
        fact[i] = (1LLU * fact[i - 1] * i) % MOD;
    }

    // avem nevoie de C_{n/2 - 1}^{n/2 - 1}, ..., C_{v - k - 1}^{n/2 - 1}
    // pentru a ocupa si primele pozitii din vector, acestea se shifteaza cu n/2 - 1 pozitii
    // la stanga
    // asadar C_i^{n/2 - 1} este la pozitia i - n / 2 + 1
    sumCombs[0] = 1;
    for (int i = n / 2  + 1; i <= v - k; ++i) {
        sumCombs[i - n / 2] = (sumCombs[i - n / 2 - 1]
                               + calculateCombs(fact, i - 1, n / 2 - 1)) % MOD;
    }
}

int main() {
    ifstream in("p4.in");
    ofstream out("p4.out");

    int n, k, v, totalGames;
    int* fact, *sumCombs;

    // se citesc datele si se aloca memorie
    in >> n >> k >> v;

    fact = new int[v + 1];
    sumCombs = new int[v - k + 1];

    // se precalculeaza factorialele si sumele de combinari ce vor interveni in formula din README
    makeFactCombs(fact, sumCombs, n, k, v);

    if (n & 1) {
        int subGames = 0;

        // se calculeaza jocurile cu numar par de monede rezultate din considerarea lui i ca fiind
        // ce mai mica moneda din fiecare joc
        for (int i = 1; i <= v; ++i) {
            subGames = (subGames + calculateGamesEven(fact, sumCombs, n - 1, k - i, v - i)) % MOD;
        }

        // toate permutarile unui joc sunt admise, deci se inmulteste rezultatul anterior cu n!
        totalGames = (1LLU * subGames * fact[n]) % MOD;
    } else {
        // numarul de jocuri este numarul de permutari al numarului de jocuri cu monede diferite
        totalGames = (1LLU * calculateGamesEven(fact, sumCombs, n, k, v) * fact[n]) % MOD;
    }

    out << totalGames << '\n';

    // se elibereaza memoria si se inchid fisierele
    delete[] fact;
    delete[] sumCombs;

    in.close();
    out.close();

    return 0;
}
