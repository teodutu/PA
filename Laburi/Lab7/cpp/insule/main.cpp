#include <fstream>
#include <queue>

using namespace std;

#define MAXN 102

struct Pos {
    char l, c;
};

char map[MAXN][MAXN];
bool mark[MAXN][MAXN];
short dist[MAXN][MAXN];
const char dl[] = {0, -1, 0, 1};
const char dc[] = {1, 0, -1, 0};
int rows, cols;
queue<Pos> q;

void bordMatrix() {
    for (int i = 0; i <= rows + 1; ++i) {
        map[i][0] = map[i][cols + 1] = -1;
    }

    for (int i = 0; i <= cols + 1; ++i) {
        map[0][i] = map[rows + 1][i] = -1;
    }
}

int fill(const Pos& crtPos, char type) {
    if (map[crtPos.l][crtPos.c] == '0' && !dist[crtPos.l][crtPos.c] && type == '1') {
        dist[crtPos.l][crtPos.c] = 1;
        q.emplace(crtPos);

        return 0;
    }

    if (map[crtPos.l][crtPos.c] != type || mark[crtPos.l][crtPos.c]) {
        return 0;
    }

    int size = 0;
    Pos nextPos;

    mark[crtPos.l][crtPos.c] = true;

    for (int i = 0; i < 4; ++i) {
        nextPos.l = crtPos.l + dl[i];
        nextPos.c = crtPos.c + dc[i];

        size += fill(nextPos, type);
    }

    return size + 1;
}

int main() {
    ifstream in("insule.in");
    ofstream out("insule.out");

    int numR = 0, numG = 0, numB = 0, len = 0;
    bool foundBridge = false;
    Pos crtPos, nextPos;

    in >> rows >> cols;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            in >> map[i][j];
        }
    }

    bordMatrix();

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            crtPos.l = i;
            crtPos.c = j;

            if (!mark[i][j]) {
                switch (map[i][j]) {
                    case '1':
                        ++numR;
                        fill(crtPos, '1');
                        break;
                    case '2':
                        ++numG;
                        fill(crtPos, '2');
                        break;
                    case '3':
                        ++numB;
                        fill(crtPos, '3');
                        break;
                }
            }
        }
    }

    while (!q.empty() && !foundBridge) {
        crtPos = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            nextPos.l = crtPos.l + dl[i];
            nextPos.c = crtPos.c + dc[i];

            if (map[nextPos.l][nextPos.c] == '2') {
                len = dist[crtPos.l][crtPos.c];
                foundBridge = true;
                break;
            }

            if (map[nextPos.l][nextPos.c] == '0' && !dist[nextPos.l][nextPos.c]) {
                dist[nextPos.l][nextPos.c] = dist[crtPos.l][crtPos.c] + 1;
                q.emplace(nextPos);
            }
        }
    }

    out << numR << ' ' << numG << ' ' << numB << ' ' << len;

    return 0;
}