#include <fstream>
#include <algorithm>

using namespace std;

int64_t getMaxBestDiff(int64_t** bestDiff, int* v, int n) {
    // daca se joaca doar pozitia i, exista doar un element, care va fi luat de jucatorul 1
    for (int i = 0; i < n; ++i) {
        bestDiff[i][i] = v[i];
    }

    // se vor completa pe rand supradiagonalele matricei bestDiff astfel incat sa se poata folosi
    // jocurile [i + 1, j] si [i, j - 1] pentru rezultatul jocului [i, j]
    for (int offset = 1; offset < n; ++offset) {
        for (int i = 0; i < n - offset; ++i) {
            bestDiff[i][i + offset] = max(v[i] - bestDiff[i + 1][i + offset],
                                        v[i + offset] - bestDiff[i][i + offset - 1]);
        }
    }

    // rezultatul este cel ce reprezinta jocul [0, n - 1]
    return bestDiff[0][n - 1];
}

int main() {
    ifstream in("p3.in");
    ofstream out("p3.out");

    int n;
    int* v;

    // bestDiff[i][j] = cea mai buna diferenta obtinuta daca jocul s-ar defasura doar intre
    // pozitiile i j
    int64_t** bestDiff;

    in >> n;

    // se aloca memoria necesara
    v = new int[n];
    bestDiff = new int64_t*[n];

    for (int i = 0; i < n; ++i) {
        bestDiff[i] = new int64_t[n];
    }

    // se citesc numerele
    for (int i = 0; i < n; ++i) {
        in >> v[i];
    }

    out << getMaxBestDiff(bestDiff, v, n) << '\n';

    // se dealoca memoria
    for (int i = 0; i < n; ++i) {
        delete[] bestDiff[i];
    }

    delete[] v;
    delete[] bestDiff;

    // se inchid fisierele
    in.close();
    out.close();

    return 0;
}
