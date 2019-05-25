#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// numarul maxim de noduri din graf = dimensiunea tuturor vectorilor si matricelor
#define NMAX 201

class Edge {
public:
    int next, type, cost;

    Edge() {}

    Edge(int n, int t, int c): next(n), type(t), cost(c) {}
};

__attribute__((always_inline)) void nextType(char* types, int t) {
    // functia simuleaza o adunare pe biti la nivel de octet pentru a crea pe rand, toate
    // submultimle multimii {1, 2, ...,T}
    types[1] += 1;

    for (int i = 1; i <= t; ++i) {
        types[i + 1] += types[i] / 2;
        types[i] %= 2;
    }
}

int main() {
    // se deschid fisierele
    ifstream fIn("p4.in");
    ofstream fOut("p4.out");

    char types[9] = {0};
    int numNodes, numEdges, numTypes, penalty[8], x, y, c, t;
    uint64_t minCost = UINT64_MAX, crtPenalty;
    uint64_t costs[NMAX];
    vector<Edge> adjList[NMAX];
    auto cmp = [&costs](int n1, int n2) {
        return costs[n1] > costs[n2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    // se citesc variabilele
    fIn >> numNodes >> numEdges >> numTypes;

    while (numEdges--) {
        fIn >> x >> y >> c >> t;

        adjList[x].emplace_back(y, t, c);
        adjList[y].emplace_back(x, t, c);
    }

    for (int i = 1; i <= numTypes; ++i) {
        fIn >> penalty[i];
    }

    for (int i = 1; i < (1 << numTypes); ++i) {
        memset(costs, 0xff, (numNodes + 1) * sizeof(uint64_t));

        // se generaza urmatoarea submultime a muchiilor grafului
        nextType(types, numTypes);

        crtPenalty = 0;
        costs[1] = 0;
        pq.emplace(1);

        // se ruleaza algoritmul lui Dijkstra pentru a determina costul minim de la 1 la toate
        // nodurile
        while (!pq.empty()) {
            x = pq.top();
            pq.pop();

            // se verifica si se updateaza costurile vecinilor nodului curent
            for (Edge& nextEdge : adjList[x]) {
                if (types[nextEdge.type] && costs[nextEdge.next] > nextEdge.cost + costs[x]) {
                    costs[nextEdge.next] = nextEdge.cost + costs[x];
                    pq.emplace(nextEdge.next);
                }
            }
        }

        // se calculeaza penalizarea aferenta submultimii curente de muchii
        for (int j = 1; j <= numTypes; ++j) {
            if (types[j]) {
                crtPenalty += penalty[j];
            }
        }

        // se updateaza costul minim doar daca exista un drum de la 1 la N
        if (costs[numNodes] != UINT64_MAX) {
            minCost = min(costs[numNodes] + crtPenalty, minCost);
        }
    }

    // se trateaza situatia in care nu exista drum intre 1 si N
    if (minCost == UINT64_MAX) {
        fOut << "-1\n";
    } else {
        fOut << minCost << '\n';
    }

    // se inchid fisierele de input si output
    fIn.close();
    fOut.close();

    return 0;
}