#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
using namespace std;

// in caz de lab copiat, verificati sursa:
// https://github.com/teodutu/PA/tree/master/Laburi/Lab10/cpp/task-1/main.cpp

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<tuple<int, int, int> > edges;
	vector<int> parent, size;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			edges.push_back(make_tuple(w, x, y));
		}
		parent.resize(n + 1);
		size.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
		fin.close();
	}

	int find_root(int node) {
		if (node == parent[node]) {
			return node;
		}
		return parent[node] = find_root(parent[node]);
	}

	void merge_forests(int root1, int root2) {
		if (size[root1] <= size[root2]) {
			size[root2] += size[root1];
			parent[root1] = root2;
		} else {
			size[root1] += size[root2];
			parent[root2] = root1;
		}
	}

	int get_result() {
		int x, y, c, cost = 0;

        sort(edges.begin(), edges.end(), [](tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
            return get<0>(t1) < get<0>(t2);
        });

        for (tuple<int, int, int>& crtEdge : edges) {
            tie(c, x, y) = crtEdge;

            if (find_root(x) != find_root(y)) {
                cost += c;
                merge_forests(find_root(x), find_root(y));
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
