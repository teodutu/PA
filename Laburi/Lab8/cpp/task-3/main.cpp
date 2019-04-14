#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/Laburi/Lab8/cpp/task-3/main.cpp

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> adj[kNmax];

	struct Edge {
		int x;
		int y;

		Edge(int _x, int _y): x(_x), y(_y) {}
	};

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fin.close();
	}

    void DFS(int crtNode, int& time, int crtDad, vector<int>& disc, vector<int>& firstAccessible,
             vector<Edge>& sol) {
        disc[crtNode] = firstAccessible[crtNode] = time++;

        for (int nextNode : adj[crtNode]) {
            if (!disc[nextNode]) {
                DFS(nextNode, time, crtNode, disc, firstAccessible, sol);
                firstAccessible[crtNode] = min(firstAccessible[nextNode], firstAccessible[crtNode]);

                if (firstAccessible[nextNode] > disc[crtNode]) {
                    sol.emplace_back(crtNode, nextNode);
                }
            } else if (nextNode != crtDad) {
                firstAccessible[crtNode] = min(disc[nextNode], firstAccessible[crtNode]);
            }
        }
    }

	vector<Edge> get_result() {
		/*
		TODO: Gasiti muchiile critice ale grafului neorientat stocat cu liste
		de adiacenta in adj.
		*/

		vector<Edge> sol;
        vector<int> disc(n + 1), firstAccessible(n + 1);
        int startTime = 1;

        for (int i = 1; i <= n; ++i) {
            if (!disc[i]) {
                DFS(i, startTime, 0, disc, firstAccessible, sol);
            }
        }

		return sol;
	}

	void print_output(vector<Edge> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < int(result.size()); i++) {
			fout << result[i].x << ' ' << result[i].y << '\n';
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
