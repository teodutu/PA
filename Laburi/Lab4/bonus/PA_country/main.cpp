#include <iostream>

#define MAX_N 205
#define MAX_P 305
#define MOD 666013

using namespace std;

int moves[MAX_N][MAX_N][MAX_P];
bool m[MAX_N][MAX_N];


int main() {
    int rows, cols, steps, startx, starty, endx, endy;

    cin >> rows >> cols >> steps >> startx >> starty >> endx >> endy;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            cin >> m[i][j];
        }
    }

    moves[startx][starty][0] = 1;

    for (int k = 1; k <= steps; ++k) {
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (!m[i][j]) {
                    moves[i][j][k] = (1LL * moves[i][j + 1][k - 1] +
                                      moves[i - 1][j][k - 1] +
                                      moves[i][j - 1][k - 1] +
                                      moves[i + 1][j][k - 1]) % MOD;
                }
            }
        }
    }

    int sum = 0;

    for (int i = 0; i <= steps; ++i) {
        sum = (1LL * moves[endx][endy][i] + sum) % MOD;
    }

    cout << sum << '\n';

    return 0;
}