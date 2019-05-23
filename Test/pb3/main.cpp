#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define NMAX 10001

vector<int> adjList[NMAX];
int goals[NMAX];
bool target[NMAX];
bool active[NMAX];
bool marked[NMAX][NMAX];

struct Player {
    int num, node;

    Player() {}
    Player(int n, int no): num(n), node(no) {}
};

int main() {
    int n, m, j, t, crtJ, numActive;
    queue<Player> q;
    vector<Player> p;
    Player crtP;

    scanf("%d %d %d %d", &n, &m, &j, &t);
    numActive = n;

    for (int i = 1; i <= j; ++i) {
        scanf("%d", &crtJ);
        p.emplace_back(i, crtJ);
//        q.emplace(i, crtJ);
        marked[crtJ][i] = true;
        active[i] = true;
    }

    sort(p.begin(), p.end(), [](Player& p1, Player& p2) {
        return p1.node < p2.node;
    });
    for (Player& crtPlayer : p) {
        q.emplace(crtPlayer);
    }

    for (int i = 0; i < t; ++i) {
        scanf("%d", &crtJ);
        target[crtJ] = true;
    }

    while (m--) {
        scanf("%d %d", &crtJ, &t);

        adjList[crtJ].emplace_back(t);
        adjList[t].emplace_back(crtJ);
    }

    for (int i = 1; i<= n; ++i) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    memset(goals, 0xff, sizeof(goals));

    for(; !q.empty() && numActive; q.pop()) {
        crtP = q.front();

        if (!active[crtP.num]) {
            continue;
        }

        if (target[crtP.node]) {
            goals[crtP.num] = crtP.node;
            active[crtP.num] = false;
            target[crtP.node] = false;
            --numActive;
            continue;
        }

        for (int nextNode : adjList[crtP.node]) {
            if (target[nextNode]) {
                goals[crtP.num] = nextNode;
                active[crtP.num] = false;
                target[nextNode] = false;
                --numActive;
                break;
            }

            if (!marked[nextNode][crtP.num]) {
                marked[nextNode][crtP.num] = true;
                q.emplace(crtP.num, nextNode);
            }
        }
    }

    for (int i = 1; i <= j; ++i) {
        printf("%d ", goals[i]);
    }

    printf("\n");

    return 0;
}