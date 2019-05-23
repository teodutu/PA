#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define NMAX 10001
int v[NMAX];

int main() {
    int n, k, pos1, pos2, maxPos1, maxPos2, minDiff = INT_MAX;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v + 1, v + n + 1);

    pos1 = 1; pos2 = k;

    while (pos2 <= n) {
        if (v[pos2] - v[pos1] < minDiff) {
            minDiff = v[pos2] - v[pos1];
            maxPos1 = pos1;
            maxPos2 = pos2;
        }

        ++pos1;
        ++pos2;
    }

    printf("%d\n", v[maxPos2] - v[maxPos1]);
    for (int i = maxPos1; i <= maxPos2; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}