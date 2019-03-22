#include <cstdio>

#define MOD 1000000007

FILE *in, *out;


int lgput(int p) {
    int res = 1;
    int x = 2;

    while (p) {
        if (p & 1) {
            res = (1LL * res * x) % MOD;
        }

        x = (1LL * x * x) % MOD;
        p >>= 1;
    }

    return res;
}

int main() {
    int t, n, x;
    bool foundOdd;

    in = fopen("azerah.in", "r");
    out = fopen("azerah.out", "w");

    fscanf(in, "%d", &t);

    while (t--) {
        fscanf(in, "%d", &n);

        foundOdd = false;

        for (register int i = 0; i < n; ++i) {
            fscanf(in, "%d", &x);

            if (x & 1) {
                foundOdd = true;
            }
        }

        int res;

        if (foundOdd) {
            res = lgput(n - 1);
        } else {
            res = lgput(n);
        }

        fprintf(out, "%d\n", res - 1);
    }

    return 0;
}