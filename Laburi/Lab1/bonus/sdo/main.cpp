#include <cstdio>
#include <random>

#define NMAX (1 << 20)

using namespace std;

FILE *pInFile, *pOutFile;
int v[3000000], pos = NMAX - 1, n, k;
char buff[NMAX];

void readInt(int &x) {
    while (buff[pos] < '0' || buff[pos] > '9') {
        if (++pos == NMAX) {
            fread(buff, 1, NMAX, pInFile);
            pos = 0;
        }
    }

    while (buff[pos] >= '0' && buff[pos] <= '9') {
        x = x * 10 + buff[pos] - '0';
        if (++pos == NMAX) {
            fread(buff, 1, NMAX, pInFile);
            pos = 0;
        }
    }
}

void partition(int left, int right) {
    if (left >= right) {
        return;
    }

    pos = random() % (right - left + 1) + left;
    int pivot = v[pos], i, j;

    for (i = left, j = right; i <= j;) {
        for (; v[i] < pivot; ++i);
        for (; v[j] > pivot; --j);

        if (i <= j) {
            swap(v[i++], v[j--]);
        }
    }

    if (k <= j) {
        partition(left, j);
    } else {
        partition(j + 1, right);
    }
}

int main() {
    pInFile = fopen("sdo.in", "r");
    pOutFile = fopen("sdo.out", "w");

    readInt(n);
    readInt(k);
    --k;

    for (int i = 0; i < n; ++i) {
        readInt(v[i]);
    }

    srand(time(nullptr));
    partition(0, n - 1);
    fprintf(pOutFile, "%d\n", v[k]);

    fclose(pInFile);
    fclose(pOutFile);
    return 0;
}