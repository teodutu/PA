#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
using namespace std;

const int kNmax = 50005;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/tree/master/Laburi/Lab9/cpp/bonus

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n;
    int m;
    int source;
    vector<pair<int, int> > adj[kNmax];

    void read_input() {
        ifstream fin("in");
        fin >> n >> m >> source;
        for (int i = 1, x, y, w; i <= m; i++) {
            fin >> x >> y >> w;
            adj[x].push_back(make_pair(y, w));
        }
        fin.close();
    }

    vector<vector<int>> get_result() {
        /*
        TODO: Gasiti distantele minime de la nodul source la celelalte noduri
        folosind Dijkstra pe graful orientat cu n noduri, m arce stocat in adj.
            d[node] = costul minim / lungimea minima a unui drum de la source la nodul
        node;
            d[source] = 0;
            d[node] = -1, daca nu se poate ajunge de la source la node.

        Atentie:
        O muchie este tinuta ca o pereche (nod adiacent, cost muchie):
            adj[x][i].first = nodul adiacent lui x,
            adj[x][i].second = costul.
        */

        int crtNode;
        vector<int> d(n + 1, -1);
        auto cmp = [&d](int x, int y) {
            return d[x] > d[y];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        d[source] = 0;
        pq.emplace(source);

        for (; !pq.empty(); pq.pop()) {
            crtNode = pq.top();

            for (const auto& nextEdge : adj[crtNode]) {
                if (d[nextEdge.first] == -1 || d[nextEdge.first] > nextEdge.second + d[crtNode]) {
                    d[nextEdge.first] = nextEdge.second + d[crtNode];
                    pq.emplace(nextEdge.first);
                }
            }
        }

        queue<int> q;
        vector<bool> marked(n + 1);
        vector<vector<int>> paths(n + 1);

        q.emplace(source);
        paths[source].emplace_back(source);

        for (; !q.empty(); q.pop()) {
            crtNode = q.front();

            for (const auto& nextEdge : adj[crtNode]) {
                if (d[nextEdge.first] == d[crtNode] + nextEdge.second) {
                    paths[nextEdge.first] = paths[crtNode];
                    paths[nextEdge.first].emplace_back(nextEdge.first);
                    q.emplace(nextEdge.first);
                }
            }
        }

        return paths;
    }

    void print_output(vector<vector<int>> result) {
        ofstream fout("out");
        for (int i = 1; i <= n; i++) {
            fout << i << ": ";

            for (int node : result[i]) {
                fout << node << ' ';
            }

            fout << '\n';
        }
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
