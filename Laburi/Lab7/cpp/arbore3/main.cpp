#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAXN 1000001

unordered_map<int, int> pathSum;
vector<int> adjList[MAXN];
int values[MAXN];
int totalPaths, sum;


void DFS(int crtNode, int crtSum) {
    crtSum += values[crtNode];
    ++pathSum[crtSum];

    if (pathSum.find(crtSum - sum) != pathSum.end()) {
        totalPaths += pathSum[crtSum - sum];
    }

    for (int nextNode : adjList[crtNode]) {
        DFS(nextNode, crtSum);
    }

    if (!--pathSum[crtSum]) {
        pathSum.erase(crtSum);
    }
}

int main() {
    ifstream in("arbore3.in");
    ofstream out("arbore3.out");

    int n, x, y;

    in >> n >> sum;

    for (int i = 1; i <= n; ++i) {
       in >> x >> y;

        values[i] = y;
        adjList[x].emplace_back(i);
    }

    pathSum[0]++;

    DFS(1, 0);

    out << totalPaths << '\n';

    return 0;
}