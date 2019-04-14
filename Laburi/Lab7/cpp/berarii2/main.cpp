#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1000001

vector<int> adjList[MAXN];
bool marked[MAXN];

int main() {
    ifstream in("berarii2.in");
    ofstream out("berarii2.out");

    int numNodes, numEdges, numPubs, x, y;
    queue<int> q;
    vector<int> sol;

    in >> numNodes >> numEdges >> numPubs;

    while (numEdges--) {
        in >> x >> y;
        adjList[y].emplace_back(x);
    }

    while (numPubs--) {
        in >> x;
        q.emplace(x);
        marked[x] = true;
    }

    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (int nextNode : adjList[x]) {
            if (!marked[nextNode]) {
                marked[nextNode] = true;
                q.emplace(nextNode);
            }
        }
    }

    for (int i = 1; i <= numNodes; ++i) {
        if (!marked[i]) {
            sol.emplace_back(i);
        }
    }

    out << sol.size() << '\n';
    for (int node : sol) {
        out << node << '\n';
    }

    return 0;
}