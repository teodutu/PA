#include <fstream>
#include <vector>
#include <stack>

using namespace std;

#define NMAX 100001

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/Laburi/Lab8/cpp/bonus/main.cpp

int height[NMAX], first[NMAX];
vector<int> adjList[NMAX];
vector<int>biconnectedComp;
vector<vector<int>> sol;
stack<int> s;

void DFS(int crtNode, int crtDad) {
    s.emplace(crtNode);
    height[crtNode] = first[crtNode] = height[crtDad] + 1;

    for (int nextNode : adjList[crtNode]) {
        if (!height[nextNode]) {
            DFS(nextNode, crtNode);
            first[crtNode] = min(first[crtNode], first[nextNode]);

            if (first[nextNode] >= height[crtNode]) {
                biconnectedComp.clear();
                int x;

                do {
                    x = s.top();
                    biconnectedComp.emplace_back(x);
                    s.pop();
                } while (nextNode != x);
                biconnectedComp.emplace_back(crtNode);

                sol.emplace_back(biconnectedComp);
            }
        } else if (nextNode != crtDad) {
            first[crtNode] = min(first[crtNode], height[nextNode]);
        }
    }
}

int main() {
    ifstream in("biconex.in");
    ofstream out("biconex.out");

    int numNodes, numEdges, x, y;

    in >> numNodes >> numEdges;

    while (numEdges--) {
        in >> x >> y;
        adjList[x].emplace_back(y);
        adjList[y].emplace_back(x);
    }

    DFS(1, 0);

    out << sol.size() << '\n';

    for (auto& comp : sol) {
        for (int crtNode : comp) {
            out << crtNode << ' ';
        }

        out << '\n';
    }

    return 0;
}