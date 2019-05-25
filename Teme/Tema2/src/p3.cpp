#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

#define NMAX 201
#define TMAX 101

struct Edge {
    int next, cost, type;

    Edge() {}

    Edge(int n, int c, int t): next(n), cost(c), type(t) {}
};

struct Node {
    int node, lastType;

    Node() {}

    Node(int n, int t): node(n), lastType(t) {}
};

int main() {
    ifstream fIn("p3.in");
    ofstream fOut("p3.out");

    Node crtNode;
    vector<Edge> adjList[NMAX];
    uint64_t costs[NMAX][TMAX], minCost = UINT64_MAX;
    int numNodes, numTypes, numEdges, x, n, c, t, p[TMAX][TMAX] = {0};
    queue<Node> q;

    fIn >> numNodes >> numEdges >> numTypes;

    memset(costs, 0xff, NMAX * TMAX * sizeof(uint64_t));

    // se citesc muchiile; `numEdges` nu mai este necesar in viitor, deci poate fi modificat
    while (numEdges--) {
        fIn >> x >> n >> c >> t;

        adjList[x].emplace_back(n, c, t);
        adjList[n].emplace_back(x, c, t);
    }

    // se citesc penalizarile dintre oricare 2 tipuri de muchii
    for (int i = 1; i <= numTypes; ++i) {
        for (int j = 1; j <= numTypes; ++j) {
            fIn >> p[i][j];
        }
    }

    // se considera ca nodul 1, din care se incepe algoritmul Bellman-Ford, are ca ultima muchie,
    // muchia 0
    costs[1][0] = 0;

    for (q.emplace(1, 0); !q.empty(); q.pop()) {
        crtNode = q.front();

        for (Edge& nextEdge : adjList[crtNode.node]) {
            // costul minim pana la un nod  se updateaza pentru fiecare tip de muchie de intrare
            // in acel nod, tinandu-se seama si de penalizarile aferente
            if (costs[nextEdge.next][nextEdge.type] > costs[crtNode.node][crtNode.lastType]
                                                      + nextEdge.cost
                                                      + p[crtNode.lastType][nextEdge.type]) {
                costs[nextEdge.next][nextEdge.type] = costs[crtNode.node][crtNode.lastType]
                                                      + nextEdge.cost
                                                      + p[crtNode.lastType][nextEdge.type];
                q.emplace(nextEdge.next, nextEdge.type);
            }
        }
    }

    // costul minim pana la nodul `N` s-ar putea obtine avand ca muchie finala a lantului
    // [1, ..., `N`] oricare dintre tipurile de muchii existente
    for (int i = 1; i <= numTypes; ++i) {
        minCost = minCost < costs[numNodes][i] ? minCost : costs[numNodes][i];
    }

    if (minCost == UINT64_MAX) {
        fOut << "-1\n";
    } else {
        fOut << minCost << '\n';
    }

    // se inchid fisierele
    fIn.close();
    fOut.close();

    return 0;
}