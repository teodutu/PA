#include <cstdio>
#include <algorithm>

using namespace std;

#define NMAX 1000007

struct Sprinkler {
    int x, p;
} v[NMAX];

char name[130];

int main() {
    FILE *pInFile, *pOutFile;
    int n, l, wetPos = 0, numWorking = 0;

    pInFile = fopen("stropitori.in", "r");
    pOutFile = fopen("stropitori.out", "w");

    fgets(name, 130, pInFile);

    fscanf(pInFile, "%d %d", &n, &l);
    for (int i = 0; i < n; ++i) {
        fscanf(pInFile, "%d", &v[i].x);
    }
    for (int i = 0; i < n; ++i) {
        fscanf(pInFile, "%d", &v[i].p);

        if (v[i].x > wetPos && v[i].x - v[i].p > wetPos) {
            wetPos = v[i].x;
            ++numWorking;
        } else if (v[i].x > wetPos && v[i].x + v[i].p <= l) {
            wetPos = v[i].x + v[i].p;
            ++numWorking;
        }
    }

    fprintf(pOutFile, "%d\n", numWorking);

    fclose(pInFile);
    fclose(pOutFile);
    return 0;
}