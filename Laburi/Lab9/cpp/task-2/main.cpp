#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

const int kNmax = 50005;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/tree/master/Laburi/Lab9/cpp/task-2

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

	vector<int> get_result() {
		/*
		TODO: Gasiti distantele minime de la nodul source la celelalte noduri
		folosind BellmanFord pe graful orientat cu n noduri, m arce stocat in adj.
			d[node] = costul minim / lungimea minima a unui drum de la source la nodul
		node;
			d[source] = 0;
			d[node] = -1, daca nu se poate ajunge de la source la node.

		Atentie:
		O muchie este tinuta ca o pereche (nod adiacent, cost muchie):
			adj[x][i].first = nodul adiacent lui x,
			adj[x][i].second = costul.

		In cazul in care exista ciclu de cost negativ, returnati un vector gol:
			return vector<int>();
		*/
		vector<int> d(n + 1, -1);
		vector<int> timesInQ(n + 1);
		queue<int> q;
		int crtNode;

		d[source] = 0;
		q.emplace(source);
		timesInQ[source] = 1;

        for (; !q.empty(); q.pop()) {
            crtNode = q.front();

		    for (const auto& nextNode : adj[crtNode]) {
                if (d[nextNode.first] == -1 || d[nextNode.first] > d[crtNode] + nextNode.second) {
                    d[nextNode.first] = d[crtNode] + nextNode.second;
                    q.emplace(nextNode.first);

                    if (++timesInQ[nextNode.first] > n) {
                        return vector<int>();
                    }
                }
		    }
		}

		return d;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		if (result.size() == 0) {
			fout << "Ciclu negativ!\n";
		} else {
			for (int i = 1; i <= n; i++) {
				fout << result[i] << ' ';
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
