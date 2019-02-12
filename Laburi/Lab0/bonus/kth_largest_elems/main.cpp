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

void partition(int left, int right, int currK) {
    if (left >= right) {
        return;
    }

    pos = random() % (right - left + 1) + left;
    int pivot = v[pos], j = left;

    for (int i = left; i <= right; ++i) {
        if (v[i] >= pivot) {
            swap(v[i], v[j++]);
        }
    }

    if (currK <= j - left - 1) {
        partition(left, j - 1, currK);
    } else {
        partition(j, right, currK - j + left);
    }
}

int main() {
    pInFile = fopen("input.txt", "r");
    pOutFile = fopen("output.txt", "w");

    readInt(n);
    readInt(k);

    for (int i = 0; i < n; ++i) {
        readInt(v[i]);
    }

    srand(time(nullptr));
    partition(0, n - 1, k - 1);

    for (int i = 0; i < k; ++i) {
        fprintf(pOutFile, "%d ", v[i]);
    }

    fclose(pInFile);
    fclose(pOutFile);
    return 0;
}