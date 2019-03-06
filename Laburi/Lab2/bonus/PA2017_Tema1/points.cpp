#include <cstdio>
#include <algorithm>

#define NMAX 1000000

using namespace std;

struct Interval {
    int left, right;
} interv[NMAX];

FILE *pInFile, *pOutFile;
int coords[NMAX];

int main() {
    int n, m, currInt = 0, numInt = 1, lastInt = 0;

    pInFile = fopen("points.in", "r");
    pOutFile = fopen("points.out", "w");

    fscanf(pInFile, "%d %d", &n, &m);

    for (int i = 0 ; i < n; ++i) {
        fscanf(pInFile, "%d", &coords[i]);
    }
    for (int i = 0; i < m; ++i) {
        fscanf(pInFile, "%d %d", &interv[i].left, &interv[i].right);
    }

    sort(interv, interv + m, [](Interval& i1, Interval& i2) {
        return i1.left < i2.left;
    });

    for (; currInt < m && interv[currInt].right < coords[0]; ++currInt);
    for (int i = currInt + 1; i < m && interv[i].left <= coords[0]; ++i) {
        if (interv[i].right > interv[currInt].right) {
            currInt = i;
        }
    }

    lastInt = currInt;

    for (int i = 1; i < n; ++i) {
        if (interv[currInt].right < coords[i]) {
            for (; currInt < m && interv[currInt].right < coords[i]; ++currInt);
            for (int j = currInt + 1; j < m && interv[j].left <= coords[i]; ++j) {
                if (interv[j].right > interv[currInt].right) {
                    currInt = j;
                }
            }
        }


        if (lastInt != currInt) {
            lastInt = currInt;
            ++numInt;
        }
    }

    if (!numInt) {
        numInt = 1;
    }

    fprintf(pOutFile, "%d\n", numInt);

    fclose(pInFile);
    fclose(pOutFile);
    return 0;
}