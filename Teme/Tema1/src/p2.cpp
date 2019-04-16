#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int64_t findBestDiff(int64_t** bestDiff, int* v, int n, int k) {
    char sgn = -1;

    // daca i >= j, suma este 0, deoarece se elimina toate numerele din sir
    // pe linia 0 din bestDiff se pun sumele obtinute din sirul initial, caci corespunde eliminarii
    // a 0 elemente
    bestDiff[0][0] = v[0];
    for (int i = 1; i < n; ++i, sgn *= -1) {
        bestDiff[0][i] = bestDiff[0][i - 1] + v[i] * sgn;
    }

    // paritatea unui anumit element din v este decisa de (-1)^(j - i), ceea ce este simulat prin
    // sgn
    for (int i = 1; i <= k; ++i) {
        for (int j = i; j < n; ++j) {
            if ((j - i) & 1) {
                sgn = -1;
            } else {
                sgn = 1;
            }

            bestDiff[1][j] = max(bestDiff[0][j - 1], bestDiff[1][j - 1] + sgn * v[j]);
        }

        memcpy(bestDiff[0], bestDiff[1], n * sizeof(int64_t));
        bestDiff[1][i] = 0;
    }

    return bestDiff[1][n - 1];
}

int main() {
    ifstream in("p2.in");
    ofstream out("p2.out");

    int n, k;
    // bestDiff[i][j] = cea mai mare diferenta care se poate obtine jucand pana la pozitia j si
    // eliminand i numere dintre acestea
    int64_t **bestDiff;
    int* v;

    // se citesc n si k si se aloca memoria
    in >> n >> k;
    bestDiff = new int64_t*[k + 1];
    v = new int[n];

    for (int i = 0; i <= k; ++i) {
        bestDiff[i] = new int64_t[n]();
    }

    // se citesc numerele ce constituie jocul
    for (int i = 0; i < n; ++i) {
        in >> v[i];
    }

    // asa cum am precizat la problema 1,
    sort(v, v + n, [](int v1, int v2) {
        return v1 > v2;
    });

    // la final, solutia corespunde eliminarii a k elemente dintre cele n ([0, n - 1]) numere din v
    out << findBestDiff(bestDiff, v, n, k) << '\n';

    // se elibereaza memoria
    for (int i = 0; i <= k; ++i) {
        delete[] bestDiff[i];
    }
    delete[] bestDiff;

    // se inchid fisierele
    in.close();
    out.close();

    return 0;
}