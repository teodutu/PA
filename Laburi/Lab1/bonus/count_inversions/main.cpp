#include <fstream>
#define NMAX 100000
#define MOD 9917

using namespace std;

int n, v[NMAX], aux[NMAX];

int countInv(int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = (left + right) / 2;
    int currCount = (countInv(left, mid) + countInv(mid + 1, right)) % MOD;
    int i, j, k;

    for (k = left, i = left, j = mid + 1; i <= mid && j <= right; ++k) {
        if (v[i] > v[j]) {
            currCount = (currCount + mid - i + 1) % MOD;
            aux[k] = v[j++];
        } else {
            aux[k] = v[i++];
        }
    }

    for (; i <= mid; ++i, ++k) {
        aux[k] = v[i];
    }
    for (; j <= right; ++j, ++k) {
        aux[k] = v[j];
    }

    for (i = left; i <  k; ++i) {
        v[i] = aux[i];
    }

    return currCount;
}

int main() {
    ifstream fIn("inv.in");
    ofstream fOut("inv.out");

    fIn >> n;
    for (int i = 0; i < n; ++i) {
        fIn >> v[i];
    }

    fOut << countInv(0, n - 1);

    fIn.close();
    fOut.close();
    return 0;
}