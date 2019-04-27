#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <tuple>
#include <queue>

using namespace std;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/tree/master/Laburi/Lab10/cpp/task-2/main.cpp

const int kNmax = 2e5 + 10;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<pair<int, int> > adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}
		fin.close();
	}

	int get_result() {
		auto cmp = [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
		};

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype (cmp)> pq(cmp);
        vector<int> visited(n + 1);
        pair<int, int> crtEdge;
        int cost = 0;

        visited[1] = true;
        for (auto& edge : adj[1]) {
            pq.emplace(edge);
        }

        while (!pq.empty()) {
            crtEdge = pq.top();
            pq.pop();

            if (!visited[crtEdge.first]) {
                cost += crtEdge.second;
                visited[crtEdge.first] = true;

                for (auto& nextEdge : adj[crtEdge.first]) {
                    if (!visited[nextEdge.first]) {
                        pq.emplace(nextEdge.first, nextEdge.second);
                    }
                }
            }
        }

		return cost;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << "\n";
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
