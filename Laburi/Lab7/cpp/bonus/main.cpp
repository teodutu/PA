#include <fstream>
#include <queue>

using namespace std;

struct Pos {
    short l, c;
};

__attribute__((always_inline)) bool validPos(int n, const Pos& pos) {
    return pos.l >= 0 && pos.c >= 0 && pos.l < n && pos.c < n;
}

int main() {
    ifstream in("bonus.in");
    ofstream out("bonus.out");

    int n;
    short **map;
    int** dist;
    Pos crtPos, nextPos;
    queue<Pos> q;
    bool foundTarget = false;

    int dl[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    in >> n >> crtPos.l >> crtPos.c;

    map = new short*[n];
    dist = new int*[n];

    for (int i = 0; i < n; ++i) {
        map[i] = new short[n];
        dist[i] = new int[n]();
    }

    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> map[i][j];
        }
    }

    q.push(crtPos);

    while (!q.empty() && !foundTarget) {
        crtPos = q.front();
        q.pop();

        map[crtPos.l][crtPos.c] = 1;

        for (int i = 0; i < 4; ++i) {
            nextPos.l = crtPos.l + dl[i];
            nextPos.c = crtPos.c + dc[i];

            if (validPos(n, nextPos) && map[nextPos.l][nextPos.c] != 1) {
                dist[nextPos.l][nextPos.c] = dist[crtPos.l][crtPos.c] + 1;

                if (map[nextPos.l][nextPos.c] == 2) {
                    foundTarget = true;
                    break;
                }

                map[nextPos.l][nextPos.c] = 1;
                q.emplace(nextPos);
            }
        }
    }

    out << dist[nextPos.l][nextPos.c] << '\n';

    for (int i = 0; i < n; ++i) {
        delete[] map[i];
    }
    delete[] map;

    return 0;
}