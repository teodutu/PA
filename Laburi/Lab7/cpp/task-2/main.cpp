#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

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

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
		}
		fin.close();
	}

	vector<int> get_result() {
		/*
		TODO: Faceti sortarea topologica a grafului stocat cu liste de
		adiacenta in adj.
		*******
		ATENTIE: nodurile sunt indexate de la 1 la n.
		*******
		*/
		vector<int> topsort;
		vector<int> inDegree(n + 1);
		queue<int> q;
		int crtNode;

		for (const auto& neighbours : adj) {
		    for (int node : neighbours) {
		        ++inDegree[node];
		    }
		}

		for (int i = 1; i <= n; ++i) {
		    if (!inDegree[i]) {
		        q.push(i);
		    }
		}

		while (!q.empty()) {
            crtNode = q.front();
            topsort.emplace_back(crtNode);
            q.pop();

            for (int nextNode : adj[crtNode]) {
                if (!--inDegree[nextNode]) {
                    q.push(nextNode);
                }
            }
		}

		return topsort;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 0; i < int(result.size()); i++) {
			fout << result[i] << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
