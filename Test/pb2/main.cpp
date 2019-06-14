#include <cstdio>
#include <queue>

using namespace std;

#define n first
#define op second

#define NMAX 101
#define VALUES 20001
int l[NMAX];
bool marked[VALUES];

//struct Step {
//    int num;
//    int ops;
//
//    Step() {}
//    Step(int n, int o): num(n), ops(o) {}
//};

bool isValid(int num) {
    return num < VALUES/2 && num >= -VALUES/2 && !marked[num + VALUES/2]
}

int main() {
    int N, src, tgt, sol;
//    Step crtStep;
    queue<pair<int, int>> q;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &l[i]);
    }

    scanf("%d%d", &src, &tgt);
    if (tgt == src) {
        printf("0\n");
        return 0;
    }

    q.push({src, 0});
    while (!q.empty()) {
        auto& crtPair = q.front();
        q.pop();

        if (crtPair.n == tgt) {
            sol = crtPair.op;
            break;
        }

        for (int i = 1; i <= N; i++) {
            int sum = crtPair.n + l[i];

//            if (nextSrc == tgt) {
////                printf("%d\n", crtPair.ops + 1);
//
//            }

            if (isValid(sum)) {
                q.push({sum, crtPair.op + 1});
                marked[sum + VALUES / 2] = true;
            }

            int diff = crtPair.n - l[i];

//            if (nextNum == tgt) {
//                printf("%d\N", crtPair.ops + 1);
//                return 0;
//            }

            if (isValid(diff)) {
                q.push({diff, crtPair.op + 1});
                marked[diff + VALUES / 2] = true;
            }
        }
    }

    printf("%d\n", sol);

    return 0;
}