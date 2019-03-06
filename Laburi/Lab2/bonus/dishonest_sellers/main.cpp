#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 200000
#define BUFFMAX (1 << 22)

struct Item {
    int prev, next, diff;
} v[NMAX];

char buff[BUFFMAX];
int pos = BUFFMAX - 1;

void readInt(int &x) {
    while (buff[pos] < '0' || buff[pos] > '9') {
        if (++pos == BUFFMAX) {
            fread(buff, 1, BUFFMAX, stdin);
            pos = 0;
        }
    }

    while (buff[pos] >= '0' && buff[pos] <= '9') {
        x = x * 10 + buff[pos] - '0';
        if (++pos == BUFFMAX) {
            fread(buff, 1, BUFFMAX, stdin);
            pos = 0;
        }
    }
}

int main() {
    int i, n = 0, k = 0, sum = 0;

    readInt(n);
    readInt(k);

    for (i = 0; i < n; ++i) {
       readInt(v[i].prev);
    }
    for (i = 0; i < n; ++i) {
        readInt(v[i].next);
        v[i].diff = v[i].prev - v[i].next;
    }

    sort(v, v + n, [](Item& i1, Item& i2) { return i1.diff < i2.diff; });

    for (i = 0; i < n; ++i) {
        if (k <= 0 && v[i].diff > 0) {
            break;
        } else {
            sum += v[i].prev;
            --k;
        }
    }
    for (; i < n; ++i) {
        sum += v[i].next;
    }

    printf("%d\n", sum);

    return 0;
}