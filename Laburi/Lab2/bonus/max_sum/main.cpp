#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NMAX 100000

int n, k, v[NMAX];

int main() {
    int i, sum = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v, v + n);

    for (i = 0; i < n && k; ++i) {
        if (v[i] < 0) {
            v[i] = -v[i];
            --k;
        } else {
            break;
        }
    }

    sort(v, v + n);

    if (k & 1) {
        v[0] = -v[0];
    }

    for (i = 0; i < n; ++i) {
        sum += v[i];
    }

    printf("%d\n", sum);

    return 0;
}